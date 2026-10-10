#include <iostream>
#include <map>
#include <list>
#include <unordered_map>

struct Order {
    int id;
    int amount;
    double price;
    bool isBuy;
};

// 存储订单在 list 中的位置，方便 O(1) 删除
struct OrderEntry {
    double price;
    bool isBuy;
    std::list<Order>::iterator it;
};

class OrderBook {
    // 价格 -> 该价格下的订单队列
    std::map<double, std::list<Order>> sellSide;
    std::map<double, std::list<Order>, std::greater<double>> buySide;

    // 订单 ID -> 订单位置信息
    std::unordered_map<int, OrderEntry> orderMap;

public:
    // 撤单功能：O(1) 
    void cancelOrder(int id) {
        if (orderMap.find(id) == orderMap.end()) {
            std::cout << "Order " << id << " not found or already filled.\n";
            return;
        }

        OrderEntry entry = orderMap[id];
        if (entry.isBuy) {
            buySide[entry.price].erase(entry.it);
            if (buySide[entry.price].empty()) buySide.erase(entry.price);
        } else {
            sellSide[entry.price].erase(entry.it);
            if (sellSide[entry.price].empty()) sellSide.erase(entry.price);
        }

        orderMap.erase(id);
        std::cout << "Order " << id << " cancelled successfully.\n";
    }

    // 撮合与下单逻辑
    void limitOrder(int id, double price, int amount, bool isBuy) {
        if (isBuy) {
            // 尝试与卖单撮合
            auto it = sellSide.begin();
            while (it != sellSide.end() && it->first <= price && amount > 0) {
                auto& queue = it->second;
                while (!queue.empty() && amount > 0) {
                    Order& top = queue.front();
                    int traded = std::min(amount, top.amount);
                    
                    std::cout << "Match! ID " << id << " bought from " << top.id 
                              << " | Qty: " << traded << " @ " << it->first << "\n";
                    
                    amount -= traded;
                    top.amount -= traded;
                    
                    if (top.amount == 0) {
                        orderMap.erase(top.id); // 成交完，从全局 Map 删除
                        queue.pop_front();
                    }
                }
                if (queue.empty()) it = sellSide.erase(it);
                else ++it;
            }
            // 剩余部分进入买单簿
            if (amount > 0) {
                buySide[price].push_back({id, amount, price, true});
                orderMap[id] = {price, true, --buySide[price].end()};
            }
        } else {
            // 卖单逻辑 (与买单对称)
            auto it = buySide.begin();
            while (it != buySide.end() && it->first >= price && amount > 0) {
                auto& queue = it->second;
                while (!queue.empty() && amount > 0) {
                    Order& top = queue.front();
                    int traded = std::min(amount, top.amount);
                    std::cout << "Match! ID " << id << " sold to " << top.id 
                              << " | Qty: " << traded << " @ " << it->first << "\n";
                    amount -= traded;
                    top.amount -= traded;
                    if (top.amount == 0) {
                        orderMap.erase(top.id);
                        queue.pop_front();
                    }
                }
                if (queue.empty()) it = buySide.erase(it);
                else ++it;
            }
            if (amount > 0) {
                sellSide[price].push_back({id, amount, price, false});
                orderMap[id] = {price, false, --sellSide[price].end()};
            }
        }
    }
};

int main() {
    OrderBook ob;

    std::cout << "--- Scenario 1: Basic Matching & Price Priority ---\n";
    // 先挂两个卖单
    ob.limitOrder(101, 10.5, 100, false); // 卖单1: $10.5, 100股
    ob.limitOrder(102, 10.2, 50, false);  // 卖单2: $10.2, 50股 (价格更优)

    // 发起买单：$11.0, 120股
    // 预期：先成交 102 号单 (50股)，再成交 101 号单 (70股)，买单剩余 0
    ob.limitOrder(201, 11.0, 120, true);

    std::cout << "\n--- Scenario 2: Partial Fill & Standing Order ---\n";
    // 卖单 101 还剩 30 股在簿子上
    // 发起买单：$10.0, 50股
    // 预期：价格不匹配，买单 202 挂在买单簿上
    ob.limitOrder(202, 10.0, 50, true);

    std::cout << "\n--- Scenario 3: Cancellation ---\n";
    // 撤销刚才挂着的买单 202
    ob.cancelOrder(202);
    // 尝试再次撤销同一个 ID (预期失败)
    ob.cancelOrder(202);

    std::cout << "\n--- Scenario 4: Clearing Multiple Price Levels ---\n";
    ob.limitOrder(103, 15.0, 10, false);
    ob.limitOrder(104, 16.0, 10, false);
    ob.limitOrder(105, 17.0, 10, false);

    // 一笔大买单横扫三个价位
    // 预期：依次匹配 103, 104, 105，最后买单 203 剩余 20 股挂在 $20.0
    ob.limitOrder(203, 20.0, 50, true);

    return 0;
}