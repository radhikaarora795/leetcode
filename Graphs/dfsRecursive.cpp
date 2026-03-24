#include <iostream>
#include <vector>
using namespace std;

class Graph{
    int n;
    vector<vector<int>> adjList;
    vector<bool> visited;
public:
    Graph(int V):n(V){
        adjList.resize(n);
        visited.resize(n,false);
    }

    void addEdge(int a, int b){
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    void dfs(int start){
        visited[start]=true;
        cout<<start<<" ";
        for(auto i:adjList[start]){
            if(!visited[i]){
                dfs(i);
            }
        }
    }
};

int main() {
    vector<vector<int>> edgeList ={
        {1,2}, {1,4}, {2,3}, {3,4}, {3,7}, {4,5} , {5,6}, {6,7}
    };
    Graph g(8);

    for(int i=0;i<edgeList.size();i++){
        g.addEdge(edgeList[i][0],edgeList[i][1]);
    }
    g.dfs(1);
    
    return 0;
}