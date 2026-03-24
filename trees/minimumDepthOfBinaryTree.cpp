#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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

// best solution
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int left=minDepth(root->left);
        int right=minDepth(root->right);

        if(left != 0 && right != 0){
            return 1+min(left,right);
        }
        return 1+left+right;    // if left or right is zero
    }
};

// recursive DFS
/*class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        // if left subtree is null, recurse only into right subtree
        if(root->left == nullptr){
            return 1+minDepth(root->right);
        }
        // if right subtree is null, recurse only into left subtree
        if(root->right == nullptr){
            return 1+minDepth(root->left);
        }
        // if both subtrees are non-null, take the minimum
        return 1+min(minDepth(root->left),minDepth(root->right));
    }
};*/

// BFS: using queue
// class Solution {
// public:
//     int minDepth(TreeNode* root) {
//         if(root == nullptr){
//             return 0;
//         }
//         queue<pair<TreeNode*,int>> q;
//         // keeps track of nodes and their current depth.
//         /* A pair<T1, T2> is a C++ Standard Library type that holds exactly two values, possibly of different types: 
//         first value → .first  second value → .second */
//         q.push({root,1}); // node + current depth
//         while(!q.empty()){
//             /*
//             each element inside q is a pair<TreeNode*, int>.
//             q.front() returns (without removing) the front element from the queue
//             i.e., the next (TreeNode*, int) pair to process.

//             auto [node, depth] = q.front();
//             auto lets the compiler deduce the type automatically.
//             The [node, depth] part is called structured binding (introduced in C++17).
//             It unpacks the pair into two separate variables:
//             (When you unpack a value, you take something that is grouped together (like a pair, tuple, or array)
//             and split it into separate variables.)
//             node → corresponds to the first element of the pair (TreeNode*)
//             depth → corresponds to the second element of the pair (int)
//             So after this line:
//             node is the pointer to the current TreeNode to process.
//             depth is its current depth from the root.

//             Queues are FIFO: First In, First Out
//             You must remove the front element after you’re done with it.
//             Otherwise, on the next iteration, q.front() would keep returning the same node over and over → infinite loop.
//             */
//             auto[node,depth]=q.front();
//             q.pop();
            
//             // If the current node is a leaf node (no left or right children),
//             // we've found the minimum depth, so return it immediately.
//             if(node->left == nullptr && node->right == nullptr){
//                 return depth;
//             }

//             // If the current node has a left child, add it to the queue
//             // and increase depth by 1.
//             if (node->left) {
//                 q.push({node->left, depth + 1});
//             }

//             // If the current node has a right child, add it to the queue
//             // and increase depth by 1.
//             if (node->right) {
//                 q.push({node->right, depth + 1});
//             }
//         }
//         // This line is technically unreachable because the tree is non-empty.
//         return 0;
//     }
// };



int main() {
    
    return 0;
}