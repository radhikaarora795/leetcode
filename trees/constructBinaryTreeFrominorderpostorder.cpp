#include <iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map<int,int> map;    // value,index

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,int& postIdx,int left, int right){
        if(left>right){
            return nullptr;
        }
        TreeNode* root=new TreeNode(postorder[postIdx]);
        int inIdx=map[postorder[postIdx]];
        postIdx--;
        root->right=helper(inorder,postorder,postIdx,inIdx+1,right);
        root->left=helper(inorder,postorder,postIdx,left,inIdx-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIdx=postorder.size()-1;
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }
        return helper(inorder,postorder,postIdx,0,inorder.size()-1);
    }
};

int main() {
    
    return 0;
}