#include <iostream>
using namespace std;

class Solution {
public:
    bool dfscycle(int start,vector<vector<int>> &adjList, vector<bool> &visited,vector<bool> &recursionPath){
        visited[start]=true;
        recursionPath[start]=true;
        for(auto &i:adjList[start]){
            if(!visited[i]){
                if(dfscycle(i,adjList,visited,recursionPath)){
                    return true;
                };
            }
            else if(recursionPath[i]){
                return true;
            }
        }
        recursionPath[start]=false;
        return false;
    }

    void dfsStack(int start,vector<vector<int>> &adjList, vector<bool> &visited, stack<int> &s){
        visited[start]=true;
        for(auto &i:adjList[start]){
            if(!visited[i]){
                dfsStack(i,adjList,visited,s);
            }
        }
        s.push(start);
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(auto &p:prerequisites){
            adjList[p[1]].push_back(p[0]);  // **
        }
        vector<bool> visited(numCourses,false);
        vector<bool> visited2(numCourses,false);
        vector<bool> recursionPath(numCourses,false);
        stack<int> s;

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfscycle(i,adjList,visited,recursionPath)){
                    return {};      // return empty vector
                }
                
                dfsStack(i,adjList,visited2,s);            
            }
        }

        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};

int main() {
    
    return 0;
}