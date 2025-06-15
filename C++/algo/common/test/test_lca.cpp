#include <gtest/gtest.h>
#include <unordered_map>
#include <vector>
#include "../lca.cpp"

using namespace std;

class LCATest : public ::testing::Test {
protected:
    void SetUp() override {
        // Create a sample tree:
        //       0
        //     /   \
        //    1     2
        //   / \   / \
        //  3   4 5   6
        //     / \
        //    7   8
        graph[0] = {{1, 1}, {2, 1}};
        graph[1] = {{0, 1}, {3, 1}, {4, 1}};
        graph[2] = {{0, 1}, {5, 1}, {6, 1}};
        graph[3] = {{1, 1}};
        graph[4] = {{1, 1}, {7, 1}, {8, 1}};
        graph[5] = {{2, 1}};
        graph[6] = {{2, 1}};
        graph[7] = {{4, 1}};
        graph[8] = {{4, 1}};
    }

    unordered_map<int, vector<pair<int, int>>> graph;
};

TEST_F(LCATest, BasicLCATest) {
    LCA lca(9, graph);
    
    // Test LCA of nodes at same depth
    EXPECT_EQ(lca.get_lca(3, 4), 1);
    EXPECT_EQ(lca.get_lca(5, 6), 2);
    EXPECT_EQ(lca.get_lca(7, 8), 4);
    
    // Test LCA of nodes at different depths
    EXPECT_EQ(lca.get_lca(3, 7), 1);
    EXPECT_EQ(lca.get_lca(5, 8), 0);
    EXPECT_EQ(lca.get_lca(6, 7), 0);
    
    // Test LCA with root
    EXPECT_EQ(lca.get_lca(0, 3), 0);
    EXPECT_EQ(lca.get_lca(0, 7), 0);
}

TEST_F(LCATest, DistanceTest) {
    LCA lca(9, graph);
    
    // Test distances between nodes
    EXPECT_EQ(lca.get_distance(3, 4), 2);
    EXPECT_EQ(lca.get_distance(7, 8), 2);
    EXPECT_EQ(lca.get_distance(3, 7), 3);
    EXPECT_EQ(lca.get_distance(5, 8), 5);
    
    // Test distance from root
    EXPECT_EQ(lca.get_distance(0, 3), 2);
    EXPECT_EQ(lca.get_distance(0, 7), 3);
}

TEST_F(LCATest, EdgeCases) {
    LCA lca(9, graph);
    
    // Test LCA of same node
    EXPECT_EQ(lca.get_lca(3, 3), 3);
    EXPECT_EQ(lca.get_lca(0, 0), 0);
    
    // Test distance of same node
    EXPECT_EQ(lca.get_distance(3, 3), 0);
    EXPECT_EQ(lca.get_distance(0, 0), 0);
}