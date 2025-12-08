#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<ull, ull>;
struct Pair {
    int i, j;
    int distance;
    Pair(int i, int j, int distance) : i(i), j(j), distance(distance) {}
    bool operator<(const Pair& other) const {
        return distance < other.distance;
    }
    bool operator>(const Pair& other) const {
        return distance > other.distance;
    }
    bool operator==(const Pair& other) const {
        return i == other.i && j == other.j;
    }
};
struct UF {
    vector<int> parent;
    int count;
    vector<int> size;
    UF(int n) : parent(n), count(n), size(n, 1) {
        for(int i = 0; i < n; i ++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x != y) {
            parent[y] = x;
            count -= 1;
            size[x] += size[y];
        }
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
    int getSize(int x) {
        return size[find(x)];
    }
};
int main() {
    auto start = chrono::high_resolution_clock::now();
    ull ans = 1;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<ll>> nums;
    string line = "";
    vector<string> g;
    while(getline(cin, line)) {
        // cout << line << endl;
        stringstream ss(line);
        string num;
        vector<ll> temp;
        while(getline(ss, num, ',')) {
            // cout << num << " ";
            temp.push_back(stoll(num));
        }
        nums.push_back(temp);
    }
    cout << "nums: " << nums.size() << endl;
    auto getEuclideanDistance = [&](int i, int j) -> ll {
        return sqrt(pow(nums[i][0] - nums[j][0], 2) + pow(nums[i][1] - nums[j][1], 2) + pow(nums[i][2] - nums[j][2], 2));
    };
    priority_queue<Pair, vector<Pair>, greater<Pair>> pairs;
    for(int i = 0; i < nums.size(); i ++) {
        for(int j = i + 1; j < nums.size(); j ++) {
            // cout << "i: " << i << " j: " << j << endl;
            ll distance = getEuclideanDistance(i, j);
            // cout << "distance: " << distance << endl;
            Pair p = Pair(i, j, distance);
            pairs.push(p);
        }
    }
    // cout << "ranked pairs: " << pairs.size() << endl;
    int cnt = 1;
    UF uf(nums.size());
    int k = 1000;
    while(!pairs.empty() && cnt <= k) {
        Pair p = pairs.top(); pairs.pop();
        // cout << "first element: " << nums[p.i][0] << "," << nums[p.i][1] << "," << nums[p.i][2] << endl;
        // cout << "second element: " << nums[p.j][0] << "," << nums[p.j][1] << "," << nums[p.j][2] << endl;
        // cout << "distance: " << p.distance << endl;
        // cout << "p: " << p.i << " " << p.j << " " << p.distance << endl;
        if(!uf.connected(p.i, p.j)) {
            uf.unite(p.i, p.j);
        }
        // cout << "cnt: " << cnt << endl;
        // cout << "circuit: " << uf.count << endl;
        cnt += 1;
    }
    vector<int> sizes;
    for(int i = 0; i < nums.size(); i ++) {
        if(uf.find(i) == i) {
            sizes.push_back(uf.getSize(i));
        }
    }
    sort(sizes.begin(), sizes.end(), greater<int>());
    for(int i = 0; i < 3; i ++) {
        // cout << "size " << i << ": " << sizes[i] << endl;
        ans = ans * sizes[i];
    }
    // ans = nums.size() - uf.count;
    cout << "ans:" << ans << endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "runtime: " << duration.count() << " nanoseconds" << endl;
}