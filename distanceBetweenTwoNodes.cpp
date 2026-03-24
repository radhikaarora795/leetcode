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

void inorder(node *root){      // left root right
    if(root != nullptr){
        inorder(root->left);
        cout<<" "<<root->data<<" ";
        inorder(root->right);
    }
}

// lca: least common ancestor as path from p to q goes through lca 
// therefore path = lca+p  +   lca+q
// p,q: data of nodes 
node *lca(node *root,int p,int q){
    if(root == nullptr){
        return nullptr;
    }
    if(root->data == p || root->data == q){
        return root;
    }
    node *left=lca(root->left,p,q);
    node *right=lca(root->right,p,q);

    if(left != nullptr && right != nullptr){
        return root;
    }

    if(left != nullptr){
        return left;
    }
    
    if(right != nullptr){
        return right;
    }
    return nullptr;
}

int distanceFromNode(node* root, int target) {
        if (!root) return -1;
        if (root->data == target) return 0;

        int left = distanceFromNode(root->left, target);
        if (left != -1) return left + 1;

        int right = distanceFromNode(root->right, target);
        if (right != -1) return right + 1;

        return -1;
    }

int distance(node *root,int p,int q){
    node *ptr=lca(root,p,q);
    int d1=distanceFromNode(ptr,p);
    int d2=distanceFromNode(ptr,q);
    return d1+d2;
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
    inorder(root);
    cout<<endl;
    node *ptr=lca(root,20,40);
    cout<<ptr->data<<endl;
    cout<<distance(root,20,80);

    return 0;
}