#include <bits/stdc++.h>
using namespace std;

// 2349. Design a Number Container System [M]
// LeetCode design-a-number-container-system

class NumberContainers {
public:
    unordered_map<int, int> index2Number;
    unordered_map<int, set<int>> number2Indices;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        // The index has been set before
        if(index2Number.contains(index)) {
            int preNum = index2Number[index];
            // cout << preNum << endl;
            number2Indices[preNum].erase(index);
            if(number2Indices[preNum].empty()) {
                number2Indices.erase(preNum);
            }
        }
        index2Number[index] = number;
        number2Indices[number].insert(index);
    }
    
    int find(int number) {
        if(number2Indices.contains(number)) {
            return *number2Indices[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */