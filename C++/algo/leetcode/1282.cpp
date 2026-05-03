// 1282. Group the People Given the Group Size They Belong To [M]
// LeetCode group-the-people-given-the-group-size-they-belong-to

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> dict;
        for(int i = 0; i < groupSizes.size(); i ++) {
            int size = groupSizes[i];
            dict[size].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto& p : dict) {
            vector<int> temp;
            for(int num : p.second) {
                temp.push_back(num);
                if(temp.size() == p.first) {
                    ans.push_back(temp);
                    temp.clear();
                }
            }
        }
        return ans;
    }
};