// 3589. Count Prime-Gap Balanced Subarrays [M]
// LeetCode count-prime-gap-balanced-subarrays

struct MonoQueue {
    vector<int> nums;
    queue<int> q;
    deque<int> maxQ;
    deque<int> minQ;
    void push(int i) {
        int x = nums[i];
        q.push(i);
        while(!maxQ.empty() && nums[maxQ.back()] < x) maxQ.pop_back();
        maxQ.push_back(i);
        while(!minQ.empty() && nums[minQ.back()] > x) minQ.pop_back();
        minQ.push_back(i);
    }
    void pop() {
        int cur = q.front();
        q.pop();
        if(maxQ.front() == cur) maxQ.pop_front();
        if(minQ.front() == cur) minQ.pop_front();
    }
    int gap() {
        return nums[maxQ.front()] - nums[minQ.front()];
    }
};
class Solution {
public:
    vector<int> isPrime;
    void sieve(int maxVal) {
        isPrime.assign(maxVal + 1, true);
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i * i <= maxVal; i ++) {
            if(isPrime[i]) {
                for(int j = i * i; j <= maxVal; j += i) isPrime[j] = false;
            }
        }
    }
    int primeSubarray(vector<int>& nums, int k) {
        MonoQueue mq(nums);
        sieve(5 * 1e4);
        int ans = 0, left = 0, right = 0;
        int last = -1, last2 = -1;
        while(right < nums.size()) {
            int num = nums[right];
            // cout << num << endl;
            if(isPrime[num]) {
                // cout << "isPrime" << endl;
                last2 = last;
                last = right;
                mq.push(right);
                // cout << mq.gap() << endl;
                while(mq.gap() > k) {
                    while(!mq.q.empty() && mq.q.front() == left) mq.pop();
                    left += 1;
                    // if(nums[left] == mq.q.front())mq.pop();
                }
            }
            // cout << last2 << " " << left << endl;
            ans += max(last2 - left + 1, 0);
            right += 1;
        }
        return ans;
    }
};