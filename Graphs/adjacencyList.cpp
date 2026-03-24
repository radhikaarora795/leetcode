#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Graph{
    int n;  // number of vertices
    unordered_map<int,vector<int>> adjacencyList;
public:
    void addEdge(int a, int b){
        // undirected graph;
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a); 
    }
    void printGraph(){
        for(auto i : adjacencyList){
            cout<<i.first<<" : ";
            for (auto j : i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        } 
    }
};

int main() {
    vector<vector<int>> edgeList ={
        {1,2}, {2,3}, {3,4}, {4,2}, {1,3}
    };
    Graph g;

    for(int i=0;i<edgeList.size();i++){
        g.addEdge(edgeList[i][0],edgeList[i][1]);
    }

    g.printGraph();
    
    return 0;
}