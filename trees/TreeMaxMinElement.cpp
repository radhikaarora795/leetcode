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

int greatestOfThree(int a,int b,int c){
    int greatest=a;
    if(b>a){
        greatest=b;
    }
    if(c>greatest){
        greatest=c;
    }
    return greatest;
}

int maxElement(node *root){
    if(root == nullptr){
        return 0;
    }
    int left=maxElement(root->left);
    int right=maxElement(root->right);
    return greatestOfThree(root->data,left,right);
}

int smallestOfThree(int a,int b,int c){
    int smallest=a;
    if(b<a){
        smallest=b;
    }
    if(c<smallest){
        smallest=c;
    }
    return smallest;
}

int minElement(node *root){
    if(root == nullptr){
        return INT_MAX;
    }
    int left=minElement(root->left);
    int right=minElement(root->right);
    return smallestOfThree(root->data,left,right);
}

int heightOfTree(node *root){
    if(root == nullptr){
        return 0;
    }
    int left=heightOfTree(root->left);
    int right=heightOfTree(root->right);
    return 1+max(left,right);
}

int main() {
    node *root=nullptr;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    cout<<minElement(root);
    
    return 0;
}