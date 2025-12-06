#include <bits/stdc++.h>
using namespace std;
// https://oi-wiki.org/math/number-theory/gcd/
auto gcd = [&] (int a, int b) {
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
};