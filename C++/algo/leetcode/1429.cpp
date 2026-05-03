// 1429. First Unique Number [M]
// LeetCode first-unique-number

class FirstUnique {
public:
    queue<int> q;
    unordered_map<int, int> dict;
    FirstUnique(vector<int>& nums) {
        for(int num : nums) {
            q.push(num);
            dict[num] += 1;
        }
        while(!q.empty()) {
            if(dict[q.front()] == 1) break;
            else q.pop();
        }
    }
    
    int showFirstUnique() {
        return q.empty() ? -1 : q.front();
    }
    
    void add(int value) {
        q.push(value);
        dict[value] += 1;
        while(!q.empty() && dict[q.front()] > 1) {
            q.pop();
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */