#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <ctime>

// 订单类型枚举
enum class OrderType {
    BUY,
    SELL
};

// 订单结构体
struct Order {
    int id;         // 订单ID
    OrderType type;  // 买卖类型
    double price;    // 价格
    int quantity;    // 数量
    time_t timestamp; // 时间戳

    Order(int _id, OrderType _type, double _price, int _quantity)
        : id(_id), type(_type), price(_price), quantity(_quantity) {
        timestamp = time(nullptr);
    }
};

// 订单比较器（买单调价降序，卖单调价升序）
struct BuyComparator {
    bool operator()(const Order& a, const Order& b) {
        return a.price < b.price; // 买单价高的优先
    }
};

struct SellComparator {
    bool operator()(const Order& a, const Order& b) {
        return a.price > b.price; // 卖单价低的优先
    }
};

// 订单簿类
class OrderBook {
private:
    // 使用优先队列存储订单
    std::priority_queue<Order, std::vector<Order>, BuyComparator> buyOrders;
    std::priority_queue<Order, std::vector<Order>, SellComparator> sellOrders;
    
    // 交易记录
    std::vector<std::string> tradeHistory;
    
    int orderIdCounter = 1;

public:
    // 添加新订单
    void addOrder(OrderType type, double price, int quantity) {
        Order newOrder(orderIdCounter++, type, price, quantity);
        
        if (type == OrderType::BUY) {
            buyOrders.push(newOrder);
        } else {
            sellOrders.push(newOrder);
        }
        
        matchOrders();
    }

    // 订单撮合逻辑
    void matchOrders() {
        while (!buyOrders.empty() && !sellOrders.empty()) {
            Order& topBuy = const_cast<Order&>(buyOrders.top());
            Order& topSell = const_cast<Order&>(sellOrders.top());

            // 检查是否可成交（买价 >= 卖价）
            if (topBuy.price >= topSell.price) {
                int tradeQty = std::min(topBuy.quantity, topSell.quantity);
                double tradePrice = topSell.price; // 以卖单价成交

                // 记录交易
                tradeHistory.push_back(
                    "TRADE: " + std::to_string(tradeQty) + " @ " +
                    std::to_string(tradePrice) + " | BuyID:" +
                    std::to_string(topBuy.id) + " SellID:" +
                    std::to_string(topSell.id)
                );

                // 更新订单数量
                topBuy.quantity -= tradeQty;
                topSell.quantity -= tradeQty;

                // 移除完全成交的订单
                if (topBuy.quantity == 0) buyOrders.pop();
                if (topSell.quantity == 0) sellOrders.pop();
            } else {
                break; // 没有可成交订单
            }
        }
    }

    // 打印当前订单簿状态
    void printOrderBook() {
        std::cout << "\n=== Order Book ===";
        
        // 临时存储用于恢复
        auto tempBuy = buyOrders;
        auto tempSell = sellOrders;

        std::cout << "\nBuy Orders:\n";
        while (!tempBuy.empty()) {
            auto order = tempBuy.top();
            std::cout << "[" << order.id << "] " << order.quantity 
                      << " @ " << order.price << "\n";
            tempBuy.pop();
        }

        std::cout << "\nSell Orders:\n";
        while (!tempSell.empty()) {
            auto order = tempSell.top();
            std::cout << "[" << order.id << "] " << order.quantity 
                      << " @ " << order.price << "\n";
            tempSell.pop();
        }
    }

    // 打印交易记录
    void printTradeHistory() {
        std::cout << "\n=== Trade History ===\n";
        for (const auto& record : tradeHistory) {
            std::cout << record << "\n";
        }
    }
};

int main() {
    OrderBook book;

    // 测试订单
    book.addOrder(OrderType::SELL, 100.0, 5);  // 卖单1
    book.addOrder(OrderType::BUY,  105.0, 3);  // 买单1
    book.addOrder(OrderType::BUY,  100.0, 5);  // 买单2

    book.printOrderBook();
    book.printTradeHistory();

    return 0;
}