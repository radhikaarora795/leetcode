#include <iostream>
#include <vector>
using namespace std;

class Graph{
    int n;  // number of vertices
    vector<vector<int>> adjacencyMatrix;
public:
    Graph(int V):n(V){
        adjacencyMatrix.resize(n+1,vector<int>(n+1,0));
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
};

int main() {
    vector<vector<int>> edgeList ={
        {1,2}, {2,3}, {3,4}, {4,2}, {1,3}
    };
    Graph g(4);

    for(int i=0;i<edgeList.size();i++){
        g.addEdge(edgeList[i][0],edgeList[i][1]);
    }

    g.printGraph();
    
    return 0;
}