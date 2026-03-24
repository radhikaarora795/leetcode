#include <iostream>
#include <queue>
using namespace std;

// BFS Traversal of Tree

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

void BFS(node *root){
    queue<node*> q;
    if(root!=nullptr){
        q.push(root);
    }

    while(!q.empty()){
        node *ptr=q.front();
        cout<<ptr->data<<" ";
        q.pop();
        if(ptr->left != nullptr){
            q.push(ptr->left);
        }
        if(ptr->right != nullptr){
            q.push(ptr->right);
        }
    }
}

// using BFS
int heightOfTree(node* root){
    queue<node*> q;
    int height=0;
    if(root != nullptr){
        q.push(root);
    }
    while(!q.empty()){
        int s=q.size();
        for(int i=0;i<s;i++){
            node* ptr=q.front();
            q.pop();
            if(ptr->left != nullptr){
                q.push(ptr->left);
            }
            if(ptr->right != nullptr){
                q.push(ptr->right);
            }
        }
        height++;
    }
    return height;
}

int heightOfTreeDFS(node* root){
    if(root == nullptr){
        return 0;
    }
    int left=heightOfTreeDFS(root->left);
    int right=heightOfTreeDFS(root->right);
    return 1+max(left,right);
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
    //inorder(root);
    cout<<endl;
    BFS(root);
    cout<<endl;
    // cout<<heightOfTreeDFS(root);
    
    return 0;
}