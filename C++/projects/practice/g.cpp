#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// --- Func 1: 寻找在两个范围内都只出现一次的字符串 ---
// 返回一个 pair 的 vector，包含所有匹配的 {indexA, indexB}
vector<pair<int, int>> findUniqueIntersections(
    const vector<string>& A, int as, int ae, 
    const vector<string>& B, int bs, int be) {
    
    unordered_map<string, int> countA, countB;
    // 记录 index，如果重复则设为 -1
    for (int i = as; i <= ae; ++i) countA[A[i]] = (countA.count(A[i]) ? -1 : i);
    for (int i = bs; i <= be; ++i) countB[B[i]] = (countB.count(B[i]) ? -1 : i);

    vector<pair<int, int>> anchors;
    for (int i = as; i <= ae; ++i) {
        if (countA[A[i]] != -1 && countB.count(A[i]) && countB[A[i]] != -1) {
            anchors.push_back({countA[A[i]], countB[A[i]]});
        }
    }
    return anchors;
}

// --- Func 2: 剥离前后缀 ---
// 返回值：{prefixLength, suffixLength}
pair<int, int> getChunkOffCounts(
    const vector<string>& A, int as, int ae, 
    const vector<string>& B, int bs, int be) {
    
    int p = 0;
    while (as + p <= ae && bs + p <= be && A[as + p] == B[bs + p]) {
        p++;
    }
    
    int s = 0;
    while (ae - s >= as + p && be - s >= bs + p && A[ae - s] == B[be - s]) {
        s++;
    }
    return {p, s};
}

// --- Func 3: 递归 Diff 主逻辑 ---
void solveDiff(const vector<string>& A, int as, int ae, const vector<string>& B, int bs, int be) {
    if (as > ae && bs > be) return;

    // 1. 调用 Func 2 剥离前后缀
    auto [pLen, sLen] = getChunkOffCounts(A, as, ae, B, bs, be);
    
    // 输出前缀 (不变的部分)
    for (int i = 0; i < pLen; ++i) cout << "  " << A[as + i] << endl;

    // 更新中间部分的边界
    int midAs = as + pLen, midAe = ae - sLen;
    int midBs = bs + pLen, midBe = be - sLen;

    if (midAs <= midAe || midBs <= midBe) {
        // 2. 调用 Func 1 寻找锚点
        vector<pair<int, int>> anchors = findUniqueIntersections(A, midAs, midAe, B, midBs, midBe);
        
        if (!anchors.empty()) {
            // 策略：取第一个唯一元素作为锚点
            auto [idxA, idxB] = anchors[0];
            // 递归左边
            solveDiff(A, midAs, idxA - 1, B, midBs, idxB - 1);
            // 输出锚点本身
            cout << "  " << A[idxA] << endl;
            // 递归右边
            solveDiff(A, idxA + 1, midAe, B, idxB + 1, midBe);
        } else {
            // 实在找不到锚点，说明这块区域完全不 match
            for (int i = midAs; i <= midAe; ++i) cout << "-" << A[i] << endl;
            for (int i = midBs; i <= midBe; ++i) cout << "+" << B[i] << endl;
        }
    }

    // 输出后缀 (不变的部分)
    for (int i = sLen - 1; i >= 0; --i) cout << "  " << A[ae - i] << endl;
}