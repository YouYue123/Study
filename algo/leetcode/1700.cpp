#include <bits/stdc++.h>
using namespace std;

// 1700. Number of Students Unable to Eat Lunch [E]
// LeetCode number-of-students-unable-to-eat-lunch

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = sandwiches.size();
        unordered_map<int, int> dict;
        for(int s : students) dict[s] += 1;
        for(int i = 0; i < n; i ++) {
            int s = sandwiches[i];
            if(dict[s] > 0) dict[s] -= 1;
            else {
                return n - i;
            }
        }
        return 0;
    }
};