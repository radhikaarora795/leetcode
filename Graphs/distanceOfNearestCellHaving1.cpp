#include <iostream>
using namespace std;

class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m));
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    dist[i][j]=0;
                    q.push({{i,j},0});
                    visited[i][j]=true;
                }
            }
        }
        
        int delRow[]={-1,0,1,0};
        int delCol[]={0,-1,0,1};
        
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            dist[row][col]=steps;  
            
            for(int k=0;k<4;k++){
                int nRow=row+delRow[k];
                int nCol=col+delCol[k];
                
                if(nRow>=0 && nCol>=0 && nRow<n && nCol<m && !visited[nRow][nCol]){
                    q.push({{nRow,nCol},steps+1});
                    visited[nRow][nCol]=true;
                }
            }
        }
        
        return dist;
    }
};

int main() {
    
    return 0;
}