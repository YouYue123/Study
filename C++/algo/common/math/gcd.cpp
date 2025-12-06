#include <bits/stdc++.h>
using namespace std;
// https://oi-wiki.org/math/number-theory/gcd/
auto gcd_robust = [](int a, int b) {
    a = abs(a);
    b = abs(b);
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
};