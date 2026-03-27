#include <iostream>
using namespace std;

// User function Template for C++

class Solution {
  public:
  void bfs(int V, int start, vector<vector<int>> &adj,vector<bool> &visited){
      queue<int> q;
      q.push(start);
      visited[start]=true;
      while(!q.empty()){
          int v=q.front();
          q.pop();
          for(int l=0;l<V;l++){
              if(adj[v][l]==1 && !visited[l]){
                  q.push(l);
                  visited[l]=true;
              }
          }
      }
  }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<bool> visited(V,false);
        int count=0;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bfs(V,i,adj,visited);
                count++;
            }
        }
        
        return count;
    }
};

int main() {
    
    return 0;
}