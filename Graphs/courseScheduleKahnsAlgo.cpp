#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& p : prerequisites) {
            adjList[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);

            for (auto& i : adjList[curr]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
        }

        if (ans.size() != numCourses) {
            return {};
        }

        return ans;
    }
};

int main() {
    
    return 0;
}