#include <bits/stdc++.h>
using namespace std;

// 1311. Get Watched Videos by Your Friends [M]
// LeetCode get-watched-videos-by-your-friends

struct Node {
    int id;
    int level;
};
struct Video {
    string name;
    int freq;
};
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = watchedVideos.size();
        vector g(n, vector<int>());
        for(int i = 0; i < n; i ++) {
            for(int f : friends[i]) {
                g[i].push_back(f);
                g[f].push_back(i);
            }
        }
        vector visit(n, false);
        queue<Node> q;
        q.emplace(id, 0);
        visit[id] = true;
        vector<int> matched_friend_ids;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            for(int nxt_id : g[cur.id]) {
                if(visit[nxt_id]) continue;
                visit[nxt_id] = true;
                int nxt_level = cur.level + 1;
                if(nxt_level == level) {
                    matched_friend_ids.push_back(nxt_id);
                } else {
                    q.emplace(nxt_id, nxt_level);
                }
            }
        }
        unordered_map<string, int> freq;
        for(int id : matched_friend_ids) {
            // cout << id << " ";
            for(string& video : watchedVideos[id]) {
                freq[video] += 1;
            }
        }
        vector<Video> videos;
        for(auto& [name, f] : freq) {
            videos.emplace_back(name, f);
        }
        sort(videos.begin(), videos.end(), [&] (auto& a, auto& b) {
            if(a.freq == b.freq) return a.name < b.name;
            return a.freq < b.freq;
        });
        vector<string> ans;
        for(auto& video : videos) {
            ans.push_back(video.name);
        }
        return ans;
    }
};