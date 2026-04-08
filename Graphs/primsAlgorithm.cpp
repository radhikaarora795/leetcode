#include <iostream>
using namespace std;

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        
        typedef pair<int,int> pii;
        
        vector<vector<pair<int,int>>> adjList(V);
        for(auto &e : edges){
            adjList[e[0]].push_back({e[1],e[2]});
            adjList[e[1]].push_back({e[0],e[2]});
        }
        vector<bool> visited(V,false);
        priority_queue<pii,vector<pii>,greater<pii>> pq;    // wt, node
        pq.push({0,0});
        int sum=0;
        
        while(!pq.empty()){
            auto [wt, u]=pq.top();
            pq.pop();
            
            if(visited[u]){
                continue;
            }
            
            visited[u]=true;
            sum+=wt;
            
            for(auto &i : adjList[u]){
                int v=i.first;
                int w=i.second;
                pq.push({w,v});
            }
        }
        return sum;
    }
};

int main() {
    
    return 0;
}