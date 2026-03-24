#include <iostream>
using namespace std;

class Solution {
public:
    bool dfs(int start, vector<vector<int>> &adjList, vector<bool> &visited, vector<bool> &recursionPath){
        visited[start]=true;
        recursionPath[start]=true;

        for(auto &i:adjList[start]){
            if(!visited[i]){
                if(dfs(i,adjList,visited,recursionPath)){
                    return true;
                }
            }
            else if(recursionPath[i]){
                return true;
            }
        }
        recursionPath[start]=false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(auto &p:prerequisites){
            adjList[p[0]].push_back(p[1]);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> recursionPath(numCourses, false);

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i,adjList,visited,recursionPath)){
                    return false;   // if cycle exists cannot finish
                }
            }
        }
        return true;
    }
};

int main() {
    
    return 0;
}