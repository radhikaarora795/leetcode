#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int SCS(string X, string Y) {
        int n=X.size();
        int m=Y.size();

        // base case: If one string is empty, the SCS is the length of the other string.

        if(n == 0){
            return m;
        }
        if(m == 0){
            return n;
        }

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(X[i-1] == Y[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        return n+m-dp[n][m];
    }
};

int main() {
    string X="abac";
    string Y="cab";
    // int n=X.size();
    // int y=Y.size();

    Solution s;

    cout<<s.SCS(X,Y);
    
    return 0;
}