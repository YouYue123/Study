// 895. Maximum Frequency Stack [H]
// LeetCode maximum-frequency-stack

class FreqStack {
public:
    unordered_map<int, int> valToFreq;
    vector<stack<int>> sts;
    FreqStack() {
        
    }
    
    void push(int val) {
        if(sts.size() == valToFreq[val]) {
            sts.push_back({});
        }
        sts[valToFreq[val]].push(val);
        valToFreq[val] += 1;
    }
    
    int pop() {
        int val = sts.back().top();
        sts.back().pop();
        if(sts.back().empty()) {
            sts.pop_back();
        }
        valToFreq[val] -= 1;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */