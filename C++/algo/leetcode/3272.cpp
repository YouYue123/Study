// 3272. Find the Count of Good Integers [H]
// LeetCode find-the-count-of-good-integers

class Solution {
public:
    vector<long long> fact;
    void precompute_fact(int n) {
        fact.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
    }

    int n;
    int k;
    long long ans = 0;
    unordered_map<string, bool> seen;
    void traverse(string& cur, int left, int right) {
        int low = 0;
        if(left > right) {
            long val = stol(cur);
            if(val % k == 0) {
                // cout << "YES" << endl;
                // cout << cur << endl;
                string temp = cur;
                sort(temp.begin(), temp.end());
                if(seen[temp]) return;
                seen[temp] = true;
                unordered_map<char, int> count;
                for (char c : temp) count[c]++;
                long long product = 1;
                for (auto& [d, cnt] : count) product *= fact[cnt];
                long long total = fact[n] / product;
                if (count.count('0')) {
                        int zero_cnt = count['0'];
                        if (zero_cnt > 0) {
                        long long new_product = product / fact[zero_cnt] * fact[zero_cnt - 1];
                        long long invalid = fact[n - 1] / new_product;                        
                        total -= invalid;
                    }
                }
                // cout << total << endl;
                ans += total;
            }
            return;
        };
        if(left == 0) low = 1;
        for(int i = low; i <= 9; i ++) {
            cur[left] = i + '0';
            cur[right] = i + '0';
            traverse(cur, left + 1, right - 1);
            cur[left] = '0';
            cur[right] = '0';
        }
    }
    long long countGoodIntegers(int n, int k) {
        this->n = n;
        this->k = k;
        precompute_fact(n);
        string cur(n, '0');
        traverse(cur, 0, n - 1);
        return ans;
    }
};

    // int bt(string& nums, string cur, unordered_map<int,bool>& used) {
    //     if(cur.size() == n) {
    //         // cout << cur << endl;
    //         return 1;
    //     }
    //     int ans = 0;
    //     for(int i = 0; i < nums.size(); i ++) {
    //         if(i >0 && nums[i] == nums[i - 1] && used[i-1]) continue;
    //         if(cur.size() == 0 && nums[i] == '0') continue;
    //         if(used[i]) continue;
    //         used[i] = true;
    //         ans += bt(nums, cur + nums[i], used);
    //         used[i] = false;
    //     }
    //     return ans;
    // }