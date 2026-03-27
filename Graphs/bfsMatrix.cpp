#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph{
    int n;  // number of vertices
    vector<vector<int>> adjacencyMatrix;
    vector<bool> visited;
    vector<int> output;
public:
    Graph(int V):n(V){
        adjacencyMatrix.resize(n+1,vector<int>(n+1,0));
        visited.resize(n+1,false);
    }
    void addEdge(int a, int b){
        // undirected graph;
        adjacencyMatrix[a][b]=1;
        adjacencyMatrix[b][a]=1;  
    }
    void printGraph(){
        for(int i=1;i<=n;i++){
            cout<<"Node: "<<i<<", Neighbours: ";
            for(int j=1;j<=n;j++){
                if(adjacencyMatrix[i][j]==1){
                    cout<<j<<" ";
                }
            }
            cout<<endl;
        }
    }

    void bfs(int start){
        queue<int> q;
        q.push(start);
        visited[start]=true;
        while(!q.empty()){
            int v=q.front();
            q.pop();
            output.push_back(v);
            for(int l=1;l<=n;l++){
                if(adjacencyMatrix[v][l]==1 && !visited[l]){
                    q.push(l);
                    visited[l]=true;    
                }
            }
                
            
        }
    }

    void printOutput(){
        for(auto i:output){
            cout<<i<<" ";
        }
    }
};

int main() {
    vector<vector<int>> edgeList ={
        {1,2}, {1,4}, {2,3}, {3,4}, {3,7}, {4,5} , {5,6}, {6,7}
    };
    Graph g(7);

    for(int i=0;i<edgeList.size();i++){
        g.addEdge(edgeList[i][0],edgeList[i][1]);
    }

    // g.printGraph();
    g.bfs(1);
    g.printOutput();

    
    return 0;
}