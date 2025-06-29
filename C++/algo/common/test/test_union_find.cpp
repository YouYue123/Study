#include <gtest/gtest.h>
#include "../union_find.cpp"

class UnionFindTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Create a sample union-find structure:
        // 0-1-2  3-4
        // |   |  |
        // 5   6  7
        uf = UF(8);
        uf.unite(0, 1);
        uf.unite(1, 2);
        uf.unite(0, 5);
        uf.unite(2, 6);
        uf.unite(3, 4);
        uf.unite(4, 7);
    }

    UF uf{0};  // Will be initialized in SetUp
};

TEST_F(UnionFindTest, Initialization) {
    UF newUf(5);
    EXPECT_EQ(newUf.size(), 5);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(newUf.findRoot(i), i);
    }
}

TEST_F(UnionFindTest, FindRoot) {
    // Test finding roots in the sample structure
    EXPECT_EQ(uf.findRoot(0), uf.findRoot(1));
    EXPECT_EQ(uf.findRoot(1), uf.findRoot(2));
    EXPECT_EQ(uf.findRoot(0), uf.findRoot(5));
    EXPECT_EQ(uf.findRoot(2), uf.findRoot(6));
    EXPECT_EQ(uf.findRoot(3), uf.findRoot(4));
    EXPECT_EQ(uf.findRoot(4), uf.findRoot(7));
}

TEST_F(UnionFindTest, Union) {
    // Test union operation
    UF testUf(4);
    testUf.unite(0, 1);
    EXPECT_TRUE(testUf.connected(0, 1));
    testUf.unite(2, 3);
    EXPECT_TRUE(testUf.connected(2, 3));
    EXPECT_FALSE(testUf.connected(0, 2));
    
    // Test union of already connected components
    testUf.unite(0, 1);  // Should not change anything
    EXPECT_TRUE(testUf.connected(0, 1));
}

TEST_F(UnionFindTest, Connected) {
    // Test connected components in the sample structure
    EXPECT_TRUE(uf.connected(0, 1));
    EXPECT_TRUE(uf.connected(1, 2));
    EXPECT_TRUE(uf.connected(0, 5));
    EXPECT_TRUE(uf.connected(2, 6));
    EXPECT_TRUE(uf.connected(3, 4));
    EXPECT_TRUE(uf.connected(4, 7));
    
    // Test non-connected components
    EXPECT_FALSE(uf.connected(0, 3));
    EXPECT_FALSE(uf.connected(1, 4));
    EXPECT_FALSE(uf.connected(5, 7));
}

TEST_F(UnionFindTest, Size) {
    EXPECT_EQ(uf.size(), 8);
    
    UF smallUf(3);
    EXPECT_EQ(smallUf.size(), 3);
}

TEST_F(UnionFindTest, PathCompression) {
    // Create a long chain: 0->1->2->3->4
    UF chainUf(5);
    for (int i = 0; i < 4; ++i) {
        chainUf.unite(i, i + 1);
    }
    
    // After finding root of 4, the path should be compressed
    int root = chainUf.findRoot(4);
    EXPECT_EQ(root, 0);
    
    // Verify path compression by checking parent pointers
    EXPECT_EQ(chainUf.findRoot(4), 0);
    EXPECT_EQ(chainUf.findRoot(3), 0);
    EXPECT_EQ(chainUf.findRoot(2), 0);
    EXPECT_EQ(chainUf.findRoot(1), 0);
} 