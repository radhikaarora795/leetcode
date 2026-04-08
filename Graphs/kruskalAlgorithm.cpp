#include <iostream>
using namespace std;

class DisjointSet{
    vector<int> parent;
    vector<int> rank;
public:
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
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        sort(edges.begin(),edges.end(),[](vector<int> &a, vector<int> &b){
            return a[2]<b[2];
        });
        
        DisjointSet d(V);
        int sum=0;
        
        for(auto &e : edges){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            
            if(d.find(u) != d.find(v)){
                d.unionByRank(u,v);
                sum+=wt;
            }
        }
        return sum;
    }
};

int main() {
    
    return 0;
}