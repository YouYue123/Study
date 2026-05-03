// 528. Random Pick with Weight [M]
// LeetCode random-pick-with-weight

class Solution {
private:
    vector<int> pre_sum;
public:
    Solution(vector<int>& w) {
        int n = w.size();
        pre_sum.assign(n, 0);
        int sum = 0;
        for(int i = 0; i < n; i ++) {
            sum += w[i];
            pre_sum[i] = sum;
        }
    }
    
    int pickIndex() {
        int n = pre_sum.size();
        int max_sum = pre_sum.back();
        int target = rand() % max_sum;
        auto is_valid = [&] (int x) {
            return pre_sum[x] <= target;
        };
        int left = -1, right = n;
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(is_valid(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left + 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */