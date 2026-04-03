#include <iostream>
#include <set>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adjList(V);
        for(auto &e : edges){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
        
        vector<int> dist(V,INT_MAX);
        set<pair<int,int>> s;       // distance, node
        dist[src]=0;
        s.insert({0,src});
        
        while(!s.empty()){
            auto it=*(s.begin());
            int d=it.first;
            int u=it.second;
            s.erase(it);
            
            for(auto &i : adjList[u]){
                int v=i.first;
                int wt=i.second;
                
                if(dist[v] > dist[u] + wt){
                    if(dist[v] != INT_MAX){     // if already present remove old entry
                        s.erase({dist[v],v});   // similar to q.pop()
                    }
                    dist[v]=dist[u]+wt;
                    s.insert({dist[v],v});
                }
            }
        }
        return dist;
    }
};

int main() {
    
    return 0;
}