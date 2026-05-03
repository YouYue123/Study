// 857. Minimum Cost to Hire K Workers [H]
// LeetCode minimum-cost-to-hire-k-workers

struct Worker {
    int quality;
    int wage;
    double ratio;
    Worker(int _q, int _w): quality(_q), wage(_w) {
        ratio = (double)wage / quality;
    };
    bool operator <(const Worker& other) const {
        return ratio < other.ratio;
    }
    bool operator >(const Worker& other) const {
        return ratio > other.ratio;
    }
};

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<Worker> workers;
        for(int i = 0; i < wage.size(); i ++) {
            workers.emplace_back(quality[i], wage[i]);
        }
        sort(workers.begin(), workers.end());
        double ans = DBL_MAX;
        int qualitySum = 0;
        priority_queue<int> pq;
        for(auto& worker : workers) {
            qualitySum += worker.quality;
            pq.push(worker.quality);
            if(pq.size() > k){
                // cout << pq.top() << endl;
                qualitySum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k) {
                ans = min(ans, qualitySum * worker.ratio);
            } 
        }
        return ans;
    }
};