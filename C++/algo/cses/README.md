# CSES 题解索引

本目录每个文件对应一题：`{题号}.cpp`。官方题面见 [CSES Problem Set](https://cses.fi/problemset/)，单题链接形如 `https://cses.fi/problemset/task/{题号}/`。

下表概括**当前仓库实现**里的关键思路（以代码为准；个别题号在 CSES 上名称若变更，以官网为准）。

| 题号 | 题目（CSES 常用英文名） | 关键思路 | 代码 |
|:---:|:---|:---|:---:|
| 1068 | Weird Algorithm | 模拟 Collatz：偶数 /2，奇数 3n+1 直到 1 | [1068.cpp](1068.cpp) |
| 1069 | Repetitions | 扫描 DNA 串，维护当前连续字符长度取 max | [1069.cpp](1069.cpp) |
| 1070 | Permutations | 构造 1…n 排列（小 n 特判；双指针交错输出） | [1070.cpp](1070.cpp) |
| 1071 | Number Spiral | 按层/奇偶讨论，O(1) 求螺旋格值 | [1071.cpp](1071.cpp) |
| 1072 | Two Knights | 组合公式：总放法减去互相攻击（8 向马步） | [1072.cpp](1072.cpp) |
| 1073 | Towers | 耐心排序：`upper_bound` 维护递减塔堆数 = 最少塔数 | [1073.cpp](1073.cpp) |
| 1074 | Stick Lengths | 排序后取中位数，代价为各点到中位距离和 | [1074.cpp](1074.cpp) |
| 1083 | Missing Number | 1…n 和减输入和 | [1083.cpp](1083.cpp) |
| 1084 | Apartments | 排序 + 双指针匹配，差值 ≤ k | [1084.cpp](1084.cpp) |
| 1085 | Array Division | 二分「子段和上限」，贪心划段数是否 ≤ k | [1085.cpp](1085.cpp) |
| 1090 | Ferris Wheel | 排序 + 双指针，最重配最轻 | [1090.cpp](1090.cpp) |
| 1091 | Concert Tickets | `multiset` + `lower_bound` 为顾客找最小够用的票 | [1091.cpp](1091.cpp) |
| 1092 | Apple Division | 判断 n(n+1)/2 奇偶；双指针配对构造两集合和相等 | [1092.cpp](1092.cpp) |
| 1093 | Two Sets II | 判断总和奇偶；DP 计数划分到目标和 mod 1e9+7 | [1093.cpp](1093.cpp) |
| 1094 | Increasing Array | 维护前缀 max，不足则补差 | [1094.cpp](1094.cpp) |
| 1097 | Removal Game | 区间 minimax DP；答案 (sum + 先手优势)/2 | [1097.cpp](1097.cpp) |
| 1140 | Projects | 区间按 end 排序；DP + 二分上一个不交的区间 | [1140.cpp](1140.cpp) |
| 1141 | Playlist | 滑动窗口 + `unordered_map`（`safe_hash`）维护元素频次 | [1141.cpp](1141.cpp) |
| 1145 | Increasing Subsequence | `lower_bound` 耐心数组，O(n log n) LIS 长度 | [1145.cpp](1145.cpp) |
| 1158 | Book Shop | 0/1 背包：物品倒序遍历体积 | [1158.cpp](1158.cpp) |
| 1163 | Traffic Lights | `set` 维护灯位置 + `multiset` 维护段长，每次输出最大段 | [1163.cpp](1163.cpp) |
| 1164 | Room Allocation | 按开始排序；小根堆释放房间 / 分配新房间 | [1164.cpp](1164.cpp) |
| 1192 | Counting Rooms | 网格 DFS/BFS 数连通块 | [1192.cpp](1192.cpp) |
| 1193 | Labyrinth | BFS 最短路 + 父指针回溯输出方向串 | [1193.cpp](1193.cpp) |
| 1194 | Monsters | 怪物与玩家双源 BFS；边界格比较到达先后 | [1194.cpp](1194.cpp) |
| 1195 | Flight Routes Discount | 状态 Dijkstra：dist[v][0/1] 表示到 v 是否已用半价边 | [1195.cpp](1195.cpp) |
| 1196 | Flight Routes | 每个结点维护至多 k 条最短路代价（大根堆淘汰）；从 1 扩展 | [1196.cpp](1196.cpp) |
| 1197 | Cycle Finding | Bellman-Ford：n 轮松弛后仍可缩短则沿 parent 取负环 | [1197.cpp](1197.cpp) |
| 1617 | Bit Strings | 快速幂：2^n mod 1e9+7 | [1617.cpp](1617.cpp) |
| 1618 | Trailing Zeros | n! 中因子 5 的个数 | [1618.cpp](1618.cpp) |
| 1619 | Restaurant Customers | 事件扫描线，维护同时在场人数最大值 | [1619.cpp](1619.cpp) |
| 1620 | Factory Machines | 二分时间，检查各机器产量之和是否 ≥ t | [1620.cpp](1620.cpp) |
| 1621 | Distinct Numbers | 排序后数相邻不同元素个数 | [1621.cpp](1621.cpp) |
| 1622 | Creating Strings |  multiset 字母计数 + DFS 生成全排列 | [1622.cpp](1622.cpp) |
| 1623 | Apple Division | 子集枚举 / DFS 最小 |sum1−sum2| | [1623.cpp](1623.cpp) |
| 1624 | Chessboard and Queens | 8×8 皇后，DFS + 列/对角线剪枝 | [1624.cpp](1624.cpp) |
| 1625 | Grid Paths | `?` 路径 DFS + 剪枝（对称/曼哈顿下界） | [1625.cpp](1625.cpp) |
| 1629 | Movie Festival | 按结束时间贪心选不相交区间 | [1629.cpp](1629.cpp) |
| 1630 | Tasks and Deadlines | 按 duration 排序，最大化 Σ(deadline−完成时刻) | [1630.cpp](1630.cpp) |
| 1631 | Reading Books | 答案 max(总和, 2×最大单本) | [1631.cpp](1631.cpp) |
| 1632 | Movie Festival II |  multiset 维护 k 条「当前结束时间」，贪心接片 | [1632.cpp](1632.cpp) |
| 1633 | Dice Combinations | 完全背包式 DP：和为 n 的掷骰方案数 mod | [1633.cpp](1633.cpp) |
| 1634 | Minimizing Coins | 完全背包最少硬币数（无序） | [1634.cpp](1634.cpp) |
| 1635 | Coin Combinations I | 硬币顺序相关：外层和、内层硬币 | [1635.cpp](1635.cpp) |
| 1636 | Coin Combinations II | 顺序无关：外层硬币、内层和（避免重复计数） | [1636.cpp](1636.cpp) |
| 1637 | Removing Digits | DP：用 i 的十进制数码从更小状态转移 | [1637.cpp](1637.cpp) |
| 1638 | Grid Paths | 障碍网格路径数：记忆化 DFS / DP，mod 1e9+7 | [1638.cpp](1638.cpp) |
| 1639 | Edit Distance | 区间 DFS 记忆化最小编辑步数 | [1639.cpp](1639.cpp) |
| 1640 | Sum of Two Values | 排序 + 双指针找和为 x 的下标对 | [1640.cpp](1640.cpp) |
| 1641 | Sum of Three Values | 排序 + 固定一项 + 双指针 | [1641.cpp](1641.cpp) |
| 1642 | Sum of Four Values | 排序 + 两重固定 + 双指针 | [1642.cpp](1642.cpp) |
| 1643 | Maximum Subarray Sum | 前缀和 + 维护最小前缀（Kadane） | [1643.cpp](1643.cpp) |
| 1644 | Subarray Sums IV | 前缀和 + 单调 deque，长度在 [a,b] 的最大子段和 | [1644.cpp](1644.cpp) |
| 1645 | Nearest Smaller Values | 从右往左单调栈填「右侧更小最近位置」 | [1645.cpp](1645.cpp) |
| 1653 | Elevator Rides | 重量降序 + bitmask DP 最小趟数与剩余容量 | [1653.cpp](1653.cpp) |
| 1660 | Subarray Sums I | 前缀和 + `unordered_map` 统计 sum−x | [1660.cpp](1660.cpp) |
| 1661 | Subarray Sums II | 同上，哈希处理大范围（与 1660 实现同类） | [1661.cpp](1661.cpp) |
| 1662 | Subarray Divisibility | 前缀和 mod n 同余计数（map） | [1662.cpp](1662.cpp) |
| 1666 | Road Construction | DSU 读边后沿编号贪心补 (i,i+1) 使全连通 | [1666.cpp](1666.cpp) |
| 1667 | Message Route | 无权图 BFS 1→n，输出最短路长度与顶点序列 | [1667.cpp](1667.cpp) |
| 1668 | Building Teams | 二分图染色 DFS，冲突输出 IMPOSSIBLE | [1668.cpp](1668.cpp) |
| 1669 | Round Trip | DFS 找环，回溯输出简单环 | [1669.cpp](1669.cpp) |
| 1671 | Shortest Routes I | Dijkstra（非负权）；不可达输出 -1 | [1671.cpp](1671.cpp) |
| 1672 | Shortest Routes II | Floyd–Warshall 全源最短路；无向边取最小权；多组查询输出距离或 −1 | [1672.cpp](1672.cpp) |
| 1673 | High Score | 正权有向图最长路：从 1/n 双向 BFS 筛「在 1→n 某路径上」的边；Bellman-Ford 松弛 n 轮，第 n 轮仍可增则正环可达输出 −1 | [1673.cpp](1673.cpp) |
| 1743 | String Reorder | 贪心：优先用剩余 > 一半频次的字母避免相邻相同 | [1743.cpp](1743.cpp) |
| 1744 | Rectangle Cutting | 记忆化：横/竖切分取最小刀数 | [1744.cpp](1744.cpp) |
| 1745 | Money Sums | `set` 迭代扩展可达和，输出排序 | [1745.cpp](1745.cpp) |
| 1746 | Array Description | 填数组使相邻差 ≤1；记忆化 / 递推 mod | [1746.cpp](1746.cpp) |
| 1748 | Increasing Subsequences | 离散化 + 树状数组：统计递增子序列个数 mod | [1748.cpp](1748.cpp) |
| 1754 | Coin Piles | 数学判定：(a+b)%3==0 且 min(a,b)×2≥max(a,b) | [1754.cpp](1754.cpp) |
| 1755 | Palindrome Reorder | 字符频次奇数 >1 无解；否则半边 + 中缝构造 | [1755.cpp](1755.cpp) |
| 2162 | Josephus Problem I | 按步长 2 倍增模拟输出剔除顺序 | [2162.cpp](2162.cpp) |
| 2163 | Josephus Problem II | 树状数组维护存活集合 + 二分第 k 个 | [2163.cpp](2163.cpp) |
| 2165 | Tower of Hanoi | 递归经典三步输出移动序列 | [2165.cpp](2165.cpp) |
| 2168 | Nested Ranges Check | 区间排序 + 两次扫描维护 maxR/minR 判定包含关系 | [2168.cpp](2168.cpp) |
| 2169 | Nested Ranges Count | 坐标压缩 + 两个 BIT 统计嵌套对数 | [2169.cpp](2169.cpp) |
| 2181 | Counting Tilings | 轮廓 DP + `unordered_map`（`safe_hash`）记 mask，mod | [2181.cpp](2181.cpp) |
| 2183 | Missing Coin Sum | 排序硬币，贪心扩展可表示区间 [1, cur) | [2183.cpp](2183.cpp) |
| 2205 | Gray Code | `i ^ (i>>1)` 输出 n 位 Gray 码 | [2205.cpp](2205.cpp) |
| 2216 | Collecting Numbers | 统计「一轮」次数：若 a[i]−1 未出现则新开一段 | [2216.cpp](2216.cpp) |
| 2217 | Collecting Numbers II | 交换相邻元素时维护「起点」计数 | [2217.cpp](2217.cpp) |
| 2220 | Counting Numbers | 数位 DP：区间 [a,b] 无相邻相等数字 | [2220.cpp](2220.cpp) |
| 2413 | Counting Towers | 两列状态 DP 递推，预处理回答多组询问 | [2413.cpp](2413.cpp) |
| 2428 | Subarrays II | 双指针：至多 k 个不同值的子数组个数 | [2428.cpp](2428.cpp) |
| 2431 | Digit Queries | 将 1,2,3… 串成无限串，定位第 k 位所属数字与位 | [2431.cpp](2431.cpp) |
| 3217 | Knight Moves Grid | 棋盘马步 0-1 BFS / BFS 最短路 | [3217.cpp](3217.cpp) |
| 3311 | Grid Coloring | 逐格填 A–D，与上/左及原格不同 | [3311.cpp](3311.cpp) |
| 3314 | *见代码* | 值域笛卡尔树 + 后序 DP（最长合法链） | [3314.cpp](3314.cpp) |
| 3359 | *见代码* | 分层 BFS：每层选最小字符构造字典序路径 | [3359.cpp](3359.cpp) |
| 3399 | Card Game | 构造胜负平局序列：平局前缀 + 循环移位分配 | [3399.cpp](3399.cpp) |
| 3403 | *见代码* | LCS 记忆化 + 按 memo 回溯输出一条 LCS | [3403.cpp](3403.cpp) |
| 3419 | *见代码* | n×n 矩阵：首行首列 0…n−1，其余贪心填不冲突最小非负 | [3419.cpp](3419.cpp) |
| 3420 | Distinct Values Subarrays II | 双指针 + 频次：统计元素全不重复的子数组数 | [3420.cpp](3420.cpp) |
| 3421 | Counting Subsequences | 各值频次 (c+1) 乘积 −1（非空子序列数）mod | [3421.cpp](3421.cpp) |

## 本地测试

`run_test.sh` 会按 `test_cases/*.in` 的 **版本排序** 跑 `./test.o`，并用 `timeout`/`gtimeout` 做 **每测例 1s** 限制（见脚本内说明）。

## 相关模板

- 笛卡尔树 / 静态 treap 建树说明：[../common/data_structure/treap.cpp](../common/data_structure/treap.cpp)

---

*表格随本目录 `.cpp` 变更可手动更新；若你希望自动生成，可在 CI 或脚本里扫描文件头注释。*
