from dataclasses import dataclass


@dataclass
class Ans:
    net_adjustment_applied: str
    fair_market_psf: float
    fair_market_value: float
    negotiation_floor: float
    negotiation_ceiling: float

def calculate_perfect_condo_fmv(p_eok=2650, tg_book_size=990) -> Ans:
    
    # 1. 尺价脱水转化 (Post-Harmonization -> Pre-Harmonization)
    # Emerald 的 2600 PSF 去掉 5% 的公摊溢价
    h_deflator = 0.95 
    p_base = p_eok * h_deflator # 还原后等效老政开盘基准尺价 (~$2,470)
        
    # 3. 核心溢价/折价矩阵 (Delta Matrix)
    adjustments = {
        "mrt_location": -0.025,        # 距离 Tanjong Katong MRT 稍远
        "immediate_top": 0.060,        # 2年现房即住的机会成本时间溢价
        "cdl_branding_view": 0.03,     # CDL品牌口碑
        "lease_age_decay": -0.015,     # 土地地契年限差距 1% per year
        "supply_penalty": -0.020,      # 考虑隔壁低价地块带来的潜在竞品压制，给予对冲惩罚
        "year_to_year_price_increase": 0.030,  # 考虑年化价格增长
    }
    
    sum_delta = sum(adjustments.values())
    
    # 4. 计算 Tembusu Grand 的公平合理账面 PSF
    p_tg_fair = p_base * (1 + sum_delta)
    
    # 5. 挂钩老政账面面积，计算结构性转售公平总价 (Intrinsic FMV)
    fmv_tg = p_tg_fair * tg_book_size
    
    # 6. 转售市场的撮合价格区间 (Market Negotiation Buffer +/- 1.5%)
    lower_bound = round((fmv_tg * 0.985), -3)
    upper_bound = round((fmv_tg * 1.015), -3)
    
    return Ans(
        net_adjustment_applied=f"{round(sum_delta * 100, 1)}%",
        fair_market_psf=round(p_tg_fair, 2),
        fair_market_value=round(fmv_tg, 2),
        negotiation_floor=lower_bound,
        negotiation_ceiling=upper_bound
    )

if __name__ == "__main__":
    # 模拟一个自住刚需买家的视角
    res_owner = calculate_perfect_condo_fmv()
    
    print("=" * 55)
    print("   TEMBUSU GRAND (990 SQFT) QUANTITATIVE VALUATION   ")
    print("=" * 55)
    print(f"净溢价权重            : {res_owner.net_adjustment_applied}")
    print(f"合理估算合理转售尺价    : ${res_owner.fair_market_psf:,} PSF")
    print("-" * 55)
    print(f"理性公平总价 (FMV)    : ${res_owner.fair_market_value:,}")
    print(f"出价博弈安全区间       : ${res_owner.negotiation_floor:,} - ${res_owner.negotiation_ceiling:,}")
    print("=" * 55)