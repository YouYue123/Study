#include <vector>
using namespace std;

// 树状数组（Binary Indexed Tree，又称Fenwick Tree）数据结构
struct BIT
{
    vector<int> tree; // 存储树状数组的数组

    // 构造函数，初始化树状数组
    // 参数N: 树状数组的大小（通常为元素个数+1，因为索引从1开始）
    BIT(int N)
    {
        tree.assign(N + 1, 0); // 分配N+1个空间并初始化为0
    }

    // 计算lowbit值，即一个数的最低位1所代表的值
    // 例如：lowbit(6)=2 (6的二进制是110)
    int lowbit(int i)
    {
        return i & (-i); // 位运算技巧：i与它的负数按位与
    }

    // 向树状数组的指定位置添加值
    // 参数index: 要更新的位置（从1开始）
    // 参数val: 要增加的值
    void add(int index, int val)
    {
        // 从index开始，向上更新所有相关节点
        while (index < (int)tree.size())
        {
            tree[index] += val;     // 当前节点增加val
            index += lowbit(index); // 移动到父节点
        }
    }

    // 查询前缀和（从1到index的元素和）
    // 参数index: 查询的结束位置
    // 返回值: 前index个元素的和
    int query(int index)
    {
        int ans = 0; // 初始化结果为0

        // 从index开始，向下累加所有相关节点的值
        while (index > 0)
        {
            ans += tree[index];     // 累加当前节点的值
            index -= lowbit(index); // 移动到前一个需要累加的节点
        }
        return ans; // 返回累加结果
    }
};