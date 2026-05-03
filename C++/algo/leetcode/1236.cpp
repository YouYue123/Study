#include <bits/stdc++.h>
using namespace std;

// 1236. Web Crawler [M]
// LeetCode web-crawler

/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    string getHostName(string temp){
        int pos = min(temp.size(), temp.find('/',7));
        return temp.substr(7, pos-7);
    }
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        queue<string> q;
        q.push(startUrl);
        unordered_set<string> visited{startUrl};
        string hostname = getHostName(startUrl);
        while(!q.empty()){
            string f = q.front();
            q.pop();
            for(string nextUrl : htmlParser.getUrls(f)){
                if(getHostName(nextUrl) == hostname && !visited.count(nextUrl)){
                    q.push(nextUrl);
                    visited.insert(nextUrl);
                }
            }
        }
        return vector<string>(visited.begin(), visited.end());
    }
};