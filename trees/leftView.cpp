#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    void dfs(Node *root,int level, vector<int>& ans){
        if(root == nullptr){
            return;
        }
        if(level == ans.size()){
            ans.push_back(root->data);
        }
        dfs(root->left,level+1,ans);
        dfs(root->right,level+1,ans);
    }
  
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        dfs(root,0,ans);
        return ans;
    }
};

int main() {
    
    return 0;
}