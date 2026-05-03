// 860. Lemonade Change [E]
// LeetCode lemonade-change

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int changes[3] = {0};
        for(auto bill : bills) {
            if(bill == 5) {
                changes[0] += 1;
            } else if(bill == 10) {
                if(changes[0] == 0) return false;
                changes[0] -= 1;
                changes[1] += 1;
            } else if(bill == 20) {
                // cout << changes[0] << " " << changes[1] << endl;
                bool is_valid = false;
                if(changes[1] >= 1 && changes[0] >= 1) {
                    changes[1] -= 1;
                    changes[0] -= 1;
                    is_valid = true;
                } else if(changes[0] >= 3){
                    changes[0] -= 3;
                    is_valid = true;
                }
                if(!is_valid) return false;
            }
        }
        return true;
    }
};