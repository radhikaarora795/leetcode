#include <iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;

    node(int d): data(d), left(nullptr), right(nullptr)
        {}
};

node *createNode(int data){
    return new node(data);
}

node *insertNode(node *root, int data){
    if(root == nullptr){
        // node *root=new node(data);
        // root=createNode(data);
        // return root;
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

int countLeafNodes(node *root){
    if(root == nullptr){
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr){
        return 1;
    }
    return countLeafNodes(root->left)+countLeafNodes(root->left);
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

}