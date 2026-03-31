#include <iostream>
using namespace std;

// User function Template for C++
class Solution {
  public:
    void dfsTopoSort(int start,vector<vector<pair<int,int>>> &adjList,vector<bool> &visited,stack<int> &s){
        visited[start]=true;
        for(auto &i:adjList[start]){
            if(!visited[i.first]){
                dfsTopoSort(i.first,adjList,visited,s);
            }
        }
        s.push(start);
    }
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adjList(V);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            adjList[u].push_back({v,wt});
        }
        vector<bool> visited(V, false);
        stack<int> s;
        vector<int> dist(V,INT_MAX);
        dist[0]=0;  // source 0;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfsTopoSort(i,adjList,visited,s);
            }
        }
        
        while(!s.empty()){
            int u=s.top();
            s.pop();
            
            for(auto &i : adjList[u]){
                int v=i.first;
                int wt=i.second;
                    
                if(dist[u]!= INT_MAX && dist[u]+wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        for(int i = 0; i < V; i++){
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