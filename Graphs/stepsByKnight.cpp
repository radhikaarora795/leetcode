#include <iostream>
using namespace std;

class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        vector<vector<int>> coordinates={
            {-2,-1},{-2,1},{2,-1},{2,1},{-1,-2},{-1,2},{1,-2},{1,2}
        };
        
        vector<int> newKnightPos(2);
        newKnightPos[0]=n-knightPos[1];
        newKnightPos[1]=knightPos[0]-1;
        
        vector<int> newTargetPos(2);
        newTargetPos[0]=n-targetPos[1];
        newTargetPos[1]=targetPos[0]-1;
        
        vector<vector<int>> visited(n,vector<int>(n));
        queue<pair<int,int>> q; // q of coordinates 
        
        q.push({newKnightPos[0],newKnightPos[1]});
        visited[newKnightPos[0]][newKnightPos[1]]=1;
        int steps=0;
        // start bfs with level counting
        while(!q.empty()){
            int qSize=q.size();
            while(qSize>0){
                pair<int,int> v=q.front();
                int x=v.first;
                int y=v.second;
                q.pop();
                if(x==newTargetPos[0] && y==newTargetPos[1]){
                    return steps;
                }
                for(int k=0;k<coordinates.size();k++){
                    int newX=x+coordinates[k][0];
                    int newY=y+coordinates[k][1];
                    if(newX>=0 && newY>=0 && newX<n && newY<n && visited[newX][newY]==0){
                        visited[newX][newY]=1;
                        q.push({newX,newY});
                    }
                }
                qSize--;
            }
            steps++;
        }
        return steps;
    }
};

int main() {
    
    return 0;
}