#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Graph{
    vector<vector<int>> adjacencyList;
    vector<bool> visited;
    vector<int> output;
public:
    Graph(int n){
        adjacencyList.resize(n+1);
        visited.resize(n+1,false);
    }
    void addEdge(int a, int b){
        // undirected graph;
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a); 
    }

    void bfs(int start){
        queue<int> q;
        q.push(start);
        visited[start]=true;
        while(!q.empty()){
            int v=q.front();
            q.pop();
            output.push_back(v);
            for(auto item : adjacencyList[v]){  
                if(!visited[item]){
                    q.push(item);
                    visited[item]=true;
                }
            }
        }
    }
    void printGraph(int n){
        for (int i=1;i<=n;i++){
            cout << i << " : ";
            for(auto j : adjacencyList[i]){
                cout<<j<<" ";
            }
            cout<<endl;
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

    g.printGraph(7);
    cout<<endl<<endl;
    g.bfs(1);
    g.printOutput();
    
    return 0;
}