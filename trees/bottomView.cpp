#include <iostream>
#include <map>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        if(root == nullptr){
            return {};
        }
        
        vector<int> ans;
        queue<pair<Node*,int>> q;   // node,hd
        map<int,int> m ; // hd,node value
        
        q.push({root,0});
        
        while(!q.empty()){
            auto [node,hd]=q.front();
            q.pop();
            
            m[hd]=node->data;
            
            if(node->left != nullptr){
                q.push({node->left,hd-1});
            }
            
            if(node->right != nullptr){
                q.push({node->right,hd+1});
            }
        }
        
        for(auto i:m){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};

int main() {
    
    return 0;
}