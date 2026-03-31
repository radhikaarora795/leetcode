#include <iostream>
using namespace std;

class Solution {
  public:
    bool dfs(int start, vector<vector<int>>& adjList, vector<bool>& visited, vector<bool>& pathVisited, vector<bool>& safe){ 
        visited[start]=true;
        pathVisited[start]=true;
        
        for(auto &i:adjList[start]){
            if(!visited[i]){
                if(dfs(i,adjList,visited,pathVisited,safe)){
                    safe[start]=false;
                    return true;
                }
            }
            else if(pathVisited[i]){
                safe[start]=false;
                return true;
            }
        }
        safe[start]=true;
        pathVisited[start]=false;
        return false;
    }
  
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adjList(V);
        for(auto &e:edges){
            adjList[e[0]].push_back(e[1]);
        }
        
        vector<bool> visited(V, false);
        vector<bool> pathVisited(V,false);
        vector<bool> safe(V,false);     // tells which nodes are safe
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i, adjList, visited, pathVisited, safe);
            }
        }
        
        vector<int> result;
        for(int i=0;i<V;i++){
            if(safe[i]){
                result.push_back(i);
            }
        }
        
        return result;
    }
};

int main() {
    
    return 0;
}