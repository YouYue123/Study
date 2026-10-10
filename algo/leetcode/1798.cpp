#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int getMaximumConsecutive(vector<int>& coins) {
            int cur_max = 1;
            sort(coins.begin(), coins.end());
            for(int coin : coins) {
                if(coin <= cur_max) {
                    cur_max += coin;
                } else {
                    break;
                }
            }
            return cur_max;
        }
    };