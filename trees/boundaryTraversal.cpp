#include <iostream>
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
    vector<int> ans;
    
    bool isLeaf(Node* root){
        return (root && !root->left && !root->right);   // root exists left right null
    }
    
    void leftBoundary(Node* root){
        Node* curr=root;
        while(curr != nullptr){
            if(!isLeaf(curr)){
                ans.push_back(curr->data);
            }
            if(curr->left){
                curr=curr->left;
            }
            else{
                curr=curr->right;
            }
        }
    }
    
    void leafNodes(Node* root){
        // preorder traversal
        if(root == nullptr){
            return;
        }
        if(isLeaf(root)){
            ans.push_back(root->data);
        }
        leafNodes(root->left);
        leafNodes(root->right);
    }
    
    void rightBoundary(Node* root){
        vector<int> temp;
        Node* curr=root;
        while(curr != nullptr){
            if(!isLeaf(curr)){
                temp.push_back(curr->data);
            }
            if(curr->right){
                curr=curr->right;
            }
            else{
                curr=curr->left;
            }
        }
        for(int i=temp.size()-1;i>=0;i--){
            ans.push_back(temp[i]);
        }
        
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        if(root == nullptr){
            return {};
        }
        if(!isLeaf(root)){
            ans.push_back(root->data);
        }
        if(root->left){
            leftBoundary(root->left);   
        }
        leafNodes(root);
        if(root->right){
            rightBoundary(root->right);   
        }
        
        return ans;
    }
};

int main() {
    
    return 0;
}