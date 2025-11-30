// Example usage of Segment Tree implementations
// Compile with: g++ -std=c++17 segment_tree.cpp segment_tree_example.cpp -o segment_tree_example

#include "segment_tree.cpp"
#include <iostream>
#include <vector>

using namespace std;

void example_basic_segment_tree() {
    cout << "=== Basic Segment Tree Example ===" << endl;
    
    vector<int> a = {1, 3, 5, 7, 9, 11};
    SegmentTree seg(a);
    
    cout << "Initial array: ";
    for (int x : a) cout << x << " ";
    cout << endl;
    
    // Query range [0, 2]
    cout << "Max in [0, 2]: " << seg.query(1, 0, 2) << endl;  // Should be 5
    
    // Query range [2, 4]
    cout << "Max in [2, 4]: " << seg.query(1, 2, 4) << endl;  // Should be 9
    
    // Update position 1 to 20
    seg.update(1, 1, 20);
    cout << "After updating position 1 to 20:" << endl;
    cout << "Max in [0, 2]: " << seg.query(1, 0, 2) << endl;  // Should be 20
    
    // Binary search: find first position >= 10
    int idx = seg.findFirst(1, 0, 5, [](int val) { return val >= 10; });
    cout << "First position >= 10: " << idx << endl;  // Should be 5 (value 11)
    
    cout << endl;
}

void example_lazy_segment_tree() {
    cout << "=== Lazy Segment Tree Example ===" << endl;
    
    vector<int> a = {1, 2, 3, 4, 5};
    LazySegmentTree seg(a);
    
    cout << "Initial array: ";
    for (int x : a) cout << x << " ";
    cout << endl;
    
    // Query sum of [0, 2]
    cout << "Sum in [0, 2]: " << seg.query(1, 0, 2) << endl;  // Should be 6
    
    // Add 10 to range [0, 2]
    seg.update(1, 0, 2, 10);
    cout << "After adding 10 to [0, 2]:" << endl;
    cout << "Sum in [0, 2]: " << seg.query(1, 0, 2) << endl;  // Should be 36
    
    // Query unchanged range
    cout << "Sum in [3, 4]: " << seg.query(1, 3, 4) << endl;  // Should be 9
    
    cout << endl;
}

void example_dynamic_segment_tree() {
    cout << "=== Dynamic Segment Tree Example ===" << endl;
    
    // Create segment tree for large value range [0, 1e9]
    DynamicSegmentTree seg(0, 1000000000);
    
    // Update some sparse positions
    seg.update(seg.root, 1000000, 10);
    seg.update(seg.root, 2000000, 20);
    seg.update(seg.root, 3000000, 30);
    
    cout << "Updated positions: 1000000=10, 2000000=20, 3000000=30" << endl;
    
    // Query ranges
    cout << "Max in [500000, 1500000]: " << seg.query(seg.root, 500000, 1500000) << endl;  // Should be 10
    cout << "Max in [1500000, 2500000]: " << seg.query(seg.root, 1500000, 2500000) << endl;  // Should be 20
    cout << "Max in [500000, 2500000]: " << seg.query(seg.root, 500000, 2500000) << endl;  // Should be 20
    
    cout << endl;
}

void example_persistent_segment_tree() {
    cout << "=== Persistent Segment Tree Example ===" << endl;
    
    vector<int> a = {1, 2, 3, 4, 5};
    PersistentSegmentTree pst;
    vector<PersistentSegmentTree::PSTNode*> versions;
    
    // Build initial version
    versions.push_back(pst.build(a, 0, a.size() - 1));
    cout << "Version 0 (initial):" << endl;
    cout << "  Sum in [0, 2]: " << pst.queryRange(versions[0], 0, 2) << endl;  // Should be 6
    cout << "  Sum in [0, 4]: " << pst.queryRange(versions[0], 0, 4) << endl;  // Should be 15
    
    // Create version 1 by modifying position 0
    versions.push_back(pst.modify(versions[0], 0, 10));
    cout << "Version 1 (add 10 to position 0):" << endl;
    cout << "  Sum in [0, 2]: " << pst.queryRange(versions[1], 0, 2) << endl;  // Should be 16
    cout << "  Version 0 unchanged, Sum in [0, 2]: " << pst.queryRange(versions[0], 0, 2) << endl;  // Still 6
    
    // Create version 2 by modifying position 2
    versions.push_back(pst.modify(versions[1], 2, 5));
    cout << "Version 2 (add 5 to position 2):" << endl;
    cout << "  Sum in [0, 2]: " << pst.queryRange(versions[2], 0, 2) << endl;  // Should be 21
    cout << "  Version 1 unchanged, Sum in [0, 2]: " << pst.queryRange(versions[1], 0, 2) << endl;  // Still 16
    cout << "  Version 0 unchanged, Sum in [0, 2]: " << pst.queryRange(versions[0], 0, 2) << endl;  // Still 6
    
    cout << endl;
}

int main() {
    example_basic_segment_tree();
    example_lazy_segment_tree();
    example_dynamic_segment_tree();
    example_persistent_segment_tree();
    
    return 0;
}

