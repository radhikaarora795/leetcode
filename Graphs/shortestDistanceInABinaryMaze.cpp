#include <iostream>
using namespace std;

// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        if (source.first == destination.first && source.second == destination.second) {
            return 0;
        }
        
        int n=grid.size();
        int m=grid[0].size();
        
        if(grid[source.first][source.second] == 0 || grid[destination.first][destination.second] == 0){
            return -1;
        }
        
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[source.first][source.second]=0;
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{source.first, source.second}});
        
        while(!q.empty()){
            int d=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            
            int delRow[]={-1,0,1,0};
            int delCol[]={0,1,0,-1};
            
            for(int i=0;i<4;i++){
                int newR=r+delRow[i];
                int newC=c+delCol[i];
                
                if(newR<n && newC<m && newR>=0 && newC>=0 && grid[newR][newC] == 1 && d+1<dist[newR][newC]){
                    dist[newR][newC]=1+d;
                    if(newR==destination.first && newC==destination.second){
                        return d+1;
                    }
                    q.push({d+1,{newR,newC}});
                }
            }
        }
        return -1;
    }
};


int main() {
    
    return 0;
}