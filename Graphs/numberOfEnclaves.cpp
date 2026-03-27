#include <iostream>
using namespace std;

// User function Template for C++

class Solution {
  public:
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited){
        int n=grid.size();
        int m=grid[0].size();
        
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] != 1 || visited[i][j]==true) {
            return;
        }
        
        visited[i][j]=true;
        
        dfs(i-1,j,grid,visited);
        dfs(i,j-1,grid,visited);
        dfs(i+1,j,grid,visited);
        dfs(i,j+1,grid,visited);
    }
  
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(!visited[i][j] && grid[i][j] == 1){
                        dfs(i,j,grid,visited);
                    }
                }
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( !visited[i][j] && grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};


int main() {
    
    return 0;
}