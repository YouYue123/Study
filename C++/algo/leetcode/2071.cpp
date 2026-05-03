// 2071. Maximum Number of Tasks You Can Assign [H]
// LeetCode maximum-number-of-tasks-you-can-assign

class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        auto isValid = [&] (int mid) {
            int j = workers.size() - 1;
            deque<int> dq;
            int p = pills;
            for(int i = mid - 1; i >=0; --i) {
                // cout << "task: " << tasks[i] << endl;
                while(j >= 0 && workers[j] + strength >= tasks[i]) {
                    dq.push_front(workers[j]);
                    j -= 1;
                }
                // cout << dq.size() << endl;
                if(dq.empty()) return false;
                else if(dq.back() >= tasks[i]) dq.pop_back();
                else {
                    if(p == 0) return false;
                    --p;
                    dq.pop_front();
                }
            }
            return true;
        };
        int left = 1, right = min(workers.size(), tasks.size()) + 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(!isValid(mid)) {
                // cout << mid << " not valid" << endl;
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left - 1;
    }
};