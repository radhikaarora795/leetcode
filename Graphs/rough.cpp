#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(vector<vector<int>>& adjList,int start,vector<bool>& visited){
    visited[start]=true;
    cout<<start<<" ";
    for(auto &i:adjList[start]){
        if(!visited[i]){
            dfs(adjList,i,visited);
        }
    }
}

void bfs(vector<vector<int>>& adjList,int start){
    int n=adjList.size();
    vector<bool> visited(n,false);
    queue<int> q;
    q.push(start);
    visited[start]=true;

    while(!q.empty()){
        int v=q.front();
        q.pop();
        cout<<v<<" ";
        for(auto &i:adjList[v]){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}

int main() {
    int n=7;
    vector<vector<int>> edges={
        {0,1},{0,3},{1,2},{2,3},{2,6},{3,4},{4,5},{5,6}
    };

    vector<vector<int>> adjList(n);

    for(auto &e:edges){
        adjList[e[0]].push_back(e[1]);
        adjList[e[1]].push_back(e[0]);
    }

    vector<bool> visited(n,false);

    dfs(adjList,0,visited);
    cout<<endl;
    bfs(adjList,0);
    
    return 0;
}