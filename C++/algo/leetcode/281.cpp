#include <bits/stdc++.h>
using namespace std;

// 281. Zigzag Iterator [M]
// LeetCode zigzag-iterator

class ZigzagIterator {
private:
    vector<int> v1;
    vector<int> v2;
    int p1 = 0;
    int p2 = 0;
    int turn = 0;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2): v1(v1), v2(v2) {
        
    }

    int next() {
        int ans = 0;
        if(turn == 0) {
            if(p1 < v1.size()) {
                ans = v1[p1];
                p1 += 1;
            } else {
                ans = v2[p2];
                p2 += 1;
            }
        } else {
            if(p2 < v2.size()) {
                ans = v2[p2];
                p2 += 1;
            } else {
                ans = v1[p1];
                p1 += 1;
            }
        }
        turn = turn ^ 1;
        return ans;
    }

    bool hasNext() {
        if(p1 == v1.size() && p2 == v2.size()) return false;
        return true;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */