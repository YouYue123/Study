// 1169. Invalid Transactions [M]
// LeetCode invalid-transactions

struct Transaction {
    string name;
    int time;
    int amount;
    string city;
    string origin;
};
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> ans;
        vector<Transaction> items;
        // { name: Transaction }
        unordered_map<string, vector<Transaction>> dict;
        for(string& t : transactions) {
            stringstream ss(t);
            string name, time_str, amount_str, city;
            getline(ss, name, ',');
            
            getline(ss, time_str, ',');
            getline(ss, amount_str, ',');
            getline(ss, city, ',');
            int amount = stoi(amount_str);
            int time = stoi(time_str);
            items.emplace_back(name, time, amount, city, t);
            dict[name].push_back(items.back());
        }
        for (auto& [name, txs] : dict) {
            sort(txs.begin(), txs.end(), 
                [](const Transaction& a, const Transaction& b) {
                return a.time < b.time;
            });
        }
        for(auto& item : items) {
            bool invalid = false;
            if(item.amount > 1000) {
                invalid = true;
            } else {
                if(dict.contains(item.name)) {
                    auto& txs = dict[item.name];
                    auto it_start = lower_bound(
                        txs.begin(), 
                        txs.end(), 
                        item.time - 60, 
                        [](const Transaction& t, int val) { return t.time < val; }
                    );
                    // 只需要在这个区间内检查 city
                    for (auto it = it_start; it != txs.end() && it->time <= item.time + 60; ++it) {
                        if (it->city != item.city) {
                            invalid = true;
                            break;
                        }
                    }
                }
            }
            if(invalid) ans.push_back(item.origin);
        }
        return ans;
    }
};