#include <iostream>
using namespace std;

class Solution {
  public:
  
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adjList(V);
        vector<int> indegree(V,0);
        for(auto &e : edges){
            adjList[e[1]].push_back(e[0]);      // reverse graph u->v adjList: v->u
            indegree[e[0]]++;                   // so we calculate indegree of u
        }
        
        vector<bool> visted(V,false);
        queue<int> q;
        
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto &i : adjList[curr]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        
        vector<int> safeStates;
        
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                safeStates.push_back(i);
            }
        }
        
        return safeStates;
    }
};

int main() {
    
    return 0;
}