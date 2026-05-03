// 1472. Design Browser History [M]
// LeetCode design-browser-history

class BrowserHistory {
public:
    stack<string> st;
    stack<string> fSt;
    BrowserHistory(string homepage) {
        st.push(homepage);
    }
    
    void visit(string url) {
        while(!fSt.empty()) fSt.pop();
        st.push(url);
    }
    
    string back(int steps) {
        while(steps > 0 && st.size() > 1) {
            fSt.push(st.top());
            st.pop();
            steps -= 1;
        }
        // fst.push(st.top());
        return st.top();
    }
    
    string forward(int steps) {
        while(steps > 0 && !fSt.empty()) {
            st.push(fSt.top());
            fSt.pop();
            steps -= 1;
        }
        return st.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */