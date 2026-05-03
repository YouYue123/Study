// 2043. Simple Bank System [M]
// LeetCode simple-bank-system

class Bank {
public:
    unordered_map<long long, long long> accounts;
    int maxAccNo = 0;
    Bank(vector<long long>& balance) {
        for(int i = 0; i < balance.size(); i ++) {
            accounts[i + 1] = balance[i];
        }
        maxAccNo = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 > maxAccNo || account2 > maxAccNo) return false;
        if(accounts[account1] >= money) {
            accounts[account1] -= money;
            accounts[account2] += money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account > maxAccNo) return false;
        accounts[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account > maxAccNo) return false;
        if(accounts[account] >= money) {
            accounts[account] -= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */