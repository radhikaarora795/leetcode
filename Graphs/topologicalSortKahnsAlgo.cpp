#include <iostream>
using namespace std;

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adjList(V);
        vector<int> indegree(V,0);
        for(auto &e: edges){
            adjList[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        
        queue<int> q;
        
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            for(auto &i: adjList[curr]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        
        if(ans.size() != V){
            return {};      // cycle exists;
        }
        
        return ans;
    }
};

int main() {
    
    return 0;
}