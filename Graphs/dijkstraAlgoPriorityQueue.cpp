#include <iostream>
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
        dist[src]=0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;    // kya jaayega, container(priority queue is a vector of pairs), for min heap(greater wala)
        pq.push({0,src});   // push {dist,source}
        while(!pq.empty()){
            int d=pq.top().first;
            int u=pq.top().second;      
            pq.pop();
            
            if(d > dist[u]){
                continue;
            }
            
            for(auto &i : adjList[u]){
                int v=i.first;
                int wt=i.second;    // in adjacency list
                if(dist[v] > dist[u] + wt){
                    dist[v]=dist[u]+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
};

int main() {
    
    return 0;
}