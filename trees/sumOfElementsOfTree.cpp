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

int sum(node *root){
    if(root == nullptr){
        return 0;
    }
    int left=sum(root->left);
    int right=sum(root->right);
    return root->data + left + right;
}

int maximum(node *root){
    if(root == nullptr){
        return INT_MIN;
    }
    int left=maximum(root->left);
    int right=maximum(root->right);
    return max(root->data,max(left,right));
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

    // cout<<sum(root);
    cout<<maximum(root);
    
    return 0;
}