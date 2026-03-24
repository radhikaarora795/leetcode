#include <iostream>
using namespace std;

class Solution {
  public:
    bool bfs(int start,vector<bool>& visited, vector<vector<int>>& adjList){
        queue<pair<int,int>> q;
        q.push({start,-1});
        visited[start]=true;
        while(!q.empty()){
            pair<int,int> p=q.front();
            int v=p.first;
            int parent=p.second;
            q.pop();
            for(auto i:adjList[v]){
                if(!visited[i]){
                    q.push({i,v});
                    visited[i]=true;
                }
                else if(i!=parent){
                    return true;
                }
            }
        }
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adjList(V);
        vector<bool> visited(V,false);
        for(auto &e:edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }   
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(bfs(i,visited,adjList)){
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