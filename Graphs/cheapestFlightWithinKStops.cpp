#include <iostream>
#include <tuple>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adjList(n);
        for(auto &f : flights){
            int u=f[0];
            int v=f[1];
            int wt=f[2];
            adjList[u].push_back({v,wt});
        }
        vector<int> dist(n,INT_MAX);
        dist[src]=0;

        queue<tuple<int,int,int>> q;    // node, cost, stops
        q.push({src,0,0});

        while(!q.empty()){
           auto [u, cost, stops]=q.front();
           q.pop();

           if(stops > k){
            continue;
           }

            for(auto &i : adjList[u]){
                int v=i.first;
                int wt=i.second;
                if(cost+wt < dist[v]){
                    dist[v]=cost+wt;
                    q.push({v,cost+wt,stops+1});    // similar to dijkstra
                }
            }
        }

        if(dist[dst] == INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};

int main() {
    
    return 0;
}