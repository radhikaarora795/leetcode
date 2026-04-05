#include <iostream>
using namespace std;

// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        const int mod=100000;
        queue<pair<int,int>> q;     // node, steps
        q.push({start,0});
        
        vector<int> dist(mod,INT_MAX);
        dist[start]=0;
        
        while(!q.empty()){
            int node=q.front().first;
            int steps=q.front().second;
            q.pop();
            
            if(node == end){
                return steps;
            }
            
            for(int i : arr){
                int newNode = (node*i) % mod;
                if(steps+1 < dist[newNode]){
                    dist[newNode]=steps+1;
                    q.push({newNode,steps+1});
                }
            }
        }
        return -1;
    }
};


int main() {
    
    return 0;
}