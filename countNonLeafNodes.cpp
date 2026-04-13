#include <iostream>
using namespace std;

/*Structure of the node of the tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// you are required to complete this function
// the function should return the count of Non-Leaf Nodes

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int d): data(d), left(nullptr), right(nullptr)
        {}
};


class Solution {
  public:
    int countNonLeafNodes(Node* root) {
        if(root == nullptr){
            return 0;
        }

        // if it is a leaf node
        if(root->left == nullptr && root->right == nullptr){
            return 0;
        }

        // count current node + recurse
        return 1 + countNonLeafNodes(root->left) 
                 + countNonLeafNodes(root->right);
    }
};

int main() {
    
    return 0;
}