// 911. Online Election [M]
// LeetCode online-election

#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class TopVotedCandidate {
private:
    // 存储时间点 t 对应的领先者 id：{time, leaderId}
    // 使用 map 是为了方便使用 lower_bound 进行二分查找
    map<int, int> timeToLeader;

public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> voteCount; // id -> 票数
        int curLeader = -1;
        int maxVotes = 0;

        for (int i = 0; i < persons.size(); ++i) {
            int p = persons[i];
            int t = times[i];

            // 更新当前人的票数
            voteCount[p]++;

            // 如果当前人的票数 >= 当前最高票数（注意是 >=，处理平局逻辑）
            // 则该人成为当前时间点的领先者
            if (voteCount[p] >= maxVotes) {
                maxVotes = voteCount[p];
                curLeader = p;
            }
            
            // 记录该时间点的领先者
            timeToLeader[t] = curLeader;
        }
    }
    
    int q(int t) {
        // upper_bound 返回第一个 > t 的迭代器
        // prev 获取到的就是第一个 <= t 的迭代器
        auto it = timeToLeader.upper_bound(t);
        return prev(it)->second;
    }
};