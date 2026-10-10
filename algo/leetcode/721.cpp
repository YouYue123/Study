#include <bits/stdc++.h>
using namespace std;

// 721. Accounts Merge [M]
// LeetCode accounts-merge

class Account {
public:
    string name;
    set<string> emails;
    Account() {
        this->name = "";
        this->emails.clear();
    }
    Account(vector<string>& account) {
        this->name = account[0];
        this->emails = set(account.begin() + 1, account.end());
    }
};

class UF {
public:
    int count;
    vector<int> parent;
    UF(int n) {
        count = n;
        parent.resize(n);
        for(int i = 0; i < n; i ++) parent[i] = i;
    }
    void union_(int p, int q) {
        int rootP = findRoot(p);
        int rootQ = findRoot(q);
        if(rootP == rootQ) return;
        parent[rootP] = rootQ;
    }
    int findRoot(int x) {
        if(parent[x] == x) return x;
        int root = findRoot(parent[x]);
        parent[x] = root;
        return root;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        auto uf = UF(accounts.size());
        vector<Account> accs;
        for(vector<string>& acc : accounts) {
            accs.push_back(Account(acc));
        }

        for(int i = 0; i< accounts.size(); i ++) {
            for(int j = i + 1; j < accounts.size(); j  ++) {
                auto& acc1 = accs[i];
                auto& acc2 = accs[j];
                for(string email: acc1.emails) {
                    if(acc2.emails.contains(email)) uf.union_(i, j);
                }
            }
        }
        vector<Account> ans(uf.count, Account());
        for(int i = 0; i < accounts.size() ; i ++) {
            int root = uf.findRoot(i);
            // cout << root << endl;
            if(ans[root].name.empty()) {
                ans[root].name = accs[i].name;
            }
            for(string email : accs[i].emails) {
                ans[root].emails.insert(email);
            }
        }
        vector<vector<string>> result;
        for(int i = 0; i < ans.size(); i ++) {
            if(ans[i].name.empty()) continue;
            // cout << "i: " << i << endl;
            // cout << "name: " << ans[i].name << endl;
            vector<string> temp;
            temp.push_back(ans[i].name);
            // cout << "emails" << endl;
            for(string email: ans[i].emails) {
                cout << email << endl;
                temp.push_back(email);
            }
            result.push_back(temp);
            // for(int j = 0; j < ans[i].size(); j ++) {
            //     cout << ans[i][j].name << endl;
            // }
        }
        return result;
    }
};