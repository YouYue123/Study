#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

bool is_safe(const vector<int>& levels) {
    if (levels.size() < 2) {
        return true; 
    }

    bool increasing;
    
    int trend_start_index = -1;
    for (size_t i = 1; i < levels.size(); ++i) {
        if (levels[i] != levels[i - 1]) {
            trend_start_index = i;
            break;
        }
    }

    if (trend_start_index == -1) {
        return false;
    }

    increasing = (levels[trend_start_index] > levels[trend_start_index - 1]);

    for (size_t i = 1; i < levels.size(); ++i) {
        int diff = levels[i] - levels[i - 1];
        int abs_diff = abs(diff);

        if (abs_diff < 1 || abs_diff > 3) {
            return false;
        }

        if (increasing) {
            if (diff <= 0) return false;
        } else {
            if (diff >= 0) return false;
        }
    }

    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int total_safe_reports = 0;
    string line;
    
    while(getline(cin, line)) {
        stringstream ss(line);
        int num;
        vector<int> original_row;
        while(ss >> num) original_row.push_back(num);

        if (original_row.empty()) continue;

        if (is_safe(original_row)) {
            total_safe_reports++;
            continue;
        }

        bool is_safe_with_dampener = false;
        
        for(size_t i = 0; i < original_row.size(); ++i) {
            vector<int> modified_row;
            for(size_t j = 0; j < original_row.size(); ++j) {
                if (i != j) {
                    modified_row.push_back(original_row[j]);
                }
            }

            if (is_safe(modified_row)) {
                is_safe_with_dampener = true;
                break;
            }
        }

        if (is_safe_with_dampener) {
            total_safe_reports++;
        }
    }
    
    cout << total_safe_reports << endl;
    
    return 0;
}