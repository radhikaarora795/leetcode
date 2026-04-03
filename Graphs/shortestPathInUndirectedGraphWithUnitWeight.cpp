#include <iostream>
using namespace std;

// gfg : Shortest Path in Undirected Graph


class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<vector<int>> adjList(V);
        vector<int> dist(V,INT_MAX);
        queue<int> q;
        
        for(auto &e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        
        q.push(src);
        dist[src]=0;
        
        while(!q.empty()){
            int v=q.front();
            q.pop();
            
            for(auto &i : adjList[v]){
                if(dist[i] == INT_MAX){     // if !visited
                    dist[i]=dist[v]+1;      // dist[neighbour]=1+dist[currNode]
                    q.push(i);
                }
            }
        }
        
        for(int i=0;i<V;i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};


int main() {
    
    return 0;
}