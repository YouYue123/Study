#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Item {
    ll start;
    ll end;
    int idx;
};
void solve() {
    int n;
    cin >> n;
    vector<Item> items(n);
    for(int i =0; i < n; i ++) {
        cin >> items[i].start >> items[i].end;
        items[i].idx = i;
    }
    sort(items.begin(), items.end(), [&] (auto& a, auto& b) {
        if(a.start == b.start) return a.end > b.end;
        return a.start < b.start;
    });
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    int nxt_assigned_room = 1;
    queue<int> free_queue;
    vector<int> rooms(n);
    for(auto& [start, end, idx] : items) {
        while(!pq.empty() && pq.top().first < start) {
            auto cur = pq.top();
            free_queue.push(cur.second);
            pq.pop();
        }
        if(!free_queue.empty()) {
            rooms[idx] = free_queue.front();
            pq.emplace(end, free_queue.front());
            free_queue.pop();
        } else {
            rooms[idx] = nxt_assigned_room;
            pq.emplace(end, nxt_assigned_room);
            nxt_assigned_room += 1;
        }
    }
    cout << nxt_assigned_room - 1 << endl;
    for(int room : rooms) {
        cout << room << " ";
    }
    cout << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}