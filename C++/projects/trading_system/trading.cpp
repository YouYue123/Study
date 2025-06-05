#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <ctime>
using namespace std;
enum class OrderType
{
    BUY,
    SELL
};

// TODO: add stock ticker
struct Order
{
    int id;
    OrderType type;
    double price;
    int quantity;
    time_t timestamp;
    Order(int _id, OrderType _type, double _price, int _quantity) : id(_id), type(_type), price(_price), quantity(_quantity)
    {
        // timestamp on creation
        timestamp = time(nullptr);
    };
};

struct BuyComparator
{
    bool operator()(Order &a, Order &b)
    {
        // prioritise the higher price
        return a.price < b.price;
    }
};

struct SellComparator
{
    bool operator()(Order &a, Order &b)
    {
        // prioritise the lower price
        return a.price > b.price;
    }
};

class OrderBook
{
private:
    priority_queue<Order, vector<Order>, BuyComparator> buyOrders;
    priority_queue<Order, vector<Order>, SellComparator> sellOrders;
    int tradingCounter = 1;
    vector<string> tradingHistory;
    double totalTransactionVal = 0;
    void matchOrders()
    {
        while (!buyOrders.empty() && !sellOrders.empty())
        {
            Order &topBuy = const_cast<Order &>(buyOrders.top());
            Order &topSell = const_cast<Order &>(sellOrders.top());
            if (topBuy.price >= topSell.price)
            {
                int tradingQty = min(topBuy.quantity, topSell.quantity);
                double tradingPrice = topSell.price;
                tradingHistory.push_back(
                    "TRADE " +
                    to_string(tradingQty) + "@" + to_string(tradingPrice) +
                    "|BuyID: " + to_string(topBuy.id) +
                    "|SellID: " + to_string(topSell.id));
                topBuy.quantity -= tradingQty;
                topSell.quantity -= tradingQty;
                totalTransactionVal += tradingPrice * tradingQty;
                if (topBuy.quantity == 0)
                    buyOrders.pop();
                if (topSell.quantity == 0)
                    sellOrders.pop();
            }
            else
            {
                break;
            }
        }
    }

public:
    OrderBook() {};
    void addOrder(OrderType orderType, double price, int quantity)
    {
        // cout << "addOrder: " << price << endl;
        Order newOrder(tradingCounter, orderType, price, quantity);
        tradingCounter += 1;
        switch (orderType)
        {
        case OrderType::BUY:
            cout << "add buy order: " << newOrder.id << endl;
            buyOrders.emplace(newOrder);
            break;
        case OrderType::SELL:
            sellOrders.emplace(newOrder);
            break;
        }
        matchOrders();
    }
    void printOrderBook()
    {
        cout << "=====Order Book====" << endl;
        // TODO: non-copy
        auto tempBuy = buyOrders;
        auto tempSell = sellOrders;
        cout << "====Buy====" << endl;
        while (!tempBuy.empty())
        {
            const Order order = tempBuy.top();
            tempBuy.pop();
            cout << "[" << order.id << "]" << order.quantity << "@" << order.price << endl;
        }
        cout << "====Sell====" << endl;
        while (!tempSell.empty())
        {
            const Order order = tempSell.top();
            tempSell.pop();
            cout << "[" << order.id << "]" << order.quantity << "@" << order.price << endl;
        }
    }
    void printTradeHistory()
    {
        cout << "=====Trading History====" << endl;
        for (auto &record : tradingHistory)
        {
            cout << record << endl;
        }
        cout << "=====Trading Total Val====" << endl;

        cout << totalTransactionVal << endl;
    }
};

// TODO:
// 增加订单状态管理（已成交/部分成交/未成交）

// 添加撤单功能

// 支持市价单（Market Order）

// 添加风控模块（最大仓位限制等）

// 实现网络接口（TCP/UDP协议）

// 添加数据库持久化存储

// 支持多品种交易

// 添加实时市场数据推送

int main()
{
    OrderBook *orderBook = new OrderBook();
    orderBook->addOrder(OrderType::BUY, 100, 5);
    orderBook->addOrder(OrderType::BUY, 105, 10);
    orderBook->addOrder(OrderType::SELL, 100, 20);
    orderBook->addOrder(OrderType::BUY, 90, 5);
    orderBook->addOrder(OrderType::BUY, 10000, 50000);
    orderBook->addOrder(OrderType::SELL, 1, 100);

    orderBook->printOrderBook();
    orderBook->printTradeHistory();
}