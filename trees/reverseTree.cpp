#include <iostream>
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

void inorder(node *root){      // left root right
    if(root != nullptr){
        inorder(root->left);
        cout<<" "<<root->data<<" ";
        inorder(root->right);
    }
}

void preorder(node *root){
    if(root != nullptr){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

node* reverseTree(node *root){
    if(root == nullptr){
        return nullptr;
    }
    reverseTree(root->left);
    reverseTree(root->right);
    swap(root->left,root->right);
    return root;
}

int main() {
    node *root=nullptr;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    preorder(root);
    cout<<endl;
    root=reverseTree(root);
    preorder(root);

    
    return 0;
}