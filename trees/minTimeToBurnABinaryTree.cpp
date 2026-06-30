#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    Node* parentMapping(Node* root,int start,unordered_map<Node*,Node*>& parent){
        Node* target=nullptr;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            
            Node* ptr=q.front();
            q.pop();
            
            if(ptr->data == start){
                target=ptr;
            }
            
            if(ptr->left != nullptr){
                parent[ptr->left]=ptr;
                q.push(ptr->left);
            }
            
            if(ptr->right != nullptr){
                parent[ptr->right]=ptr;
                q.push(ptr->right);
            }
        }
        return target;
    }
    
    int burnTime(Node* target, unordered_map<Node*,Node*>& parent){
        queue<Node*> q;
        unordered_map<Node*,int> visited;       // node 0:not visited 1:visited
        
        q.push(target);
        visited[target]=1;
        
        int time=-1;
        
        while(!q.empty()){
            int s=q.size();
            time++;
            for(int i=0;i<s;i++){
                Node* ptr=q.front();
                q.pop();
                
                if(ptr->left != nullptr && !visited[ptr->left]){
                    visited[ptr->left]=1;
                    q.push(ptr->left);
                }
                
                if(ptr->right != nullptr && !visited[ptr->right]){
                    visited[ptr->right]=1;
                    q.push(ptr->right);
                }
                
                if(parent.count(ptr) && !visited[parent[ptr]]){
                    visited[parent[ptr]]=1;
                    q.push(parent[ptr]);
                }
            }
        }
        return time;
    }
  
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*,Node*> parent;
        Node* start=parentMapping(root,target,parent);
        return burnTime(start,parent);
    }
};

int main() {
    
    return 0;
}