// 952. Largest Component Size by Common Factor [H]
// LeetCode largest-component-size-by-common-factor

struct UF {
    vector<int> parent;
    vector<int> size;
    UF(int n) {
        parent.resize(n);
        size.resize(n);
        for(int i = 0; i < n; i ++) {
            parent[i] = i;
            size[i] = 1;
        }
    } 
    void unite(int x, int y) {
        int root_x = find_root(x);
        int root_y = find_root(y);
        if(root_x == root_y) return;
        if(size[root_x] >= size[root_y]) {
            size[root_x] += size[root_y];
            parent[root_y] = root_x;
        } else {
            size[root_y] += size[root_x];
            parent[root_x] = root_y;
        }
    };

    int find_root(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find_root(parent[x]);
    }

    int get_max_size() {
        return *max_element(size.begin(), size.end());
    }
};
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> dict;
        auto get_prime_factors = [&] (int x) {
            vector<int> ans;
            for(int p = 2; p * p <= x; p += 1) {
                if(x % p == 0) ans.push_back(p);
                while(x % p == 0) x /= p;
            }
            if(x > 1) ans.push_back(x);
            return ans;
        };    
        UF uf(n); 
        for(int i = 0; i < n; i ++) {
            int num = nums[i];
            auto factors = get_prime_factors(num);
            for(int factor : factors) {
                if(dict.contains(factor)) {
                    uf.unite(i, dict[factor]);
                } else {
                    dict[factor] = i;
                }
            }
        }
        return uf.get_max_size();
    }
};