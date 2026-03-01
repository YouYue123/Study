#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>

using namespace std;

using pii = pair<int, int>;

class Excel {
private:
    int H, W;
    vector<vector<int>> vals;
    // formulas[destIdx] 存储该格引用的所有 {srcIdx : 出现次数}
    unordered_map<int, map<int, int>> formulas;
    // deps[srcIdx] 存储所有引用了 srcIdx 的单元格，用于环检测
    unordered_map<int, unordered_set<int>> deps;
    // 用于单向 get 查询的缓存
    unordered_map<int, int> memo;

    int getIdx(int r, char c) { return (r - 1) * 26 + (c - 'A'); }

    // 环检测：判断从 curr 开始是否能回到自己
    bool hasCycle(int curr) {
        unordered_map<int, int> visit;
        auto dfs = [&] (this auto&& dfs, int idx) {
            if(visit[idx] == 1) return true;
            if(visit[idx] == 2) return false;
            visit[idx] = 1;
            for(int nxt : deps[idx]) {
                if(dfs(nxt)) return true;
            }
            visit[idx] = 2;
            return false;
        };
        return dfs(curr);
    }

    int getWithMemo(int idx) {
        if (memo.count(idx)) return memo[idx];

        int res = 0;
        if (formulas.count(idx)) {
            for (auto const& [srcIdx, cnt] : formulas[idx]) {
                res += getWithMemo(srcIdx) * cnt;
            }
        } else {
            res = vals[idx / 26 + 1][idx % 26];
        }
        return memo[idx] = res;
    }

public:
    Excel(int height, char width) {
        H = height;
        W = width - 'A' + 1;
        vals.assign(H + 1, vector<int>(W, 0));
    }

    void set(int row, char column, int val) {
        int idx = getIdx(row, column);
        clearFormula(idx);
        vals[row][column - 'A'] = val;
    }

    void clearFormula(int idx) {
        if (formulas.count(idx)) {
            for (auto const& [srcIdx, cnt] : formulas[idx]) {
                deps[srcIdx].erase(idx);
            }
            formulas.erase(idx);
        }
    }

    int get(int row, char column) {
        memo.clear(); // 每次主入口调用都清空缓存，确保数据实时
        return getWithMemo(getIdx(row, column));
    }

    int sum(int row, char column, vector<string> numbers) {
        int destIdx = getIdx(row, column);
        clearFormula(destIdx);

        map<int, int> newFormula;
        for (const string& s : numbers) {
            size_t pos = s.find(':');
            if (pos == string::npos) {
                newFormula[parseIdx(s)]++;
            } else {
                int start = parseIdx(s.substr(0, pos));
                int end = parseIdx(s.substr(pos + 1));
                int r1 = start / 26 + 1, c1 = start % 26;
                int r2 = end / 26 + 1, c2 = end % 26;
                for (int r = r1; r <= r2; ++r) {
                    for (int c = c1; c <= c2; ++c) {
                        newFormula[(r - 1) * 26 + c]++;
                    }
                }
            }
        }

        // 建立临时依赖关系进行环检测
        for (auto const& [srcIdx, cnt] : newFormula) {
            deps[srcIdx].insert(destIdx);
        }

        if (hasCycle(destIdx)) {
            // 如果检测到环，撤销依赖（根据 Excel 逻辑通常不允许成环）
            for (auto const& [srcIdx, cnt] : newFormula) {
                deps[srcIdx].erase(destIdx);
            }
            return 0; 
        }

        formulas[destIdx] = newFormula;
        return get(row, column);
    }

private:
    int parseIdx(string s) {
        return (stoi(s.substr(1)) - 1) * 26 + (s[0] - 'A');
    }
};