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

void preorder(node *root){      // root left right
    if(root != nullptr){
        cout<<" "<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root){      // left root right
    if(root != nullptr){
        inorder(root->left);
        cout<<" "<<root->data<<" ";
        inorder(root->right);
    }
}

void postorder(node *root){      // left right root
    if(root != nullptr){
        postorder(root->left);
        postorder(root->right);
        cout<<" "<<root->data<<" ";
    }
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

    cout<<"Preorder : ";
    preorder(root);
    cout<<endl;
    cout<<"Inorder  : ";
    inorder(root);
    cout<<endl;
    cout<<"Postorder: ";
    postorder(root);
    cout<<endl;
    return 0;
}