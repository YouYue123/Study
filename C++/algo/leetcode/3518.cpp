#include <bits/stdc++.h>
using namespace std;

// 3518. Smallest Palindromic Rearrangement II [H]
// LeetCode smallest-palindromic-rearrangement-ii

//step 1: find the freq array 
//step 2: find the half freq array if there is any odd freq then store it in middle variable 
//step 3: check if k > total permutation possible, if yes then return ""
//step 4: take the char one by one and find the multinominal coef of remaining
//step 5: if coef >= k take that char else skip that 
//step 6: ans is left + middle + rev(left)
class Solution {
public:
    typedef long long ll;
    int maxK = 1e6 + 1;

    //this is same as nCk formula 
    // we know nCk is n! / (k! * (n - k)!)
    // can be written as (n * (n - 1) * (n - 2) * ....... * (n - k + 1)) / (1 * 2 * 3 * ..... * k) 
    ll binomial(int n, int k){
        if(k > n) return 0;
        if(k > n - k) k = n - k;

        ll res = 1;
        for(int i = 1; i <= k; i++){
            res = res * (n - i + 1) / i;
            if(res >= maxK) return maxK;
        }
        return res;
    }

    // multinomial is n! / (k1! * k2! * k3!)
    // can we written as nCk1 * (n - k1)Ck2 * (n - k1 - k2)Ck3
    ll multinomial(vector<int>& halfFreq){
        int total = accumulate(halfFreq.begin(), halfFreq.end(), 0);

        ll res = 1;
        for(int i = 0; i < 26; i++){
            int cnt = halfFreq[i];
            res *= binomial(total, cnt);
            if(res >= maxK) return maxK;
            total -= cnt;
        }

        return res;
    }
    string smallestPalindrome(string s, int k) {
        // step1 storing freq
        vector<int> freq(26, 0);
        for(char c : s){
            freq[c - 'a']++;
        }

        // step 2 storing half and findng middle 
        string left = "", middle = "";
        vector<int> halfFreq(26, 0);
        int halfLen = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] % 2 == 1){
                middle = i + 'a';
            }
            halfFreq[i] = freq[i] / 2;
            halfLen += halfFreq[i];
        }

        //step 3: checking if k > total permutation -> if yes then no ans -> return ""
        ll totalPermutation = multinomial(halfFreq);
        if(k > totalPermutation) return "";

        // step 4: take one char at a time
        for(int i = 0; i < halfLen; i++){
            for(int j = 0; j < 26; j++){
                if(halfFreq[j]){
                    halfFreq[j]--;
                    ll permutation = multinomial(halfFreq);

                    //step 5
                    if(permutation >= k){
                        left += (j + 'a');
                        break;
                    }
                    else{
                        k -= permutation;
                        halfFreq[j]++;
                    }
                }
            }
        }

        //step 6
        string right = left;
        reverse(right.begin(), right.end());
        return left + middle + right;
    }
};