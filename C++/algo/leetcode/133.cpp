#include <bits/stdc++.h>
using namespace std;

// 133. Clone Graph [M]
// LeetCode clone-graph

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> dict;
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        if(dict.contains(node)) return dict[node];
        Node* newNode = new Node(node->val);
        dict[node] = newNode;
        for(Node* next : node->neighbors) {
            newNode->neighbors.push_back(
                cloneGraph(next)
            );
        }
        return dict[node];
    }
};