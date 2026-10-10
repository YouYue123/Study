#include <bits/stdc++.h>
using namespace std;

// 355. Design Twitter [M]
// LeetCode design-twitter

struct Tweet {
    int tweetId;
    int timestamp;
    bool operator > (const Tweet& other) const {
        return timestamp > other.timestamp;
    }
};
class Twitter {
private:
    int timestamp = 0;
    unordered_map<int, deque<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> ups;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(tweetId, timestamp);
        while(tweets[userId].size() > 10) tweets[userId].pop_front();
        timestamp += 1;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet, vector<Tweet>, greater<>> pq;
        auto addToPq = [&] (int curUserId) {
            for(auto& tweet : tweets[curUserId]) {
                pq.push(tweet);
            }
            while(pq.size() > 10) pq.pop();
        };
        addToPq(userId);
        for(int upUserId : ups[userId]) addToPq(upUserId);
        
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().tweetId);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        ups[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(!ups[followerId].contains(followeeId)) return;
        ups[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */