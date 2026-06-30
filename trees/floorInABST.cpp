#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 

class Solution {
  public:
    int findMaxFork(Node* root, int x) {
        // code here
        int floor=-1;
        while(root != nullptr){
            if(root->data == x){
                floor=root->data;
                return floor;
            }
            if(x>root->data){
                floor=root->data;
                root=root->right;
            }
            else{
                root=root->left;
            }   
        }
        return floor;
    }
};

int main() {
    
    return 0;
}