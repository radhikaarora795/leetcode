#include <iostream>
using namespace std;

// User function Template for C++

class DisjointSet{
public:
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    
    int find(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    
    void unionByRank(int x,int y){
        int uParx=find(x);
        int uPary=find(y);
        if(uParx == uPary){
            return;
        }
        if(rank[uParx]<rank[uPary]){
            parent[uParx]=uPary;
        }
        else if(rank[uParx]>rank[uPary]){
            parent[uPary]=uParx;
        }
        else{
            parent[uPary]=uParx;
            rank[uParx]++;
        }
    }
};


class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        int extra=0;
        DisjointSet d(n);
        
        for(auto &e : edge){
            int u=e[0];
            int v=e[1];
            
            if(d.find(u) == d.find(v)){
                extra++;
            }
            else{
                d.unionByRank(u,v);
            }
        }
        
        // find number of components;
        int components=0;
        for(int i=0;i<n;i++){
            if(d.parent[i] == i){
                components++;
            }
        }
        
        if(extra>=components-1){
            return components-1;
        }
        else{
            return -1;
        }
    }
};

int main() {
    
    return 0;
}