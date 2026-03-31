#include <iostream>
using namespace std;

class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        int n=words.size();
        vector<vector<int>> adjList(26);
        vector<bool> visited(26, false);
        vector<int> indegree(26, 0);
        vector<bool> present(26,false);
        queue<int> q;
        string result="";
        int count=0;    // number of unique characters
        
        for(auto &word:words){
            for(auto &ch:word){
                present[ch-'a']=true;
            }
        }
        
        for(int i=0;i<26;i++){
            if(present[i]){
                count++;
            }
        }
        
        for(int i=0;i<n-1;i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.size(), s2.size());

            if(s1.size() > s2.size() && s1.substr(0, len) == s2){
                return "";
            }
            for(int j=0;j<len;j++){
                if(s1[j] != s2[j]){
                    adjList[s1[j]-'a'].push_back(s2[j]-'a');
                    indegree[s2[j]-'a']++;
                     break;
                }
            }
        } 

        for(int i=0;i<26;i++){
            if(present[i] && indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            result+=(char)(curr+'a');
            for(auto &i : adjList[curr]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        
        if(result.size() != count){
            return "";
        }
        
        return result;
    }
};

int main() {
    
    return 0;
}