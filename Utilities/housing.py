"""
新加坡私人公寓「合理尺价」估值脚手架。

设计说明（比单纯 base×age + Σpremium 更全面的地方）：
- 把时间维度拆开：交房/楼龄成色 (TOP factor) ≠ 市场情绪周期 (macro factor)。
- 把「区位/产品」溢价按类别拆开，便于回顾与压力测试。
- 面积对 PSF 的非线性（小面积大 PSF）：用可选的对数微调项。
- 把期房交割/政策风险单列，避免混在笼统 age factor 里。
- 产出区间（情景带），提醒自己这是区间判断而不是点估计。

校准提醒：下文系数（λ、阈值）都是「可改的假设」，应用应用层comps 或回归结果替换。
"""

from __future__ import annotations

from dataclasses import dataclass
from math import log
from typing import Any, Dict, Mapping, Tuple


# ---------------------------------------------------------------------------
# Comprehensive model inputs
# ---------------------------------------------------------------------------


def _nested_sum(premiums_by_category: Mapping[str, Mapping[str, float]]) -> float:
    return sum(sum(sub.values()) for sub in premiums_by_category.values())


def _size_psf_adjustment_psf(size_sqft: float, benchmark_sqft: float, elasticity: float) -> float:
    """
    Larger units tend to trade at lower PSF; smaller units vice versa.

    elasticity 控制强度；设为 0 关闭此项（与旧模型一致）。
    """
    if elasticity == 0.0 or benchmark_sqft <= 0 or size_sqft <= 0:
        return 0.0
    return -elasticity * log(size_sqft / benchmark_sqft)


def _remaining_lease_psf_drag_psf(years_remaining: float | None, is_freehold: bool, per_year_drag: float) -> float:
    """
    Illustrative downward drag versus a fresh ~99LH lease baseline.

    若 comps 已经把租期折进价里了，可把 per_year_drag 设为 0 并用外部 manual 覆盖。
    """
    if is_freehold or years_remaining is None or per_year_drag == 0.0:
        return 0.0
    erosion = max(0.0, 99.0 - years_remaining)
    return -per_year_drag * erosion


@dataclass(frozen=True)
class ComprehensiveValuationConfig:
    """可在项目级统一的「标尺」，避免每笔交易重复传一堆默认。"""

    market_cycle_factor: float = 1.0  # >1 : 市场整体更景气；<1 : 逆风
    benchmark_sqft: float = 920.0  # 「典型三房」用作面积曲线锚点
    size_psf_elasticity: float = 60.0  # 设为 0 关闭面积 PSF 非线性（旧行为）
    buc_discount_psf: float = 0.0  # 期房/施工风险折价（可为负数以表示折价）
    remaining_lease_years: float | None = None
    freehold_like: bool = False
    lease_drag_per_remaining_year_below_99: float = 0.0  # >0 时启用简易租期拖累
    low_high_pct: float = 0.08  # 情景带宽（对称 ±）


def _print_section(title: str) -> None:
    print(f"{title}")
    print("-----------------------------------------")


