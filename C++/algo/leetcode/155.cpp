// 155. Min Stack [M]
// LeetCode min-stack

class MinStack {
public:
    // {cur, min}
    stack<pair<int, int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            st.emplace(val, val);
        } else {
            st.emplace(val, min(getMin(), val));
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */