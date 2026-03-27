#include <iostream>
using namespace std;

class Solution {
  public:
    bool bfs(int start,int V, vector<vector<int>> &adjList, vector<int>& colour){
        colour[start]=0;
        queue<int> q;
        q.push(start);
        
        while(!q.empty()){
            int v=q.front();
            q.pop();
            for(auto &i : adjList[v]){
                if(colour[i] == -1){
                    colour[i]=!colour[v];
                    q.push(i);
                }
                else if(colour[v] == colour[i]){
                    return false;
                }
            }
        }
        return true;
    }
  
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>> adjList(V);
        for(auto &e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        vector<int> colour(V,-1);
        
        for(int i=0;i<V;i++){
            if(colour[i]==-1){
                if(!bfs(i,V,adjList,colour)){
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    
    return 0;
}