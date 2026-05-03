#include <bits/stdc++.h>
using namespace std;

// 975. Odd Even Jump [H]
// LeetCode odd-even-jump


class Solution {
public:
  
    void print(vector<pair<int,int>>&dp){
        for(int i=0;i<dp.size();i++){
        cout<<dp[i].first<<" "<<dp[i].second<<endl;
        }
    }

    void next(vector<pair<int,int>>&dp,vector<pair<int,int>>&v){
        stack<int>s;
        int n=v.size();
        for(int i=0;i<n;i++){
            while(!s.empty() && s.top()<v[i].second){
                dp[s.top()].second=v[i].second;
                s.pop();
            }
            s.push(v[i].second);
        }
        while(!s.empty()){
            dp[s.top()].second=-1;
            s.pop();
        }
    }
    int solve(bool odd,int index,vector<pair<int,int>>&dp){
            if(index==dp.size()-1)return 1;
            if(odd && dp[index].second==-1 || !odd && dp[index].first==-1)return 0;
            if(odd)return solve(!odd,dp[index].second,dp);
            return solve(!odd,dp[index].first,dp);
    }
    void small(vector<pair<int,int>>&dp,vector<pair<int,int>>&v){
        stack<int>s;
        int n=v.size();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top()<v[i].second ) {
                dp[s.top()].first=v[i].second;
                s.pop();
            }
                s.push(v[i].second);
        }
        while(!s.empty()){
            dp[s.top()].first=-1;
            s.pop();
        }
    }

    int oddEvenJumps(vector<int>& arr) {
        int n=arr.size();
        vector<pair<int,int>>v(n);
        vector<pair<int,int>>dp(n);
        
        for(int i=0;i<n;i++){
            v[i]={arr[i],i};
        }

        sort(v.begin(),v.end());
        next(dp,v);
        sort(v.begin(),v.end(),[](auto &a,auto &b){
            if(a.first==b.first)return a.second>b.second;
            return a.first<b.first;
        });
        small(dp,v);
        int count=0;
        bool odd;
        for(int i=0;i<n;i++){
            count+=solve(true,i,dp);
        }
        return count;
    }
};