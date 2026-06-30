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
    void preorderDFS(TreeNode *root,vector<int>& result){
        if(root == nullptr){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            result.push_back(root->val);
        }

        preorderDFS(root->left,result);
        preorderDFS(root->right,result);
    }

    void preorderDFSRight(TreeNode *root,vector<int>& result){
        if(root == nullptr){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            result.push_back(root->val);
        }

        preorderDFSRight(root->right,result);
        preorderDFSRight(root->left,result);
    }

    int leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> result1;
        vector<int> result2;

        preorderDFS(root1,result1);
        preorderDFSRight(root2,result2);

        int r1=result1.size();
        int r2=result2.size();

        int count=0;

        for(int i=0;i<min(r1,r2);i++){
            if(result1[i] != result2[i]){
                count++;
            }
        }

        return count+abs(r1-r2);
    }
};

int main() {
    
    return 0;
}