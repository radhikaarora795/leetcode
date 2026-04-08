#include <iostream>
#include <vector>
using namespace std;

class DisjointSet{
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUPar(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x]=findUPar(parent[x]);
    }

    void unionByRank(int u,int v){
        int Uparu=findUPar(u);
        int Uparv=findUPar(v);
        if(Uparu == Uparv){
            return;
        }
        if(rank[Uparu]>rank[Uparv]){
            parent[Uparv]=Uparu;
        }
        else if(rank[Uparu]<rank[Uparv]){
            parent[Uparu]=Uparv;
        }
        else{
            // rank of parent of u == rank of parent v
            parent[Uparv]=Uparu;
            rank[Uparu]++;
        }
    }

    void unionBySize(int u,int v){
        int Uparu=findUPar(u);
        int Uparv=findUPar(v);
        if(Uparu == Uparv){
            return;
        }
        if(size[Uparu]<size[Uparv]){
            parent[Uparu]=Uparv;
            size[Uparv]+=size[Uparu];
        }
        else{
            parent[Uparv]=Uparu;
            size[Uparu]+=size[Uparv];
        }
    }
};

int main() {
    DisjointSet d(7);
    d.unionBySize(1,2);
    d.unionBySize(2,3);
    d.unionBySize(4,5);
    d.unionBySize(6,7);
    d.unionBySize(5,6);

    if(d.findUPar(3) == d.findUPar(7)){
        cout<<"same"<<endl;
    }
    else{
        cout<<"not same"<<endl;
    }

    d.unionByRank(3,7);

    if(d.findUPar(3) == d.findUPar(7)){
        cout<<"same"<<endl;
    }
    else{
        cout<<"not same"<<endl;
    }
    
    return 0;
}