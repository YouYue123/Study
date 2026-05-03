#include <bits/stdc++.h>
using namespace std;

// 2126. Destroying Asteroids [M]
// LeetCode destroying-asteroids

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long curMass = mass;
        sort(asteroids.begin(), asteroids.end());
        for(int i = 0; i < asteroids.size(); i ++) {
            if(curMass >= asteroids[i]) curMass += asteroids[i];
            else return false;
        } 
        
        return true;
    }
};