#include <iostream>
using namespace std;

class Solution {
public:
    int dfs(int start,vector<vector<int>> &forward, vector<vector<int>> &backward, int &ans, vector<bool>& visited){
        visited[start]=true;
        for(auto& item:forward[start]){
            if(!visited[item]){
                ans++;
                dfs(item,forward,backward,ans,visited);
            }
        }
        for(auto& item:backward[start]){
            if(!visited[item]){
                dfs(item,forward,backward,ans,visited);
            }
        }
        return ans;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
       vector<vector<int>> forward(n);
       vector<vector<int>> backward(n);
       vector<bool> visited(n,false);
        int ans=0;
        for(auto &c:connections){
            forward[c[0]].push_back(c[1]);
            backward[c[1]].push_back(c[0]);
        }
        return dfs(0,forward,backward,ans,visited);
    }
};

int main() {
    
    return 0;
}