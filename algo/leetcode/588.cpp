#include <bits/stdc++.h>
using namespace std;

// 588. Design In-Memory File System [H]
// LeetCode design-in-memory-file-system

struct Node {
    bool isDir = true;
    // Only for non-dir
    string content;
    unordered_map<string, Node*> children;
    bool hasChild(string path) {
        return children.contains(path);
    }
    Node* getChild(string path) {
        if(!hasChild(path)) return nullptr;
        return children[path];
    }
    void setChild (string path, Node* child) {
        children[path] = child;
    }
};
class FileSystem {
private:
    Node* masterNode;
    vector<string> splitPath (string path) {
        vector<string> ans;
        string temp = "";
        for(char c : path) {
            if(c == '/') {
                if(!temp.empty()) ans.push_back(temp);
                temp.clear();
            } else {
                temp += c;
            }
        }
        if(!temp.empty()) ans.push_back(temp); 
        return ans;
    }
public:
    FileSystem() {
        masterNode = new Node();
    }
    
    vector<string> ls(string queryPath) {
        vector<string> ans;
        auto paths = splitPath(queryPath);
        auto root = masterNode;
        for(auto path : paths) {
            // cout << path << endl;
            if(root->hasChild(path)) {
                root = root->getChild(path);
            } else {
                // cout << "does not exist" << endl;
                // not exist
                return {};
            }
        }
        // cout << root->
        if(root->isDir) {
            for(auto& [path, _] : root->children) {
                ans.push_back(path);
            }
            sort(ans.begin(), ans.end());
        } else {
            ans.push_back(paths[paths.size() - 1]);
        }
        return ans;
    }
    
    void mkdir(string folderPath) {
        // what if path exist
        // cout << folderPath << endl;
        auto paths = splitPath(folderPath);
        auto root = masterNode;
        for(auto path : paths) {
            // cout << path << endl;
            if(!root->hasChild(path)) {
                root->setChild(path, new Node());
            }
            root = root->getChild(path);
        }
    }
    
    void addContentToFile(string filePath, string content) {
        // what if it adds into a dir path
        auto paths = splitPath(filePath);
        auto root = masterNode;
        int n = paths.size();
        for(int i = 0; i < n - 1; i ++) {
            string path = paths[i];
            if(!root->hasChild(path)) {
                return;
            }
            root = root->getChild(path);
        }
        string lastPath = paths[n - 1];
        if(root->hasChild(lastPath)) {
            if(root->getChild(lastPath)->isDir) return;
            root->getChild(lastPath)->content += content;
        } else {
            root->setChild(lastPath, new Node(false, content));
        }
    }
    
    string readContentFromFile(string filePath) {
        // what if it reads a dir path
        auto paths = splitPath(filePath);
        auto root = masterNode;
        for(auto path : paths) {
            if(!root->hasChild(path)) {
                return "";
            }
            root = root->getChild(path);
        }
        if(root->isDir) return "";
        return root->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */