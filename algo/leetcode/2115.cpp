#include <bits/stdc++.h>
using namespace std;

// 2115. Find All Possible Recipes from Given Supplies [M]
// LeetCode find-all-possible-recipes-from-given-supplies

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, bool> dict;
        for(string s : supplies) dict[s] = true;
        unordered_map<string, vector<string>> inToRGraph;
        unordered_map<string, vector<string>> rToInGraph;
        queue<string> q;
        vector<string> ans;
        for(int i = 0; i < recipes.size(); i ++) {
            string r = recipes[i];
            rToInGraph[r] = ingredients[i];
            for(string in : ingredients[i]) inToRGraph[in].push_back(r);
            if(isEligible(rToInGraph[r], dict)) q.push(r);
        }
        while(!q.empty()) {
            string cur = q.front();
            ans.push_back(cur);
            dict[cur] = true;
            q.pop();
            for(string r : inToRGraph[cur]) {
                if(isEligible(rToInGraph[r], dict)) q.push(r);
            }
        }
        return ans;
    }

    bool isEligible(vector<string> ins, unordered_map<string, bool> dict) {
        bool eligible = true;
        for(string in : ins) {
            if(!dict.contains(in)) {
                eligible = false;
                break;
            }
        }
        return eligible;
    }
};