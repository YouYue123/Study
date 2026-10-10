#include <bits/stdc++.h>
using namespace std;

// 1801. Number of Orders in the Backlog [M]
// LeetCode number-of-orders-in-the-backlog

int MOD = 1e9 + 7;
enum OrderType {
    SELL,
    BUY
};

struct Order {
    int price;
    int amount;
    bool operator < (const Order& other) const {
        return price < other.price;
    }
    bool operator > (const Order& other) const {
        return price > other.price;
    }
};

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<Order, vector<Order>, greater<>> sellPq;
        priority_queue<Order> buyPq;
        for(auto& order : orders) {
            int price = order[0], amount = order[1];
            OrderType type = order[2] == 0 ? OrderType::BUY : OrderType::SELL;
            switch(type) {
                case OrderType::BUY:
                    while(!sellPq.empty() && sellPq.top().price <= price && amount > 0) {
                        if(sellPq.top().amount <= amount) {
                            amount -= sellPq.top().amount;
                            sellPq.pop();
                        } else {
                            auto cur = sellPq.top();
                            sellPq.pop();
                            cur.amount -= amount;
                            sellPq.push(cur);
                            amount = 0;
                        }
                    }
                    if(amount > 0) buyPq.emplace(price, amount);
                    break;
                case OrderType::SELL:
                    while(!buyPq.empty() && buyPq.top().price >= price && amount > 0) {
                        if(buyPq.top().amount <= amount) {
                            amount -= buyPq.top().amount;
                            buyPq.pop();
                        } else {
                            auto cur = buyPq.top();
                            buyPq.pop();
                            cur.amount -= amount;
                            buyPq.push(cur);
                            amount = 0;
                        }
                    }
                    if(amount > 0) sellPq.emplace(price, amount);
            }
        }
        long long ans = 0;
        while(!buyPq.empty()) {
            ans = (ans + buyPq.top().amount) % MOD;
            buyPq.pop();
        }
        while(!sellPq.empty()) {
            ans = (ans + sellPq.top().amount) % MOD;
            sellPq.pop();
        }
        return ans;
    }
};