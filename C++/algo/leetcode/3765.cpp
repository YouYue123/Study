// 3765. Complete Prime Number [M]
// LeetCode complete-prime-number

const int MAX_N = 1e6;
bool isComposite[MAX_N + 1];
void sieve () {
    isComposite[1] = true;
    for(int p = 2; p * p <= MAX_N; p ++) {
        if(!isComposite[p]) {
            for(int mul = p * p; mul <= MAX_N; mul += p) isComposite[mul] = true;
        }
    }
}
class Solution {
public:
    bool completePrime(int num) {
        if(isComposite[3] == false) sieve();
        string preS = "", sufS = "";
        string numS = to_string(num);
        int n = numS.size();

        for(int i = 0; i < n; i ++) {
            preS += numS[i]; 
            sufS = numS[n - 1 - i] + sufS;
            // cout << preS << " " << sufS << endl;
            // cout << isComposite[stoi(preS)] << " " << isComposite[stoi(sufS)] << endl;
            if(isComposite[stoi(preS)] || isComposite[stoi(sufS)]) return false;
        }
        return true;
    }
};