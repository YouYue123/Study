// 1381. Design a Stack With Increment Operation [M]
// LeetCode design-a-stack-with-increment-operation

class CustomStack {
public:
    deque<int> st;
    int maxSize;
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(st.size() < maxSize) {
            st.push_back(x);
        }
    }
    
    int pop() {
        if(!st.empty()) {
            int cur = st.back();
            st.pop_back();
            return cur;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < k && i < st.size(); i ++) {
            st[i] += val;
        }
     }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */