#include <bits/stdc++.h>
using namespace std;

// 901. Online Stock Span [M]
// LeetCode online-stock-span

struct Node {
    int price;
    int cnt;
};
class StockSpanner {
private:
    stack<Node> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        while(!st.empty() && st.top().price <= price) {
            // if(price == 85) cout << st.top().price << " " << st.top().cnt << endl;
            ans += st.top().cnt;
            st.pop();
        }
        // cout << price << " " << ans << endl;
        st.emplace(price, ans);
        // cout << price << endl;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */