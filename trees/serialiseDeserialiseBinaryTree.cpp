#include <iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    void dfs(TreeNode* root, string& ans){
        if(root == nullptr){
            ans+="#,";
            return;
        }
        
        ans+=to_string(root->val);
        ans+=",";
        ans+=serialize(root->left);
        ans+=serialize(root->right);
    }

    string serialize(TreeNode* root) {
        string ans="";
        dfs(root,ans);
        return ans;
    }

    TreeNode* build(string& data, int& i){
        if(data[i] == '#'){
            i+=2;
            return nullptr;
        }
        //int n=data.size();
        string temp="";
        while(data[i] != ','){
            temp+=data[i];
            i++;
        }
        i++;    // skip ,
        int rootData=stoi(temp);
        TreeNode* root=new TreeNode(rootData);
        root->left=build(data,i);
        root->right=build(data,i);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
       return build(data,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main() {
    
    return 0;
}