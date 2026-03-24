#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    int rows;
    int cols;
    vector<vector<int>> dp;
public:
    Solution(int r,int c):rows(r),cols(c),dp(r+1, vector<int>(c+1, -1))
        {}
    int knapsack(vector<int>& wt,vector<int>& val,int W,int n){
        if(W==0 || n==0){
            return 0;
        }
        if(dp[n][W] != -1){
            return dp[n][W];
        }
        if(wt[n-1] <= W){
            return dp[n][W] = max( (val[n-1]+knapsack(wt,val,W-wt[n-1],n-1)) , knapsack(wt,val,W,n-1));
        }
        else{
            return dp[n][W] = knapsack(wt,val,W,n-1);
        }
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