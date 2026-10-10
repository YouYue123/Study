#include <bits/stdc++.h>
using namespace std;

// 1352. Product of the Last K Numbers [M]
// LeetCode product-of-the-last-k-numbers

class ProductOfNumbers {
private:
    vector<int> precul;
public:
    ProductOfNumbers() {
        precul.push_back(1);
    }
    
    void add(int num) {
        if(num == 0) {
            precul.clear();
            precul.push_back(1);
            return;
        }
        return precul.push_back(precul.back() * num);
    }
    
    int getProduct(int k) {
        int n = precul.size();
        if(n - 1 - k < 0) return 0;
        return precul[n - 1] / precul[n - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */