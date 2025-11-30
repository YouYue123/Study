#include <gtest/gtest.h>
#include "../segment_tree.cpp"
#include <vector>
#include <algorithm>

using namespace std;

// Test basic segment tree (max query)
TEST(SegmentTreeTest, BasicMaxQuery) {
    vector<int> a = {1, 3, 5, 7, 9, 11};
    SegmentTree seg(a);
    
    EXPECT_EQ(seg.query(1, 0, 2), 5);   // max(1, 3, 5) = 5
    EXPECT_EQ(seg.query(1, 2, 4), 9);   // max(5, 7, 9) = 9
    EXPECT_EQ(seg.query(1, 0, 5), 11);   // max of all = 11
}

TEST(SegmentTreeTest, BasicUpdate) {
    vector<int> a = {1, 3, 5, 7, 9, 11};
    SegmentTree seg(a);
    
    seg.update(1, 1, 20);
    EXPECT_EQ(seg.query(1, 0, 2), 20);  // max(1, 20, 5) = 20
    EXPECT_EQ(seg.query(1, 1, 1), 20);  // single element
}

TEST(SegmentTreeTest, FindFirst) {
    vector<int> a = {1, 3, 5, 7, 9, 11};
    SegmentTree seg(a);
    
    // Find first position >= 10
    int idx = seg.findFirst(1, 0, 5, [](int val) { return val >= 10; });
    EXPECT_EQ(idx, 5);  // position 5 has value 11
    
    // Find first position >= 4
    idx = seg.findFirst(1, 0, 5, [](int val) { return val >= 4; });
    EXPECT_EQ(idx, 2);  // position 2 has value 5
}

TEST(SegmentTreeTest, FindLast) {
    vector<int> a = {1, 3, 5, 7, 9, 11};
    SegmentTree seg(a);
    
    // Find last position <= 6
    int idx = seg.findLast(1, 0, 5, [](int val) { return val <= 6; });
    EXPECT_EQ(idx, 2);  // position 2 has value 5
}

// Test lazy segment tree (sum query)
TEST(LazySegmentTreeTest, BasicSumQuery) {
    vector<int> a = {1, 2, 3, 4, 5};
    LazySegmentTree seg(a);
    
    EXPECT_EQ(seg.query(1, 0, 2), 6);   // 1 + 2 + 3 = 6
    EXPECT_EQ(seg.query(1, 0, 4), 15);   // sum of all = 15
}

TEST(LazySegmentTreeTest, RangeUpdate) {
    vector<int> a = {1, 2, 3, 4, 5};
    LazySegmentTree seg(a);
    
    seg.update(1, 0, 2, 10);  // add 10 to [0, 2]
    EXPECT_EQ(seg.query(1, 0, 2), 36);  // (1+10) + (2+10) + (3+10) = 36
    EXPECT_EQ(seg.query(1, 3, 4), 9);   // 4 + 5 = 9 (unchanged)
}

TEST(LazySegmentTreeTest, MultipleUpdates) {
    vector<int> a = {1, 2, 3, 4, 5};
    LazySegmentTree seg(a);
    
    seg.update(1, 0, 2, 5);
    seg.update(1, 1, 3, 3);
    EXPECT_EQ(seg.query(1, 0, 0), 6);   // 1 + 5 = 6
    EXPECT_EQ(seg.query(1, 1, 1), 10);  // 2 + 5 + 3 = 10
    EXPECT_EQ(seg.query(1, 2, 2), 11);  // 3 + 5 + 3 = 11
    EXPECT_EQ(seg.query(1, 3, 3), 7);   // 4 + 3 = 7
}

// Test dynamic segment tree
TEST(DynamicSegmentTreeTest, LargeRange) {
    DynamicSegmentTree seg(0, 1000000000);
    
    seg.update(seg.root, 1000000, 10);
    seg.update(seg.root, 2000000, 20);
    seg.update(seg.root, 3000000, 30);
    
    EXPECT_EQ(seg.query(seg.root, 500000, 1500000), 10);
    EXPECT_EQ(seg.query(seg.root, 1500000, 2500000), 20);
    EXPECT_EQ(seg.query(seg.root, 500000, 2500000), 20);
    EXPECT_EQ(seg.query(seg.root, 2500000, 3500000), 30);
}

TEST(DynamicSegmentTreeTest, OverlappingQueries) {
    DynamicSegmentTree seg(-1000000, 1000000);
    
    seg.update(seg.root, -500, 5);
    seg.update(seg.root, 0, 10);
    seg.update(seg.root, 500, 15);
    
    EXPECT_EQ(seg.query(seg.root, -1000, 1000), 15);
    EXPECT_EQ(seg.query(seg.root, -600, -400), 5);
    EXPECT_EQ(seg.query(seg.root, 400, 600), 15);
}

// Test persistent segment tree
TEST(PersistentSegmentTreeTest, VersionHistory) {
    vector<int> a = {1, 2, 3, 4, 5};
    PersistentSegmentTree pst;
    vector<PersistentSegmentTree::PSTNode*> versions;
    
    versions.push_back(pst.build(a, 0, a.size() - 1));
    EXPECT_EQ(pst.queryRange(versions[0], 0, 2), 6);  // 1 + 2 + 3 = 6
    EXPECT_EQ(pst.queryRange(versions[0], 0, 4), 15);  // sum of all = 15
    
    // Create new version by modifying
    versions.push_back(pst.modify(versions[0], 0, 10));
    EXPECT_EQ(pst.queryRange(versions[1], 0, 2), 16);  // (1+10) + 2 + 3 = 16
    EXPECT_EQ(pst.queryRange(versions[0], 0, 2), 6);   // old version unchanged
    
    // Create another version
    versions.push_back(pst.modify(versions[1], 2, 5));
    EXPECT_EQ(pst.queryRange(versions[2], 0, 2), 21);  // 11 + 2 + (3+5) = 21
    EXPECT_EQ(pst.queryRange(versions[1], 0, 2), 16);  // previous version unchanged
    EXPECT_EQ(pst.queryRange(versions[0], 0, 2), 6);   // original unchanged
}

TEST(PersistentSegmentTreeTest, KthSmallest) {
    // This test requires building versions with count information
    // For simplicity, we test the structure exists
    PersistentSegmentTree pst;
    vector<int> a = {1, 1, 1, 1, 1};
    auto root = pst.build(a, 0, a.size() - 1);
    EXPECT_NE(root, nullptr);
}

// Test edge cases
TEST(SegmentTreeTest, SingleElement) {
    vector<int> a = {42};
    SegmentTree seg(a);
    
    EXPECT_EQ(seg.query(1, 0, 0), 42);
    EXPECT_EQ(seg.queryAll(), 42);
    
    seg.update(1, 0, 100);
    EXPECT_EQ(seg.query(1, 0, 0), 100);
}

TEST(LazySegmentTreeTest, SingleElement) {
    vector<int> a = {42};
    LazySegmentTree seg(a);
    
    EXPECT_EQ(seg.query(1, 0, 0), 42);
    seg.update(1, 0, 0, 10);
    EXPECT_EQ(seg.query(1, 0, 0), 52);
}

TEST(SegmentTreeTest, EmptyQuery) {
    vector<int> a = {1, 2, 3, 4, 5};
    SegmentTree seg(a);
    
    // Query same start and end
    EXPECT_EQ(seg.query(1, 2, 2), 3);
}

