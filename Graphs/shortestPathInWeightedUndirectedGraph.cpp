#include <iostream>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>> adjList(n+1);
        for(auto &e : edges){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
        
        vector<int> dist(n+1,INT_MAX);
        dist[1]=0;
        
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,1});
        
        while(!pq.empty()){
            int d=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            
            if(d > dist[u]){
                    continue;
            }
            
            for(auto &i : adjList[u]){
                int v=i.first;
                int wt=i.second;
                
                if(dist[v] > dist[u]+wt){
                    dist[v] = dist[u]+wt;
                    pq.push({dist[v],v});
                    parent[v]=u;
                }
            }
        }
        
        if(dist[n] == INT_MAX){
            return {-1};
        }
        
       vector<int> path;
        int node = n;
        
        // Trace back until we reach the source (node 1)
        /*
        loop terminates when a node is its own parent (the source) or use a specific marker (like -1).
        */
        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        
        // Add the total weight as the first element per problem requirements
        path.push_back(dist[n]);
        
        reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    
    return 0;
}