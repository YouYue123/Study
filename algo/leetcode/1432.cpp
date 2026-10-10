#include <bits/stdc++.h>
using namespace std;

// 1432. Max Difference You Can Get From Changing an Integer [M]
// LeetCode max-difference-you-can-get-from-changing-an-integer

class Solution {
public:
    int get(int num, char target) {
        string ans = "";
        string numS = to_string(num);
        unordered_map<char, char> dict;
        for(int i = 0; i <= 9; i ++) dict[i + '0'] = i + '0';
        bool mapped = false;
        unordered_set<int> set;
        for(int i = 0; i < numS.size(); i ++) {
            char c = numS[i];
            if(!mapped && c != target && !set.contains(c)) {
                if(i != 0 || target != '0') {
                    dict[c] = target;
                    mapped = true; 
                }
            }
            set.insert(c);
            // cout << c << " " << dict[c] << endl;
            ans += dict[c];
        }
        // cout << ans << endl;
        return stoi(ans);
    }
    int maxDiff(int num) {
        int maxVal = get(num, '9');
        int minVal = get(num, '0');
        int anotherMinVal = get(num, '1');
        // cout << minVal << " " << anotherMinVal << " " << maxVal << endl;
        return max(maxVal - minVal, maxVal - anotherMinVal);
    }
};