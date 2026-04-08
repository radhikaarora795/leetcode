#include <iostream>
using namespace std;

// User function Template for C++
class DisjointSet{
public:
    vector<int> parent;
    vector<int> size;
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
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
    void unionBySize(int u, int v){
        int uParu=find(u);
        int uParv=find(v);
        if(uParu == uParv){
            return;
        }
        if(size[uParu]<size[uParv]){
            parent[uParu]=uParv;
            size[uParv]+=size[uParu];
        }
        else{
            parent[uParv]=uParu;
            size[uParu]+=size[uParv];
        }
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        int visited[n][m];
        memset(visited,0,sizeof(visited));
        int count=0;
        vector<int> ans;
        DisjointSet d(n*m);
        
        for(auto &op : operators){
            int row=op[0];
            int col=op[1];
            
            if(visited[row][col] == 1){
                ans.push_back(count);
                continue;
            }
            visited[row][col]=1;
            count++;
            int delRow[]={-1,0,1,0};
            int delCol[]={0,1,0,-1};
            
            int node=row*m+col;
            
            for(int i=0;i<4;i++){
                int newRow=row+delRow[i];
                int newCol=col+delCol[i];
                
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && visited[newRow][newCol] == 1){
                    int adjNode=newRow*m+newCol;
                    if(d.find(node) != d.find(adjNode)){
                        count--;
                        d.unionBySize(node,adjNode);
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};


int main() {
    
    return 0;
}