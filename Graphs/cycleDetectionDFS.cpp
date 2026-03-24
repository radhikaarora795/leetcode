#include <iostream>
using namespace std;

class Solution {
  public:
  bool dfs(int start, int parent, vector<bool>& visited, vector<vector<int>>& adjList){
      visited[start]=true;
      for(auto &i:adjList[start]){
          if(!visited[i]){
              if(dfs(i,start,visited,adjList)){
                  return true;
              }
          }
          else if(i!=parent){
              return true;
          }
      }
      return false;
  }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adjList(V);
        for(auto &e:edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        vector<bool> visited(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,-1,visited,adjList)){
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