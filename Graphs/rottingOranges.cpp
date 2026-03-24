#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();      // rows in grid
        int m=grid[0].size();   // cols
        int fresh = 0;
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int time=0;
        while(!q.empty() && fresh>0){
            int length=q.size();

            for(int k=0;k<length;k++){
                int i=q.front().first;
                int j=q.front().second;

                q.pop();
                if(i-1>=0 && grid[i-1][j]==1){   // top
                    q.push({i-1,j});
                    grid[i-1][j]=2;
                    fresh--;
                }
                if(j-1>=0 && grid[i][j-1]==1){   // left
                    q.push({i,j-1});
                    grid[i][j-1]=2;
                    fresh--;
                }
                if(i+1<n && grid[i+1][j]==1){   //  bottom
                    q.push({i+1,j});
                    grid[i+1][j]=2;
                    fresh--;
                }
                if(j+1<m && grid[i][j+1]==1){   //  right
                    q.push({i,j+1});
                    grid[i][j+1]=2;
                    fresh--;
                }
            }
            time++;
        }
        if(fresh > 0){
            return -1;
        }
        return time;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid={
        {2,1,1}, {1,1,0}, {0,1,1}
    };
    cout<<s.orangesRotting(grid);
    
    return 0;
}