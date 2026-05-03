// 1090. Largest Values From Labels [M]
// LeetCode largest-values-from-labels

struct Item {
    int val;
    int label;
    Item(int _val, int _label): val(_val), label(_label) {}
    
    bool operator<(const Item& other) {
        return val < other.val;
    }
    bool operator>(const Item& other) {
        return val > other.val;
    }
};
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<Item> items;
        for(int i = 0; i < values.size(); i ++) {
            items.push_back(Item(values[i], labels[i]));
        }
        sort(items.begin(), items.end(), greater<>());
        unordered_map<int, int> dict;
        int count = 0;
        int ans = 0;
        for(auto& item : items) {
            if(dict[item.label] < useLimit) {
                dict[item.label] += 1;
                count += 1;
                ans += item.val;
            }
            if(count == numWanted) return ans;
        }
        return ans;
    }
};