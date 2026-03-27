#include <iostream>
using namespace std;

class Solution {
  public:
    void dfs(int i, int j,vector<vector<char>>& grid, vector<vector<bool>>& visited){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] != 'O' || visited[i][j]==true){
            return;
        }
        visited[i][j]=true;
        dfs(i-1,j,grid,visited);
        dfs(i,j-1,grid,visited);
        dfs(i+1,j,grid,visited);
        dfs(i,j+1,grid,visited);
    }
  
    void fill(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        for(int j=0;j<m;j++){
            if(!visited[0][j] && grid[0][j] == 'O'){
                dfs(0,j,grid,visited);   
            }
            if(!visited[n-1][j] && grid[n-1][j] == 'O'){
                dfs(n-1,j,grid,visited);   
            }
        }
        
        for(int i=0;i<n;i++){
           if(!visited[i][0] && grid[i][0] == 'O'){
                dfs(i,0,grid,visited);   
            }
            if(!visited[i][m-1] && grid[i][m-1] == 'O'){
                dfs(i,m-1,grid,visited);   
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == 'O'){
                    grid[i][j]='X';
                }
            }
        }
        
    }
};

int main() {
    
    return 0;
}