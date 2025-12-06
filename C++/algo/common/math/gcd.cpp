#include <bits/stdc++.h>
using namespace std;

auto gcd = [&] (int a, int b) {
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
};