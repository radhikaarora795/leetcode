#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int d): data(d), left(nullptr), right(nullptr)
        {}
};

// User function Template for C++

class Solution {
  public:
    int countNodes(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + countNodes(root->left) 
                 + countNodes(root->right);
    }
};

int main() {
    
    return 0;
}