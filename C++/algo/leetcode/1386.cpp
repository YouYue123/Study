// 1386. Cinema Seat Allocation [M]
// LeetCode cinema-seat-allocation

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // 使用哈希表只存储有预约的行，key 为行号，value 为位掩码
        unordered_map<int, int> occupied;
        for (const auto& seat : reservedSeats) {
            int r = seat[0];
            int c = seat[1];
            // 用位运算标记第 c 列被占用
            occupied[r] |= (1 << c);
        }

        // 初始假设每行都能坐 2 个家庭
        // 注意使用 long long 防止 n 很大时计算溢出（虽然这里 ans 不会溢出 int）
        int ans = (n - occupied.size()) * 2;

        for (auto const& [row, mask] : occupied) {
            bool left = true, right = true, middle = true;
            
            // 检查 2,3,4,5 列 (左)
            if (mask & (1 << 2) || mask & (1 << 3) || mask & (1 << 4) || mask & (1 << 5)) left = false;
            // 检查 6,7,8,9 列 (右)
            if (mask & (1 << 6) || mask & (1 << 7) || mask & (1 << 8) || mask & (1 << 9)) right = false;
            // 检查 4,5,6,7 列 (中)
            if (mask & (1 << 4) || mask & (1 << 5) || mask & (1 << 6) || mask & (1 << 7)) middle = false;

            if (left && right) {
                ans += 2;
            } else if (left || right || middle) {
                ans += 1;
            }
        }

        return ans;
    }
};