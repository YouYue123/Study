# 🏆 CP Ability Profile

<!-- Auto-generated weekly. Last updated: 2026-05-31 20:00 SGT -->

## 📊 Stats Overview

| Metric | Value |
|--------|-------|
| **LeetCode** | 1643 solved · Guardian ~2262 |
| **Codeforces** | 135 solved · youyue · Specialist 1423 (max) |
| **Difficulty (LC)** | 🟢 Easy 311 · 🟡 Medium 939 · 🔴 Hard 362 · ❓ Unknown 31 |

### Weekly Activity (May 24–30, 2026)

| Platform | New Solutions |
|----------|:------------:|
| LeetCode | 17 (see below for problem list) |
| Codeforces | 22 (CF 2232 A–D · CF 1398 A–C · CF 1486 A–B · CF 1324D · CF 1520E · CF 1526C · CF 1195C · CF 2A · CF 371C · CF 479C · CF 545C · CF 550C · CF 580 A–B · CF 698A) |
| **Total** | **39** |

### Difficulty Breakdown

```
🟢 Easy:   █████████████████████░░░░░░░░░░  19%
🟡 Medium: ████████████████████████████████░  57%
🔴 Hard:   ████████████████████░░░░░░░░░░░░  22%
❓ Unknown: ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░   2%
```

## 🧠 Topic Strengths

### 🟢 Strong (core competency)

| Topic | Recent Problems |
|-------|----------------|
| **String / Rolling Hash / Trie / KMP** | **Massive string week** — LC 1044 (Longest Duplicate Substring, H, Rolling Hash+BS), LC 1062 (Longest Repeating Substring, M, DP+Hash), LC 1147 (Longest Chunked Palindrome, H, Greedy+TwoPtr), LC 1316 (Distinct Echo Substrings, H, Rolling Hash), LC 1698 (Count Distinct Substrings, M, Trie), LC 1923 (Longest Common Subpath, H, Rolling Hash+BS), LC 3093 (Longest Common Suffix Queries, H, Trie), LC 3934 (Smallest Unique Subarray, H, Rolling Hash) · CF 550C (Divisibility by 8, DP on digits) · Prev: LC 28 (strStr), LC 214 (Shortest Palindrome), LC 1397 (DP+KMP), CF 126B (Password), CF 182D (Common Divisors) |
| **Dynamic Programming** | CF 1195C (Basketball Exercise, two-row DP), CF 698A (Vacations, simple state DP), CF 1526C (Potions, Greedy+PQ) · Prev: LC 1397 (digit DP+KMP), LC 790 (domino tiling), LC 975 (DP+monotonic), LC 996 (bitmask), CF 2225C (grid DP), CF 2218G (combinatorial DP), CF 2228E (combinatorial DP+segment tree), CF 455A (Boredom), CF 489C (Given Length) |
| **Combinatorics / Number Theory** | CF 1398C (Good Subarrays, prefix sum + combinatorics) · Prev: LC 1735 (stars-and-bars), CF 1284C (combinatorics), CF 182D (GCD), CF 1407B (Big Vova), CF 2218D (OEIS), CF 2228D (Fenwick counting), CF 1526B (I Hate 1111) |

### 🟡 Good (comfortable)

