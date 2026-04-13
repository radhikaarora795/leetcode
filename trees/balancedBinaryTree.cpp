#include <iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;

    node(int d): data(d), left(nullptr), right(nullptr)
        {}
};

node *insertNode(node *root, int data){
    if(root == nullptr){
        return new node(data);
    }

    if(data<=root->data){
        root->left=insertNode(root->left,data);
    }
    else{
        root->right=insertNode(root->right,data);
    }

    return root;
}


class Solution {
public:
    int height(node* root) {
        if (root == nullptr)
            return 0;

        int leftHeight = height(root->left);
        if (leftHeight == -1) return -1;    

        int rightHeight = height(root->right);
        if (rightHeight == -1) return -1;

        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(node* root) {
        return height(root) != -1;
    }
};


int main() {
    
    return 0;
}