def evaluate_condo_fair_psf_comprehensive(
    project_name: str,
    base_psf: float,
    size_sqft: float,
    *,
    top_adjustment_factor: float,
    premiums_by_category: Mapping[str, Mapping[str, float]],
    config: ComprehensiveValuationConfig | None = None,
) -> Tuple[float, float, Dict[str, Any]]:
    """
    Comprehensive fair PSF (hedonic scaffolding) + naive scenario band.

    Returns:
      fair_psf, fair_total_price, breakdown(dict)
    """
    cfg = config or ComprehensiveValuationConfig()

    macro_adj_base = base_psf * cfg.market_cycle_factor
    vintaged_base_psf = macro_adj_base * top_adjustment_factor

    size_adj = _size_psf_adjustment_psf(size_sqft, cfg.benchmark_sqft, cfg.size_psf_elasticity)
    lease_drag = _remaining_lease_psf_drag_psf(
        cfg.remaining_lease_years, cfg.freehold_like, cfg.lease_drag_per_remaining_year_below_99
    )

    hedonic_total = _nested_sum(premiums_by_category)

    incremental_psf = hedonic_total + size_adj + cfg.buc_discount_psf + lease_drag
    fair_psf = vintaged_base_psf + incremental_psf
    fair_total = fair_psf * size_sqft

    band_pct = cfg.low_high_pct
    fair_low = fair_psf * (1.0 - band_pct)
    fair_high = fair_psf * (1.0 + band_pct)

    breakdown = {
        "macro_adj_base_psf": macro_adj_base,
        "top_adjustment_factor": top_adjustment_factor,
        "vintaged_base_psf": vintaged_base_psf,
        "hedonic_psf_total": hedonic_total,
        "premiums_by_category": {k: dict(v.items()) for k, v in premiums_by_category.items()},
        "size_psf_adjustment": size_adj,
        "buc_discount_psf": cfg.buc_discount_psf,
        "lease_residual_drag_psf": lease_drag,
        "incremental_psf": incremental_psf,
        "fair_psf_point": fair_psf,
        "fair_total_price": fair_total,
        "scenario_band_pct": band_pct,
        "fair_psf_low": fair_low,
        "fair_psf_high": fair_high,
    }

    print("=========================================")
    print(f"📊 Comprehensive fair-PSF model: {project_name}")
    print("=========================================")
    print(f" Base PSF (island scaffold)           : ${base_psf:,.2f}")
    print(f" Market-cycle factor ×                : ×{cfg.market_cycle_factor:g}")
    print(f" Cyclically adjusted base             : ${macro_adj_base:,.2f}")
    print(f" TOP / completion quality factor ×    : ×{top_adjustment_factor:g}")
    print(f" Vintaged scaffold base               : ${vintaged_base_psf:,.2f}")

    print()
    print("🔎 Hedonic increments (additive PSF buckets)")
    category_subtotals: Dict[str, float] = {}
    for cat, items in premiums_by_category.items():
        cat_sum = sum(items.values())
        category_subtotals[cat] = cat_sum
        print(f"\n[{cat}] (subtotal ${cat_sum:+,.2f})")
        for label, amt in items.items():
            pad = label.ljust(28)
            print(f"    - {pad} : ${amt:+,.2f}")
    hedonic_footer = sum(category_subtotals.values())
    print(f"\nHedonic subtotal                       : ${hedonic_footer:+,.2f}")

    print("\nStructural add-ons")
    print(f"  Size PSF curve (Δ)                   : ${size_adj:+,.2f}")
    print(f"  BUC / execution risk PSF           : ${cfg.buc_discount_psf:+,.2f}")
    print(f"  Illustrative residual-lease PSF drag : ${lease_drag:+,.2f}")

    print()
    print("🎯 Consolidated valuation")
    print(f" Incremental hedonic PSF              : ${incremental_psf:+,.2f}")
    print(f" Fair PSF (point estimate)           : ${fair_psf:,.2f}")
    band_label = band_pct * 100
    print(
        " Fair PSF band (±{:.1f}% naïve)          : "
        "${:,.2f} – ${:,.2f}".format(band_label, fair_low, fair_high)
    )
    print(f" Unit size                             : {size_sqft:,.0f} sqft")
    print(f" Fair total (point)                    : ${fair_total:,.2f}")

    totals_low = fair_low * size_sqft
    totals_high = fair_high * size_sqft
    print(
        " Total band (scaled)                   : "
        "${:,.2f} – ${:,.2f}".format(totals_low, totals_high)
    )
    print("=========================================\n")

    breakdown["category_subtotals"] = category_subtotals

    return fair_psf, fair_total, breakdown


def calculate_fair_psf(project_name, base_psf, age_factor, premiums, size_sqft):
    """
    原版线性模型（保持口径不变，便于对齐历史笔记）：

      fair_psf = base_psf * age_factor + sum(premiums)

    For a structured version,调用 `evaluate_condo_fair_psf_comprehensive`.
    """

    adjusted_base = base_psf * age_factor
    total_premium = sum(premiums.values())
    fair_psf = adjusted_base + total_premium
    fair_total_price = fair_psf * size_sqft

    print("=========================================")
    print(f"📊 新加坡房产特征定价报告: {project_name}")
    print("=========================================")
    print(f" 基础刚性底价 (Base PSF)        : ${base_psf:,.2f}")
    print(f" 年份折旧/溢价系数 (Age Factor) : {age_factor}")
    print(f" 调整后底价 (Adjusted Base)     : ${adjusted_base:,.2f}")
    print("-----------------------------------------")
    print(" 🔍 特征溢价明细 (Premiums):")
    mw = max((len(str(k)) for k in premiums), default=0)
    mw = max(mw, 20)
    for key, val in premiums.items():
        print(f"   - {key.ljust(mw)} : ${val:+,.2f}")
    print(f" 溢价总计 (Total Premium)       : ${total_premium:+,.2f}")
    print("-----------------------------------------")
    print(" 🎯 估值结果:")
    print(f"   👉 估算合理尺价 (Fair PSF)   : ${fair_psf:,.2f} / sqft")
    print(f"   👉 对应单位面积 (Size)       : {size_sqft:,.0f} sqft")
    print(f"   👉 估算合理总价 (Total)      : ${fair_total_price:,.2f}")
    print("=========================================\n")

    return fair_psf, fair_total_price


# =====================================================================
# 实战运行：原版 vs 更全面模型并排对照
# =====================================================================
if __name__ == "__main__":
    BASE_PSF_2026 = 1900.0

    amo_premiums_flat = {
        "Tenure (99-yr)": 0,
        "Neighborhood (D20)": 200,
        "School": 200,
        "MRT Access": 100,
        "Amenities": 0,
        "View": 50,
        "Developer": 50,
        "Scale": 50,
    }

    amo_premiums_nested = {
        "Location": {"District D20 uplift": 200, "Connectivity (10–12 mins MRT bands)": 100},
        "Education / scarcity narrative": {"Primary school halo": 200},
        "Project / developer": {"Branding scale": 50, "Facility stack": 0},
        "Unit story": {"Unblocked view bands": 50},
    }

    calculate_fair_psf(
        project_name="AMO Residence (legacy linear stack)",
        base_psf=BASE_PSF_2026,
        age_factor=1.10,
        premiums=amo_premiums_flat,
        size_sqft=958,
    )

    cfg_amo = ComprehensiveValuationConfig(
        market_cycle_factor=1.0,
        size_psf_elasticity=60.0,
        buc_discount_psf=0.0,
        remaining_lease_years=None,
        freehold_like=False,
        lease_drag_per_remaining_year_below_99=0.0,
    )

    evaluate_condo_fair_psf_comprehensive(
        project_name="AMO Residence — comprehensive scaffolding",
        base_psf=BASE_PSF_2026,
        size_sqft=958,
        top_adjustment_factor=1.10,
        premiums_by_category=amo_premiums_nested,
        config=cfg_amo,
    )

    tembusu_premiums_flat = {
        "Tenure (99-yr)": 0,
        "Neighborhood": 350,
        "School": 100,
        "MRT Access": 100,
        "Amenities": 50,
        "View": 50,
        "Developer": 50,
        "Scale": 50,
        "Supply Penalty": -100,
    }

    tembusu_premiums_nested = {
        "Location": {"East corridor core district premium": 350, "Connectivity (MRT-ish access)": 100},
        "Education narrative": {"Neighbourhood schooling optionality": 100},
        "Project / ops": {"Amenity depth": 50, "Brand / strata scale": 100},
        "Unit story": {"Stacking premiums / view": 50},
        "Competition overlay": {"Incoming supply / bidding-for-margin penalty": -100},
    }

    calculate_fair_psf(
        project_name="Tembusu Grand (legacy linear stack)",
        base_psf=BASE_PSF_2026,
        age_factor=1.00,
        premiums=tembusu_premiums_flat,
        size_sqft=990,
    )

    cfg_buc_example = ComprehensiveValuationConfig(
        market_cycle_factor=0.96,  # 假设销售端略逆风，可自行改 1.0 / 1.05
        size_psf_elasticity=60.0,
        buc_discount_psf=-40.0,
        remaining_lease_years=99,
        lease_drag_per_remaining_year_below_99=0.0,
    )

    evaluate_condo_fair_psf_comprehensive(
        project_name="Tembusu Grand — BUC-informed comprehensive stack",
        base_psf=BASE_PSF_2026,
        size_sqft=990,
        top_adjustment_factor=1.03,  # 把「次新溢价」从产品里拆出一些给完工风险
        premiums_by_category=tembusu_premiums_nested,
        config=cfg_buc_example,
    )
