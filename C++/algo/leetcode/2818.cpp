// 2818. Apply Operations to Maximize Score [H]
// LeetCode apply-operations-to-maximize-score

class Solution {
public:
    unordered_map<int, int> memo;
    int getPrimeScore(int num) {
        int count = 0;
        int originalNum = num;
        if(memo.contains(originalNum)) return memo[originalNum];
        for(int i = 2; i * i <= num; i ++) {
            if(num % i == 0) {
                while(num % i == 0)  num /= i;
                count += 1;
            }
        }
        if(num != 1) count += 1;
        // cout << "num: " << num << endl;
        // cout << "score:" << count << endl;
        // for(int a : set) cout << a << endl;
        return memo[originalNum] = count;
    }
    int maximumScore(vector<int>& nums, int k) {
        int MOD = 1000000007;
        vector<int> primeScores;
        memo = unordered_map<int, int>();
        // cout << "prime scores" << endl;
        for(int num : nums) {
            int primeScore = getPrimeScore(num);
            // cout << num << "->" <<primeScore << " ";
            primeScores.push_back(getPrimeScore(num));
        }
        // cout << endl;
        // Keep track the first element index after
        // the current one which is larger than cur
        vector<int> before(nums.size(), -1);
        vector<int> after(nums.size(), nums.size());
        stack<int> monoS;
        for(int i = primeScores.size() - 1; i >=0; i --) {
            while(!monoS.empty() && primeScores[monoS.top()] <= primeScores[i]) {
                before[monoS.top()] = i;
                monoS.pop();
            }
            monoS.push(i);
        }
        while(!monoS.empty()) monoS.pop();
        for(int i = 0; i < primeScores.size(); i ++) {
            while(!monoS.empty() && primeScores[monoS.top()] < primeScores[i]) {
                after[monoS.top()] = i;
                monoS.pop();
            }
            monoS.push(i);
        }
        // cout << "===========" << endl;
        vector<pair<int, long long>> maxCount;
        for(int i = 0; i < nums.size(); i ++) {
            // cout << "index: " << i << endl;
            // cout << "primeScore: " << primeScores[i] << endl;
            // cout << "the closest equal or larger element index before this: " << endl;
            // cout << before[i] << endl;
            // cout << "the closest strictly larger element index after this: " << endl;
            // cout << after[i] << endl;
            // cout << "this can be choosed at most" << endl;
            long long count = (long long)(i - before[i]) * (after[i] - i);
        
            // cout << count << endl;
            // cout << "===========" << endl;
            maxCount.push_back({ nums[i], count });
        }
        sort(maxCount.begin(), maxCount.end(), greater<>());
        long long ans = 1;

        for(int i = 0; i < maxCount.size(); i ++) {
            auto cur = maxCount[i];
            // cout << "curNum: " << cur.first << " count: " << cur.second << endl;
            long long selectAmount = min((long long)k, cur.second);
            ans =  (ans * power(cur.first, selectAmount, MOD)) % MOD;
            cout << selectAmount << endl;
            k -= selectAmount;
            // cout << ans << endl;
            // cout << k << endl;
            if(k == 0) break;
        }
        // for(int i = 0; i < nums.size(); i ++) {
        //     for(int j = 0; j < i; j ++)  
        // }
        // for(int i = 0)
        // cout << getPrimeScore(300) << endl;
        // cout << 22011 * 14858 
        return ans;
    }
    long long power(long long base, long long exponent, int MOD) {
        long long res = 1;

        // Calculate the exponentiation using binary exponentiation
        while (exponent > 0) {
            // If the exponent is odd, multiply the result by the base
            if (exponent % 2 == 1) {
                res = ((res * base) % MOD);
            }

            // Square the base and halve the exponent
            base = (base * base) % MOD;
            exponent /= 2;
        }

        return res;
    }

};