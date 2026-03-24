#include <iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;

    node(int d): data(d), left(nullptr), right(nullptr)
        {}
};

void preorder(node *root){      // left root right
    if(root != nullptr){
        cout<<" "<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}


int main() {
    node *root= new node(1);
    root->left= new node(2);
    root->right= new node(3);
    root->left->left= new node(4);
    root->left->right= new node(5);
    root->right->left= new node(6);
    preorder(root);
    return 0;
}