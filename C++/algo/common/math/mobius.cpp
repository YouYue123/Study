#include <bits/stdc++.h>
using namespace std;

constexpr int MX = 100'001;
int mu[MX];
vector<int> divisors[MX];

int init = [] {
    mu[1] = 1;
    for (int i = 1; i < MX; i++) {
        for (int j = i * 2; j < MX; j += i) {
            mu[j] -= mu[i];
        }
    }
    for (int i = 1; i < MX; i++) {
        if (mu[i]) {
            for (int j = i; j < MX; j += i) {
                divisors[j].push_back(i);
            }
        }
    }
    return 0;
}();
