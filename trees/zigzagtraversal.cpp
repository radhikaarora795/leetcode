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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr){
            return {};
        }
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight=true;

        while (!q.empty()) {
            int s = q.size();
            vector<int> level;
            for (int i = 0; i < s; i++) {
                TreeNode* ptr=q.front();
                q.pop();
                level.push_back(ptr->val);
                
                if(ptr->left != nullptr){
                    q.push(ptr->left);
                }
                if(ptr->right != nullptr){
                    q.push(ptr->right);
                }
            }
            if(leftToRight == true){
                ans.push_back(level);
                leftToRight=false;
            }
            else{
                reverse(level.begin(),level.end());
                ans.push_back(level);
                leftToRight=true;
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}