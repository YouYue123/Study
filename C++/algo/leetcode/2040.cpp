#include <bits/stdc++.h>
using namespace std;

// 2040. Kth Smallest Product of Two Sorted Arrays [H]
// LeetCode kth-smallest-product-of-two-sorted-arrays

class Solution {
public:
    long long kthSmallestProduct(vector<int>& a, vector<int>& b, long long k) {
        int n = a.size(), m = b.size();
        int i0 = ranges::lower_bound(a, 0) - a.begin(); // 四个区域的水平分界线
        int j0 = ranges::lower_bound(b, 0) - b.begin(); // 四个区域的垂直分界线

        auto isValid = [&](long long mx) -> bool {
            long long cnt = 0;

            if (mx < 0) {
                // 右上区域
                int i = 0, j = j0;
                while (i < i0 &&
                       j < m) { // 注：可以加个 cnt < k 的判断，提前退出
                    if (1LL * a[i] * b[j] > mx) {
                        j++;
                    } else {
                        cnt += m - j;
                        i++;
                    }
                }

                // 左下区域
                i = i0;
                j = 0;
                while (i < n && j < j0) {
                    if (1LL * a[i] * b[j] > mx) {
                        i++;
                    } else {
                        cnt += n - i;
                        j++;
                    }
                }
            } else {
                // 右上区域和左下区域的所有数都 <= 0 <= mx
                cnt = 1LL * i0 * (m - j0) + 1LL * (n - i0) * j0;

                // 左上区域
                int i = 0, j = j0 - 1;
                while (i < i0 && j >= 0) {
                    if (1LL * a[i] * b[j] > mx) {
                        i++;
                    } else {
                        cnt += i0 - i;
                        j--;
                    }
                }

                // 右下区域
                i = i0;
                j = m - 1;
                while (i < n && j >= j0) {
                    if (1LL * a[i] * b[j] > mx) {
                        j--;
                    } else {
                        cnt += j - j0 + 1;
                        i++;
                    }
                }
            }

            return cnt >= k;
        };

        long long corners[4] = {
            1LL * a[0] * b[0],
            1LL * a[0] * b[m - 1],
            1LL * a[n - 1] * b[0],
            1LL * a[n - 1] * b[m - 1],
        };

        long long left = -1e10 - 1, right = 1e10 + 1;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (isValid(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};