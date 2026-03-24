#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Graph{
    unordered_map<int,vector<int>> adjacencyList;
    vector<bool> visited;
    vector<int> output;
public:
    Graph(int n){
        visited.resize(n+1,false);
    }
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
    void bfs(int start){
        queue<int> q;
        q.push(start);
        visited[start]=true;
        while(!q.empty()){
            int v=q.front();
            q.pop();
            output.push_back(v);
            for(auto item : adjacencyList[v]){  // item automatically vector ban jaayega
                if(!visited[item]){
                    q.push(item);
                    visited[item]=true;
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