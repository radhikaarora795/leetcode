/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

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
    bool isMirror(TreeNode *n1, TreeNode *n2){
        bool symmetric=false;

        if(n1==nullptr && n2==nullptr){
            return true;
        }
        if(n1==nullptr || n2==nullptr){
            return false;
        }

        if(n1->val == n2->val && isMirror(n1->left,n2->right) && isMirror(n1->right,n2->left)){
            symmetric=true;
        }

        return symmetric;

    }

    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left,root->right);
    }
};

int main() {
    
    return 0;
}