| Topic | Recent Problems |
|-------|----------------|
| **Graph / Tree** | CF 580A (Kefa and First Steps — longest non-decreasing subsegment) · Prev: LC 1368 (Dijkstra), CF 2218F (tree construction), CF 580C (Kefa and Park — DFS), CF 520B (Two Buttons — BFS) |
| **Data Structures** | LC 3161 (Block Placement Queries, H, Segment Tree), LC 3691 (Max Total Subarray Value II, H, Segment Tree+Heap) · Prev: LC 990 (Union Find), CF 2226C (multiset), CF 2228D (Fenwick), CF 276C (frequency + sort), CF 1904C (two pointers) |
| **Greedy / Constructive** | LC 1402 (Reducing Dishes, M, sorting+greedy), LC 1703 (Min Adjacent Swaps for K Consecutive Ones, H, greedy+prefix sum) · CF 2232A (Group calls, greedy min), CF 2232B (Cake frosting levelling, prefix max), CF 2232C (Spectral Cup constructives), CF 2232D (Magical cake moving, constructive) · CF 1398A (Bad Triangle, trivial), CF 1398B (Substring Removal Game, greedy), CF 1486A (Shifting Stacks, greedy), CF 1520E (Arranging The Sheep, greedy+prefix), CF 545C (Woodcutters, greedy), CF 479C (Exams, sorting+greedy) · Prev: many from Div4 and recent rounds |
| **Math / Geometry** | LC 296 (Best Meeting Point, H, Manhattan median), LC 462 (Min Moves to Equal Array Elements II, M, median), CF 1486B (Eastern Exhibition, median in 2D) · Prev: CF 1407B (GCD), CF 2218D (distinct GCD) |
| **Two Pointers / Binary Search** | CF 1324D (Pair of Topics, two pointers), CF 580B (Kefa and Company, two pointers+sort), CF 371C (Hamburgers, binary search) · Prev: CF 279B (Books), CF 1904C (Array Game) |
| **Bit Manipulation / State Search** | LC 1521 (Mysterious Function Closest to Target, H, bitwise AND + set), LC 2932 (Max Strong Pair XOR I, E, XOR brute force), LC 3171 (Subarray OR Closest to K, H, sliding window+bit counts) · Prev: LC 1284 (bitmask BFS), CF 2218E (XOR) |
| **Game Theory** | CF 1398B (Substring Removal Game, 1s deletion game) · Prev: CF 2228B (Remilia, pursuit-evasion on circle) |
| **Interactive** | — · Prev: CF 1407C (Chocolate Bunny) |

### ⬜ Gap Areas (needs practice)

| Topic | Notes |
|-------|-------|
| Segment Tree / Fenwick Tree | Getting more exposure: LC 3161 (Block Placement Queries), LC 3691 (Max Total Subarray Value II) — still fresh territory |
| Tree DP / LCA | — |
| Suffix Array / Automaton | Strong rolling hash foundations — suffix array is the natural next step for string problems |
| Flow / Matching | — |
| Geometry | — |
| Interactive Problems | — |
| CF Div2 D+ | Current rating 1423 suggests ABC ceiling |

## 💻 Coding Style

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Lambda recursion
auto dfs = [&](this auto&& dfs, int i, int p) -> ll {
    // ...
    return dfs(i + 1, next_p);
};

// Modular math
const int MOD = 1e9 + 7;
#define mod_add(a, b) ((a + b) % MOD)
#define mod_mul(a, b) ((a * 1LL * b) % MOD)
```

- **C++17** · `bits/stdc++.h` · lambda recursion (`this auto&&`)
- **Dijkstra**: `priority_queue<Coord, vector<Coord>, greater<>>`
- **Graph representations**: adjacency list with inline construction
- **Pattern**: nested lambdas for KMP (`get_lps`, `get_next_p`), DP memoization with `vector(n, vector(m, ...))`

---

## 📈 Progress History

<!-- Each week, the cron job appends a new row -->

| Week | LC New | CF New | Total | Notes |
|------|:------:|:------:|:-----:|-------|
| May 24–30, 2026 | 17 | 22 | 39 | 🔥 **String week**: 8 string problems (LC 1044, 1062, 1147, 1316, 1698, 1923, 3093, 3934 — Rolling Hash / Trie / Suffix focus) · Segment Tree intro (LC 3161, 3691) · Bit manipulation (LC 1521, 2932, 3171) · Spectral Cup round (CF 2232 A–D) · CF classics: 1398 A–C, 1486 A–B, 371C, 479C, 545C, 550C, 580 A–B, 698A, 1195C, 1324D, 1520E, 1526C, 2A |
| May 17–23, 2026 | 1 | 15 | 16 | LC 1284 (Hard, bitmask BFS) · CF Div4 1003 sweep (2230 A–D) · DP week: 455A, 489C, 1526B, 2230D · Tree/Graph: 580C, 520B · Two pointers: 279B, 1904C |
| May 10–16, 2026 | 0 | 16 | 16 | Div. 4 contest sweep (2218 A–G) · Touhou round (2228 A–E) · interactive + GCD + XOR focus |
| May 3–9, 2026 | 8 | 13 | 21 | KMP focus week · bulk import of 1618 LC files |

---

*Generated by `~/.hermes/scripts/cp-profile-scan.py` · Updates weekly via cron*
