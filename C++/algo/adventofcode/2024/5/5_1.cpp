#include <bits/stdc++.h>
using namespace std;

const string TARGET_WORD = "XMAS"; 
const int WORD_LENGTH = TARGET_WORD.length();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> g;
    string line;
    vector<int> nums;
    unordered_map<int, vector<int>> edges;
    vector<vector<int>> updates;
    unordered_map<int, unordered_set<int>> deps;
    while(getline(cin, line)) {
        if(line[2] == '|') {
            int a = stoi(line.substr(0, 2));
            int b = stoi(line.substr(3, 2));
            nums.push_back(a);
            nums.push_back(b);
            deps[b].insert(a);
        } else if(line.find(',') != string::npos) {
            stringstream ss(line);
            string num;
            vector<int> update;
            while(getline(ss, num, ',')) update.push_back(stoi(num));
            updates.push_back(update);
        }
    };
    sort(nums.begin(), nums.end());
    auto last = std::unique(nums.begin(), nums.end());
    nums.erase(last, nums.end());
    cout << "nums: ";
    for(int num : nums) cout << num << " ";
    cout << endl;
    for(auto& [key, e] : edges) {
        cout << key << " -> ";
        for(int nx : e) cout << nx << " ";
        cout << endl;
    }
    // for(int num : nums) {
    //     vector<bool> visited(1000, false);
    //     auto dfs = [&] (this auto&& dfs, int x) {
    //         // cout << "dfs(" << x << ")" << endl;
    //         if(visited[x]) return;
    //         visited[x] = true;
    //         for(int nx : edges[x]) {
    //             deps[num].insert(nx);
    //             dfs(nx);
    //         }
    //     };
    //     // cout << "starting dfs from " << num << endl;
    //     dfs(num);
    // }
    // cout << "deps: " << deps.size() << endl;
    for(auto [num, deps] : deps) {
        cout << num << " must be after: ";
        for(auto dep : deps) cout << dep << " ";
        cout << endl;
    }
    int ans = 0;
    for(auto& update : updates) {
       bool isValid = true;
       for(int i = 0; i < update.size(); i++) {
         for(int j = 0; j < i; j ++) {
            if(deps[update[j]].find(update[i]) != deps[update[j]].end()) {                
                isValid = false;
                break;
            }
         }
       }
       if(isValid) {
           // get the middle number
           int middle = update[update.size() / 2];
           ans += middle;
       }
       cout << "update: ";
       for(int num : update) cout << num << " ";
       cout << " is " << (isValid ? "valid" : "invalid") << endl;
    }
    cout << "ans: " << ans << endl;
}