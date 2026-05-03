// 327. Count of Range Sum [H]
// LeetCode count-of-range-sum

class Solution {
class BIT{
private:
    int n;
    vector<int> arr;
    int lowbit(int idx){
        return idx & (-idx);
    }
public:
    BIT(int _n):n(_n), arr(_n+1){
        arr[0] = 0;
        for(int idx = 0; idx < n; ++idx){
            add(idx, 1);
        }
    }
    void add(int idx, int delta){
        ++idx;
        while(idx < arr.size()){
            arr[idx] += delta;
            idx += lowbit(idx);     
        }
    }
    int query(int idx){
        ++idx;
        int sum = 0;
        while(idx > 0){
            sum += arr[idx];
            idx -= lowbit(idx);
        }
        return sum;
    }
};
public:
int countRangeSum(vector<int>& nums, int lower, int upper){
    vector<long long> sum(nums.size()+1, 0);
    for(int i = 0; i < nums.size(); ++i){
        sum[i+1] = sum[i]+nums[i];
    }
    vector<long long> A(sum.begin(), sum.end());
    sort(A.begin(), A.end());       
    BIT tree(A.size());
    int count = 0;
    for(const auto &x : sum){
        int idx = lower_bound(A.begin(), A.end(), x)-A.begin();
        int lowerIdx = lower_bound(A.begin(), A.end(), x+lower)-A.begin();
        int upperIdx = upper_bound(A.begin(), A.end(), x+upper)-A.begin()-1;
        tree.add(idx, -1);
        count += tree.query(upperIdx) - tree.query(lowerIdx-1);
    }
    return count;
}
};