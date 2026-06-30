#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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

void bfsMatrix(vector<vector<int>>& adjMatrix,int start){
    int n=adjMatrix.size(); // number of vertices 
    vector<bool> visited(n,false);
    queue<int> q;
    q.push(start);
    visited[start]=true;

    while(!q.empty()){
        int v=q.front();
        q.pop();
        cout<<v<<" ";
        for(int l=0;l<n;l++){
            if(adjMatrix[v][l]==1 && !visited[l]){
                q.push(l);
                visited[l]=true;
            }
        }
    }
}

void dfs(vector<vector<int>> &adjList,int start,vector<bool> &visited){
    visited[start]=true;
    cout<<start<<" ";
    for(auto &i:adjList[start]){
        if(!visited[i]){
            dfs(adjList,i,visited);
        }
    }
}

void dfsMatrix(vector<vector<int>> &adjMatrix,int start,vector<bool> &visited){
    int n=adjMatrix.size();
    visited[start]=true;
    cout<<start<<" ";
    for(int l=0;l<n;l++){
        if(adjMatrix[start][l]==1 && !visited[l]){
            dfsMatrix(adjMatrix,l,visited);
        }
    }
}

int minStepsBFS(vector<vector<int>>& adjList,int start,int target){
    int n=adjList.size();
    vector<bool> visited(n,false);
    queue<pair<int,int>> q;
    q.push({start,0});
    visited[start]=true;

    while(!q.empty()){
        int v=q.front().first;
        int steps=q.front().second;
        q.pop();

        if(v == target){
            return steps;
        }

        for(auto &i:adjList[v]){
            if(!visited[i]){
                q.push({i,steps+1});
                visited[i]=true;
            }
        }
    }
    return -1;
}

int main() {
    int n=7;
    vector<vector<int>> edges={
        {0,1},{0,3},{1,2},{2,3},{2,6},{3,4},{4,5},{5,6}
    };
    // int m=edges.size();

    vector<vector<int>> adjList(n);

    for(auto &e:edges){
        adjList[e[0]].push_back(e[1]);
        adjList[e[1]].push_back(e[0]);
    }

    cout<<minStepsBFS(adjList,1,5);

    // vector<vector<int>> adjMatrix(n,vector<int>(n,0));

    // for(auto &e:edges){
    //     int u=e[0];
    //     int v=e[1];
    //     adjMatrix[u][v]=1;
    //     adjMatrix[v][u]=1;
    // }

    // bfsMatrix(adjMatrix,0);

    // bfs(adjList,0);

    // vector<bool> visited(n,false);
    // dfsMatrix(adjMatrix,0,visited);

    // dfs(adjList,0,visited);
    
    return 0;
}