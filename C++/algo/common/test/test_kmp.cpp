#include <gtest/gtest.h>
#include "../kmp.cpp"

class KMPTest : public ::testing::Test {
protected:
    KMP kmp;
};

TEST_F(KMPTest, BasicPatternMatching) {
    string text = "AABAACAADAABAAABAA";
    string pattern = "AABA";
    vector<int> expected = {0, 9, 13};
    vector<int> result = kmp.kmp(text, pattern);
    EXPECT_EQ(result, expected);
}

TEST_F(KMPTest, MultipleOccurrences) {
    string text = "AAAAA";
    string pattern = "AA";
    vector<int> expected = {0, 1, 2, 3};
    vector<int> result = kmp.kmp(text, pattern);
    EXPECT_EQ(result, expected);
}

TEST_F(KMPTest, PatternAtEnds) {
    string text = "HELLOHELLO";
    string pattern = "HELLO";
    vector<int> expected = {0, 5};
    vector<int> result = kmp.kmp(text, pattern);
    EXPECT_EQ(result, expected);
}

TEST_F(KMPTest, EmptyPattern) {
    string text = "HELLO";
    string pattern = "";
    vector<int> expected = {0, 1, 2, 3, 4, 5};
    vector<int> result = kmp.kmp(text, pattern);
    EXPECT_EQ(result, expected);
}

TEST_F(KMPTest, PatternNotFound) {
    string text = "HELLO";
    string pattern = "WORLD";
    vector<int> expected = {};
    vector<int> result = kmp.kmp(text, pattern);
    EXPECT_EQ(result, expected);
}

TEST_F(KMPTest, LongerPattern) {
    string text = "HELLO";
    string pattern = "HELLOWORLD";
    vector<int> expected = {};
    vector<int> result = kmp.kmp(text, pattern);
    EXPECT_EQ(result, expected);
}

TEST_F(KMPTest, SingleCharacterPattern) {
    string text = "HELLO";
    string pattern = "L";
    vector<int> expected = {2, 3};
    vector<int> result = kmp.kmp(text, pattern);
    EXPECT_EQ(result, expected);
}

TEST_F(KMPTest, OverlappingPatterns) {
    string text = "ABABABAB";
    string pattern = "ABAB";
    vector<int> expected = {0, 2, 4};
    vector<int> result = kmp.kmp(text, pattern);
    EXPECT_EQ(result, expected);
}

TEST_F(KMPTest, RepeatedCharacters) {
    string text = "ZZZZZZ";
    string pattern = "ZZZ";
    vector<int> expected = {0, 1, 2, 3};
    vector<int> result = kmp.kmp(text, pattern);
    EXPECT_EQ(result, expected);
}

TEST_F(KMPTest, MixedCasePattern) {
    string text = "HelloWorld";
    string pattern = "oWo";
    vector<int> expected = {4};
    vector<int> result = kmp.kmp(text, pattern);
    EXPECT_EQ(result, expected);
}

