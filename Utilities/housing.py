from __future__ import annotations

import argparse
from dataclasses import dataclass
import matplotlib.pyplot as plt

ADJUSTMENT_LABELS: dict[str, str] = {
    "mrt_location": "MRT location",
    "immediate_top": "Immediate top",
    "cdl_branding_view": "CDL branding / view",
    "lease_age_decay": "Lease-age decay",
    "year_to_year_price_increase": "YoY price drift",
    "sea_view": "Sea view",
}


# Post-harmo EOK PSF by stack floor (Tower 51 excerpt — extend as lists update).
POST_HARMO_EOK_PSF_BY_FLOOR: dict[int, int] = {
    20: 2687,
    17: 2651,
    9: 2543,
    8: 2531,
    7: 2507,
    5: 2483,
    4: 2471,
}


@dataclass
class Ans:
    """Published valuation snapshot (programmatic + console)."""

    net_adjustment_applied: str
    adjustment_breakdown: dict[str, float]
    fair_market_psf: float
    fair_market_value: float
    negotiation_floor: float
    negotiation_ceiling: float


@dataclass(frozen=True)
class FMVModelState:
    """Intermediate values shared by reporting and plotting."""

    tier_floor: int
    tg_book_size: float
    h_deflator: float
    # psf_post: EOK PSF you quote as post-harmo (caller input — list / floor guide).
    psf_eok_post_harmo: float
    # Harmonization step: psf_pre = psf_post × deflator (< post).
    psf_eok_pre_harmo: float
    # %-adjustments stack off pre-harmo PSF (same as ×0.95 step on post).
    p_base: float
    adjustments: dict[str, float]
    sum_delta: float
    p_tg_fair: float
    fmv_tg: float
    negotiation_floor: float
    negotiation_ceiling: float


def adjustment_breakdown_for_print(state: FMVModelState) -> dict[str, float]:
    """Display label → Δ as percentage points (vs PSF anchor after harmonization ×0.95)."""
    return {
        ADJUSTMENT_LABELS.get(k, k.replace("_", " ")): float(v)
        for k, v in state.adjustments.items()
    }


def calculate_perfect_condo_fmv(floor: int, tg_book_size: float = 990) -> tuple[Ans, FMVModelState]:
    """Run full FMV path; nested ``run_fmv_model`` exists only inside this routine."""

    def run_fmv_model() -> FMVModelState:
        try:
            psf_post = float(POST_HARMO_EOK_PSF_BY_FLOOR[floor])
        except KeyError as e:
            known = ", ".join(str(k) for k in sorted(POST_HARMO_EOK_PSF_BY_FLOOR))
            raise KeyError(f"No post-harmo EOK PSF for floor {floor}. Known stacks: [{known}]") from e

        return _compute_fmv_state(psf_post, tg_book_size, floor)

    s = run_fmv_model()
    return (
        Ans(
            net_adjustment_applied=f"{round(s.sum_delta, 1)}%",
            adjustment_breakdown=adjustment_breakdown_for_print(s),
            fair_market_psf=round(s.p_tg_fair, 2),
            fair_market_value=round(s.fmv_tg, 2),
            negotiation_floor=s.negotiation_floor,
            negotiation_ceiling=s.negotiation_ceiling,
        ),
        s,
    )


def _compute_fmv_state(psf_post: float, tg_book_size: float, tier_floor: int) -> FMVModelState:
    h_deflator = 0.95
    psf_pre = psf_post * h_deflator
    p_base = psf_pre
    adjustments = {
        "mrt_location": -3,
        "immediate_top": 6,
        "cdl_branding_view": 3,
        # "lease_age_decay": -1 * 1.5,
        "year_to_year_price_increase": 4.5,
        # "sea_view": 3,
    }
    sum_delta = sum(adjustments.values())
    p_tg_fair = p_base * (1 + sum_delta / 100.0)
    fmv_tg = p_tg_fair * tg_book_size
    lower_bound = round(fmv_tg * 0.985, -3)
    upper_bound = round(fmv_tg * 1.015, -3)
    return FMVModelState(
        tier_floor=tier_floor,
        tg_book_size=tg_book_size,
        h_deflator=h_deflator,
        psf_eok_post_harmo=psf_post,
        psf_eok_pre_harmo=psf_pre,
        p_base=p_base,
        adjustments=adjustments,
        sum_delta=sum_delta,
        p_tg_fair=p_tg_fair,
        fmv_tg=fmv_tg,
        negotiation_floor=lower_bound,
        negotiation_ceiling=upper_bound,
    )


def plot_fmv_model(state: FMVModelState, *, save_path: str | None = None) -> None:

    keys = list(state.adjustments.keys())
    labels = [ADJUSTMENT_LABELS.get(k, k) for k in keys]
    deltas = [state.adjustments[k] for k in keys]
    colors = ["#2e7d32" if d >= 0 else "#c62828" for d in deltas]

    fig, axes = plt.subplots(1, 2, figsize=(14.5, 4.8))

    axes[0].barh(labels, deltas, color=colors)
    axes[0].axvline(0, color="#424242", linewidth=0.8)
    axes[0].set_xlabel("Δ vs base (percentage points)")
    axes[0].set_title(f"Adjustment stack (net {state.sum_delta:g}%)")

    psf_steps = ["EOK\n(post-harmo)", "EOK\n(pre-harmo)", "TG\n(FMV)"]
    psf_vals = [state.psf_eok_post_harmo, state.psf_eok_pre_harmo, state.p_tg_fair]
    axes[1].bar(psf_steps, psf_vals, color=["#546e7a", "#0277bd", "#1565c0"])
    axes[1].set_ylabel("$ / sqft")
    axes[1].set_title(f"PSF cascade · Tier floor {state.tier_floor}")

    fig.suptitle(
        f"Tembusu FMV ({state.tg_book_size:,.0f} sqft · pre = post × {state.h_deflator})",
        fontsize=12,
    )
    fig.tight_layout()
    if save_path:
        fig.savefig(save_path, dpi=150, bbox_inches="tight")
        plt.close(fig)
    else:
        plt.show()


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Condo FMV calculator and matplotlib charts.")
    parser.add_argument(
        "--floor",
        type=int,
        default=9,
        help="Stack floor to look up POST_HARMO_EOK_PSF_BY_FLOOR",
    )
    parser.add_argument(
        "--save",
        metavar="PATH",
        help="Write figure to PATH (PNG/SVG/PDF per extension) instead of only showing",
    )
    args = parser.parse_args()

    res_owner, state = calculate_perfect_condo_fmv(args.floor)

    print("=" * 55)
    print("   TEMBUSU GRAND (990 SQFT) QUANTITATIVE VALUATION   ")
    print("=" * 55)
    print(f"档位（楼层参照）       : Tier floor {state.tier_floor}")
    print(f"净溢价权重            : {res_owner.net_adjustment_applied}")
    print(f"EOK PSF (post-harmo)   : ${state.psf_eok_post_harmo:,}")
    print(f"EOK PSF (pre-harmo)    : ${state.psf_eok_pre_harmo:,.2f}  (= post × {state.h_deflator})")
    pad = (
        max(len(lbl) for lbl in res_owner.adjustment_breakdown)
        if res_owner.adjustment_breakdown
        else 0
    )
    print("净溢价分项:")
    for label, pts in res_owner.adjustment_breakdown.items():
        sign = "+" if pts > 0 else ""
        print(f"    {label.ljust(pad)}  {sign}{pts}%")
    print(f"合理估算合理转售尺价    : ${res_owner.fair_market_psf:,} PSF")
    print("-" * 55)
    print(f"理性公平总价 (FMV)    : ${res_owner.fair_market_value:,}")
    print(f"出价博弈安全区间       : ${res_owner.negotiation_floor:,} - ${res_owner.negotiation_ceiling:,}")
    print("=" * 55)

    plot_fmv_model(state, save_path=args.save)