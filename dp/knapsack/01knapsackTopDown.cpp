#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    int rows;
    int cols;
    vector<vector<int>> dp;
public:
    Solution(int r,int c):rows(r),cols(c),dp(r+1, vector<int>(c+1,0))
        {}
    int knapsack(vector<int>& wt,vector<int>& val,int W,int n){
        if(n==0 || W==0){
            return 0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<W+1;j++){
                if(wt[i-1]<=j){
                    dp[i][j]=max( (val[i-1]+dp[i-1][j-wt[i-1]]), dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][W];
    }
};

int main() {
    vector<int> wt={1,3,4,5};
    vector<int> val={1,4,5,7};
    int W=7;
    Solution s(val.size(),W);
    cout<<s.knapsack(wt,val,W,val.size());
    
    return 0;
}