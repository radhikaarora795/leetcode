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

bool search(node *root,int val){
    if(root == nullptr){
        return false;
    }
    bool left=search(root->left,val);
    bool right=search(root->right,val);

    return left || right || root->data == val;
}

node* searchNode(node *root,int val){
    if(root == nullptr){
        return nullptr;
    }
    node *left=searchNode(root->left,val);
    node *right=searchNode(root->right,val);

    if(left != nullptr && left->data == val){
        return left;
    } else if(right != nullptr && right->data == val){
        return right;
    } else if(root!= nullptr && root->data == val){
        return root;
    }
    return nullptr;
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

    //cout<<search(root,50);
    node *ptr=searchNode(root,40);
    cout<<ptr->data;
    return 0;
}