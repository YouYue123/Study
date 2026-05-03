// 1514. Path with Maximum Probability [M]
// LeetCode path-with-maximum-probability

class Solution {
public:
    struct State {
        int index;
        double prob;
        State(int _index, double _prob): index(_index), prob(_prob) {}
        // bool operator>(State& other) {
        //     return prob > other.prob;
        // }
        bool operator<(const State& other) const {
            return prob < other.prob;
        }
    };
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> graph(n);
        for(int i = 0; i < edges.size(); i ++) {
            int from = edges[i][0], to = edges[i][1];
            double prob = succProb[i];
            graph[to].push_back({ from, prob });
            graph[from].push_back({ to, prob });
        }
        vector<double> distTo(n, DBL_MIN);
        distTo[start_node] = 1.0;
        priority_queue<State> pq;
        pq.push(State(start_node, 1.0));
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            // cout << "curIndex: " << cur.index << endl;
            // cout << cur.prob << endl;
            if(cur.index == end_node) return cur.prob;
            for(auto& next : graph[cur.index]) {
                // cout << next.second  << endl;
                double nextProb = next.second * cur.prob;
                int nextIndex = next.first;
                // cout << "next: " << nextIndex << " " << nextProb << endl;
                if(distTo[nextIndex] < nextProb) {
                    distTo[nextIndex] = nextProb;
                    pq.push(State(nextIndex, nextProb ));
                }
            }
        }
        return distTo[end_node];
    }
};