// 1534. Count Good Triplets [E]
// LeetCode count-good-triplets

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int ans = 0;
        for(int j = 1; j < arr.size(); j ++) {
            for(int i = 0; i < j; i ++) {
                for(int k = j + 1; k < arr.size(); k ++) {
                    if(abs(arr[i] - arr[j]) <= a) {
                        if(abs(arr[j] - arr[k]) <= b) {
                            if(abs(arr[i] - arr[k]) <= c) {
                                ans += 1;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};