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
}


@dataclass
class Ans:
    net_adjustment_applied: str
    fair_market_psf: float
    fair_market_value: float
    negotiation_floor: float
    negotiation_ceiling: float


@dataclass(frozen=True)
class FMVModelState:
    """Intermediate values shared by reporting and plotting."""

    p_eok: float
    tg_book_size: float
    h_deflator: float
    p_base: float
    adjustments: dict[str, float]
    sum_delta: float
    p_tg_fair: float
    fmv_tg: float
    negotiation_floor: float
    negotiation_ceiling: float


def run_fmv_model(p_eok: float = 2591, tg_book_size: float = 990) -> FMVModelState:
    h_deflator = 0.95
    p_base = p_eok * h_deflator
    adjustments = {
        "mrt_location": -3,
        "immediate_top": 6,
        "cdl_branding_view": 3,
        "lease_age_decay": -1 * 1.5,
        "year_to_year_price_increase": 3,
    }
    sum_delta = sum(adjustments.values())
    p_tg_fair = p_base * (1 + sum_delta / 100.0)
    fmv_tg = p_tg_fair * tg_book_size
    lower_bound = round(fmv_tg * 0.985, -3)
    upper_bound = round(fmv_tg * 1.015, -3)
    return FMVModelState(
        p_eok=p_eok,
        tg_book_size=tg_book_size,
        h_deflator=h_deflator,
        p_base=p_base,
        adjustments=adjustments,
        sum_delta=sum_delta,
        p_tg_fair=p_tg_fair,
        fmv_tg=fmv_tg,
        negotiation_floor=lower_bound,
        negotiation_ceiling=upper_bound,
    )


def calculate_perfect_condo_fmv(p_eok: float = 2591, tg_book_size: float = 990) -> Ans:
    s = run_fmv_model(p_eok, tg_book_size)
    return Ans(
        net_adjustment_applied=f"{round(s.sum_delta, 1)}%",
        fair_market_psf=round(s.p_tg_fair, 2),
        fair_market_value=round(s.fmv_tg, 2),
        negotiation_floor=s.negotiation_floor,
        negotiation_ceiling=s.negotiation_ceiling,
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

    psf_steps = ["EOK\n(pre-harmo)", "EOK\n(post-harmo)", "TG\n(FMV)"]
    psf_vals = [state.p_eok, state.p_base, state.p_tg_fair]
    axes[1].bar(psf_steps, psf_vals, color=["#546e7a", "#0277bd", "#1565c0"])
    axes[1].set_ylabel("$ / sqft")
    axes[1].set_title("PSF cascade tower 51 9th floor 990 sqft as example")

    fig.suptitle(
        f"Tembusu FMV ({state.tg_book_size:,.0f} sqft · deflator ×{state.h_deflator})",
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
        "--save",
        metavar="PATH",
        help="Write figure to PATH (PNG/SVG/PDF per extension) instead of only showing",
    )
    args = parser.parse_args()

    res_owner = calculate_perfect_condo_fmv()
    state = run_fmv_model()

    print("=" * 55)
    print("   TEMBUSU GRAND (990 SQFT) QUANTITATIVE VALUATION   ")
    print("=" * 55)
    print(f"净溢价权重            : {res_owner.net_adjustment_applied}")
    print(f"合理估算合理转售尺价    : ${res_owner.fair_market_psf:,} PSF")
    print("-" * 55)
    print(f"理性公平总价 (FMV)    : ${res_owner.fair_market_value:,}")
    print(f"出价博弈安全区间       : ${res_owner.negotiation_floor:,} - ${res_owner.negotiation_ceiling:,}")
    print("=" * 55)

    plot_fmv_model(state, save_path=args.save)
