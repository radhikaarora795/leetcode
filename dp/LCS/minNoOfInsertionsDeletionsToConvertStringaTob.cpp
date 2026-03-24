#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int MinNoOfInsertionsDeletions(string X, string Y) {
        int n=X.size();
        int m=Y.size();

        if(n == 0 || m == 0){
            return 0;
        }

        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        int dp[n+1][m+1];

        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }

        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(X[i-1] == Y[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        // deletions: n-LCS
        // insertions: m-LCS
        // total: (n-LCS)+(m-LCS) = n+m-2LCS 
        return n+m-(2 * dp[n][m]);
    }
};

int main() {
    string X="leetcode";
    string Y="etco";
    // int n=X.size();
    // int y=Y.size();

    Solution s;

    cout<<s.MinNoOfInsertionsDeletions(X,Y);

    return 0;
}