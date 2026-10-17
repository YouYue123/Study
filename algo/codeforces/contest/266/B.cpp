#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    string q;
    cin >> q;
    string newQ = "";
    for(int i = 0; i < t; i ++) {
        int j = 0;
        while(j < q.size()) {
            if(j < q.size() - 1 && q[j] == 'B' && q[j + 1] == 'G') {
                newQ += 'G';
                newQ += 'B';
                j += 2;
            } else {
                newQ += q[j];
                j += 1;
            }
        }
        q = newQ;
        newQ = "";
    }
    cout << q << endl;
}