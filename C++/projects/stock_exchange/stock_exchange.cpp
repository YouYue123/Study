#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <atomic>
#include <mutex>  // Added for thread safety
#include <future> // Added for async
enum class OrderType
{
    BUY,
    SELL
};

struct Order
{
    int order_id;
    std::string user_id;
    std::string symbol;
    OrderType order_type;
    double price;
    int quantity;
    long long timestamp;
};

struct Trade
{
    int buy_order_id;
    int sell_order_id;
    std::string symbol;
    double price;
    int quantity;
    long long timestamp;
};

class User
{
public:
    std::string user_id;
    double cash_balance;
    std::unordered_map<std::string, int> stocks;
};

struct BuyOrderComparator
{
    bool operator()(const Order &a, const Order &b) const
    {
        return a.price < b.price || (a.price == b.price && a.timestamp > b.timestamp);
    }
};

struct SellOrderComparator
{
    bool operator()(const Order &a, const Order &b) const
    {
        return a.price > b.price || (a.price == b.price && a.timestamp > b.timestamp);
    }
};

class StockExchange
{
private:
    std::unordered_map<std::string, std::priority_queue<Order, std::vector<Order>, BuyOrderComparator>> buy_orders;
    std::unordered_map<std::string, std::priority_queue<Order, std::vector<Order>, SellOrderComparator>> sell_orders;
    std::vector<Trade> trades;
    std::unordered_map<std::string, User> users;
    std::atomic<long long> current_timestamp;
    std::atomic<int> next_order_id; // Changed to atomic
    std::mutex exchange_mutex;      // Added for thread safety

    void _add_order(const Order &order)
    {
        std::string output;
        output += "Adding order:\n";
        output += "Order ID: " + std::to_string(order.order_id) + ", User ID: " + order.user_id +
                  ", Symbol: " + order.symbol + ", Type: " + (order.order_type == OrderType::BUY ? "BUY" : "SELL") +
                  ", Price: " + std::to_string(order.price) + ", Quantity: " + std::to_string(order.quantity) +
                  ", Timestamp: " + std::to_string(order.timestamp) + "\n";

        if (order.order_type == OrderType::BUY)
        {
            buy_orders[order.symbol].push(order);
        }
        else
        {
            sell_orders[order.symbol].push(order);
        }

        std::cout << output; // Print outside critical section
    }

    void _match_orders(const std::string &symbol)
    {
        std::string output;
        bool matched = false;

        {
            while (!buy_orders[symbol].empty() && !sell_orders[symbol].empty())
            {
                Order buy_order = buy_orders[symbol].top();
                Order sell_order = sell_orders[symbol].top();

                if (buy_order.price < sell_order.price)
                {
                    break;
                }

                matched = true;
                output += "------------------------\n";
                output += "Matching orders:\n";
                output += "Trade Symbol: " + symbol + "\n";
                output += "Trade price: " + std::to_string(sell_order.price) + "\n";
                output += "Trade quantity: " + std::to_string(std::min(buy_order.quantity, sell_order.quantity)) + "\n";
                output += "Timestamp: " + std::to_string(current_timestamp.load()) + "\n";
                output += "Buy Order ID: " + std::to_string(buy_order.order_id) + ", User ID: " + buy_order.user_id + "\n";
                output += "Sell Order ID: " + std::to_string(sell_order.order_id) + ", User ID: " + sell_order.user_id + "\n";
                output += "Buy Order Price: " + std::to_string(buy_order.price) + ", Quantity: " + std::to_string(buy_order.quantity) + "\n";
                output += "Sell Order Price: " + std::to_string(sell_order.price) + ", Quantity: " + std::to_string(sell_order.quantity) + "\n";
                output += "------------------------\n";

                int trade_quantity = std::min(buy_order.quantity, sell_order.quantity);
                double trade_price = sell_order.price;

                Trade trade = {
                    buy_order.order_id,
                    sell_order.order_id,
                    symbol,
                    trade_price,
                    trade_quantity,
                    current_timestamp.fetch_add(1, std::memory_order_acq_rel)};
                trades.push_back(trade);

                _update_user_balance(buy_order.user_id, symbol, trade_quantity, trade_price);
                _update_user_balance(sell_order.user_id, symbol, -trade_quantity, trade_price);

                buy_orders[symbol].pop();
                sell_orders[symbol].pop();

                buy_order.quantity -= trade_quantity;
                sell_order.quantity -= trade_quantity;

                if (buy_order.quantity > 0)
                {
                    buy_orders[symbol].push(buy_order);
                }
                if (sell_order.quantity > 0)
                {
                    sell_orders[symbol].push(sell_order);
                }
            }

            if (buy_orders[symbol].empty())
            {
                buy_orders.erase(symbol);
            }
            if (sell_orders[symbol].empty())
            {
                sell_orders.erase(symbol);
            }
        }

        if (matched)
        {
            std::cout << output; // Print outside critical section
        }
    }

    void _update_user_balance(const std::string &user_id, const std::string &symbol, int quantity, double price)
    {
        auto &user = users[user_id];
        user.stocks[symbol] += quantity;
        user.cash_balance -= price * quantity;

        if (user.stocks[symbol] == 0)
        {
            user.stocks.erase(symbol);
        }
    }

public:
    StockExchange() : current_timestamp(0), next_order_id(1) {}

    void add_user(const std::string &user_id, double initial_balance, const std::unordered_map<std::string, int> &initial_stocks)
    {
        std::lock_guard<std::mutex> lock(exchange_mutex);
        users[user_id] = {user_id, initial_balance, initial_stocks};
        std::cout << "User added: " << user_id << ", Initial Balance: " << initial_balance << std::endl;
    }

    bool place_order(const std::string &user_id, const std::string &symbol, OrderType order_type, double price, int quantity)
    {
        std::lock_guard<std::mutex> lock(exchange_mutex);
        if (!users.contains(user_id))
        {
            std::cout << "User not found" << std::endl;
            return false;
        }

        if (order_type == OrderType::BUY)
        {
            if (users[user_id].cash_balance < price * quantity)
            {
                std::cout << "Not enough cash" << std::endl;
                return false;
            }
        }
        else
        {
            if (users[user_id].stocks[symbol] < quantity)
            {
                std::cout << "Not enough stocks" << std::endl;
                return false;
            }
        }

        Order order = {
            next_order_id.fetch_add(1, std::memory_order_acq_rel),
            user_id,
            symbol,
            order_type,
            price,
            quantity,
            current_timestamp.fetch_add(1, std::memory_order_acq_rel)};

        _add_order(order);
        _match_orders(symbol);
        return true;
    }

    void display_portfolio(const std::string &user_id)
    {
        std::string output;
        {
            if (!users.contains(user_id))
            {
                output = "User not found\n";
            }
            else
            {
                const auto &user = users[user_id];
                output += "User ID: " + user.user_id + ", Cash Balance: " + std::to_string(user.cash_balance) + "\n";
                for (const auto &[symbol, quantity] : user.stocks)
                {
                    if (quantity > 0)
                    {
                        output += "Stock: " + symbol + ", Quantity: " + std::to_string(quantity) + "\n";
                    }
                }
            }
        }
        std::cout << output; // Print outside critical section
    }

    void display_trades()
    {
        std::string output = "Trades:\n";
        {
            for (const auto &trade : trades)
            {
                output += "Buy Order ID: " + std::to_string(trade.buy_order_id) +
                          ", Sell Order ID: " + std::to_string(trade.sell_order_id) +
                          ", Symbol: " + trade.symbol +
                          ", Price: " + std::to_string(trade.price) +
                          ", Quantity: " + std::to_string(trade.quantity) +
                          ", Timestamp: " + std::to_string(trade.timestamp) + "\n";
            }
        }
        std::cout << output; // Print outside critical section
    }
};

// main() remains unchanged
int main()
{
    StockExchange exchange;

    std::unordered_map<std::string, int> initial_stocks;
    initial_stocks["AAPL"] = 10;
    std::unordered_map<std::string, int> initial_stocks2;
    initial_stocks2["GOOG"] = 10;
    std::unordered_map<std::string, int> initial_stocks3;
    exchange.add_user("user1", 10000, initial_stocks);
    exchange.add_user("user2", 10000, initial_stocks2);
    exchange.add_user("user3", 10000, initial_stocks3);

    exchange.place_order("user1", "AAPL", OrderType::SELL, 150, 5);
    exchange.place_order("user2", "AAPL", OrderType::BUY, 155, 3);
    exchange.place_order("user2", "GOOG", OrderType::SELL, 160, 5);
    exchange.place_order("user3", "GOOG", OrderType::BUY, 159, 3);
    exchange.place_order("user1", "GOOG", OrderType::BUY, 161, 5);

    exchange.display_portfolio("user1");
    exchange.display_portfolio("user2");
    exchange.display_portfolio("user3");
    exchange.display_trades();

    return 0;
}