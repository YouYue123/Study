#include <iostream>

using namespace std;

int main()
{
    int w;
    cin >> w;
    if (w % 2 == 0 && w > 2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}

class Solution {
public:  

    // returns the number of subarrays with more than or equal to k odd numbers
    int f(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int count = 0;
        int ans = 0;
        while(right < nums.size()) {
            count += nums[right] % 2 == 1;
            while(count >= k) {
                count -= nums[left] % 2 == 1;
                left += 1;
            }
            ans += left;
            right += 1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k + 1);
    }
};