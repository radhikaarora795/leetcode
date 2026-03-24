#include <iostream>
using namespace std;

// better time complexity if we use vector<vector>> instead of unordered map

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        // Step 1: Adjacency list (faster than unordered_map)
        vector<vector<int>> adj(n);
        // for(auto &e : edges){
        //     adj[e[0]].push_back(e[1]);
        //     adj[e[1]].push_back(e[0]);
        // }
        /*
        adj mei e[0] row mei push e[1] 
        */
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        // Step 2: BFS
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(source);
        visited[source] = true;  // IMPORTANT

        while(!q.empty()){
            int v = q.front();
            q.pop();

            if(v == destination) return true;

            for(auto &item : adj[v]){
                if(!visited[item]){
                    visited[item] = true;
                    q.push(item);
                }
            }
        }

        return false;
    }
};

int main() {
    
    return 0;
}