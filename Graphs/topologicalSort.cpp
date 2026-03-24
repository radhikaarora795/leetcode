#include <iostream>
using namespace std;

class Solution {
  public:
    void dfs(int start, vector<vector<int>> &adjList, vector<bool> &visited,stack<int> &s){
        visited[start]=true;
        for(auto &i:adjList[start]){
            if(!visited[i]){
                dfs(i,adjList,visited,s);
            }
        }
        s.push(start);
    }
 
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adjList(V);
        for(auto &e:edges){
            adjList[e[0]].push_back(e[1]);
        }
        vector<bool> visited(V,false);
        stack<int> s;
        vector<int> ans;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adjList,visited,s);
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};

int main() {
    
    return 0;
}