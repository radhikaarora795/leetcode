#include <iostream>
#include <vector>
#include <algorithm>
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


bool maxDepth(node* root) {      // recursive dfs approach
        if(root == nullptr){
            return 0;
        }
        bool left=maxDepth(root->left);
        bool right=maxDepth(root->right);
        return left == right ? true: false; 
        
    }

int main() {
    node *root=nullptr;
    root = insertNode(root, 50);
  //  root = insertNode(root, 30);
  //  root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
    cout << maxDepth(root);
    return 0;
}