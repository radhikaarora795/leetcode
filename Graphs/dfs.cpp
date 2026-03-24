#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
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
    void dfs(int start){
        stack<int> s;
        s.push(start);
        visited[start]=true;
        while(!s.empty()){
            int v=s.top();
            s.pop();
            output.push_back(v);
            for(auto item : adjacencyList[v]){                        
                if(!visited[item]){
                    s.push(item);
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

    g.dfs(1);
    g.printOutput();
    
    return 0;
}