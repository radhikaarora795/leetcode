#include <iostream>
using namespace std;

class Solution {
  public:
   
    bool dfs(int start,vector<vector<int>> &adjList,vector<bool> &visited,vector<bool> &recursionPath){
        visited[start]=true;
        recursionPath[start]=true;
        for(auto &i:adjList[start]){
            if(!visited[i]){
                if(dfs(i,adjList,visited,recursionPath)){
                    return true;
                }
            }
            else if(recursionPath[i]){
                return true;
            }
        }
        recursionPath[start]=false;
        return false;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adjList(V);
        
        for(auto &e:edges){
            adjList[e[0]].push_back(e[1]);
        }
        
        vector<bool> visited(V,false);
        vector<bool> recursionPath(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
               if(dfs(i,adjList,visited,recursionPath)){
                   return true;
               }
            }
        }
        return false;
    }
};

int main() {
    
    return 0;
}