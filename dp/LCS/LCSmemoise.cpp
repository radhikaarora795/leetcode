#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> dp;
public:
    Solution(int r, int c):dp(r+1, vector<int>(c+1, -1))
        {}

    int LCS(string X, string Y, int n, int m) {
        if(n == 0 || m == 0){
            return 0;
        }
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        if(X[n-1] == Y[m-1]){
            return dp[n][m] = 1+LCS(X,Y,n-1,m-1);
        }
        else{
            return dp[n][m] = max(LCS(X,Y,n,m-1), LCS(X,Y,n-1,m));
        }
    }
};

int main() {
    string X="abc";
    string Y="abc";
    // int n=X.size();
    // int y=Y.size();

    Solution s(X.size(),Y.size());

    cout<<s.LCS(X,Y,X.size(),Y.size());
    
    return 0;
}