#include <iostream>
#include <vector>
#include <memory>
#include <functional>
#include <iomanip>
using namespace std;
// 不可变节点：成员设为 const 以防止修改 [2]
struct Node {
    const int value;
    const size_t hash; // 用于 Part 2 的 verify() 功能 [5, 6]
    const shared_ptr<const Node> left;
    const shared_ptr<const Node> right;

    Node(int v, shared_ptr<const Node> l, std::shared_ptr<const Node> r)
        : value(v), 
          left(l), 
          right(r), 
          hash(computeHash(v, l, r)) 
          {}

    // 计算哈希：类似于默克尔树 (Merkle Tree) 机制 [7, 6]
    static size_t computeHash(
        int v, 
        shared_ptr<const Node> l, 
        shared_ptr<const Node> r
    ) {
        size_t h = std::hash<int>{}(v);
        if (l) h ^= l->hash + 0x9e3779b9 + (h << 6) + (h >> 2);
        if (r) h ^= r->hash + 0x9e3779b9 + (h << 6) + (h >> 2);
        return h;
    }
};

// 插入操作：返回一个包含新节点的新根，旧树保持不变 [1]
shared_ptr<const Node> insert(shared_ptr<const Node> root, int val) {
    if (root == nullptr) {
        return make_shared<Node>(val, nullptr, nullptr);
    }
    if (val < root->value) {
        // 路径拷贝：仅重新创建左侧路径上的节点，复用右侧子树 
        return make_shared<Node>(
            root->value, 
            insert(root->left, val), 
            root->right
        );
    } else {
        return make_shared<Node>(
            root->value, 
            root->left, 
            insert(root->right, val)
        );
    }
}

// 验证函数：递归检查每个节点的哈希一致性 [8, 6]
bool verify(shared_ptr<const Node> node) {
    if (!node) return true;
    size_t actual = Node::computeHash(
        node->value, 
        node->left, 
        node->right
    );
    return (node->hash == actual) && verify(node->left) && verify(node->right);
}

// 辅助函数：中序遍历打印树（从小到大）
void printTree(shared_ptr<const Node> root) {
    if (!root) return;
    printTree(root->left);
    cout << root->value << " ";
    printTree(root->right);
}

int main() {
    // 使用 vector 存储不同版本的根节点，这就是我们的“时间轴”
    vector<shared_ptr<const Node>> versions;

    cout << "--- 1. 初始化版本 V0 ---" << endl;
    auto v0 = insert(nullptr, 50);
    versions.push_back(v0);
    
    cout << "--- 2. 连续插入，创建新版本 ---" << endl;
    // 在 V0 基础上插入 30 -> 产生 V1
    versions.push_back(insert(versions.back(), 30));
    // 在 V1 基础上插入 70 -> 产生 V2
    versions.push_back(insert(versions.back(), 70));
    // 在 V2 基础上插入 40 -> 产生 V3
    versions.push_back(insert(versions.back(), 40));

    // 展示所有版本的数据状态
    for (size_t i = 0; i < versions.size(); ++i) {
        cout << "版本 " << i << " [根节点哈希: " << hex << versions[i]->hash << "]: ";
        printTree(versions[i]);
        cout << (verify(versions[i]) ? " (验证通过 ✅)" : " (验证失败 ❌)") << endl;
    }

    std::cout << "\n--- 3. 演示“回退”到版本 V1 ---" << std::endl;
    auto current = versions[1]; 
    std::cout << "当前处于版本 1，内容为: " << std::dec;
    printTree(current); // 应该只看到 30 50
    std::cout << "\n从版本 1 分叉，插入新值 100 得到新版本 V4:" << std::endl;
    
    auto v4 = insert(current, 100);
    std::cout << "版本 V4 内容: ";
    printTree(v4); // 应该看到 30 50 100
    
    std::cout << "\n--- 4. 结构共享验证 ---" << std::endl;
    std::cout << "V2 的右子树地址: " << versions[2]->right.get() << std::endl;
    std::cout << "V3 的右子树地址: " << versions[3]->right.get() << " (应该与 V2 相同，因为插入 40 只影响左路)" << std::endl;

    return 0;
}