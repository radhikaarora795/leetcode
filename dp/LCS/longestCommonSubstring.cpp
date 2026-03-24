#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubstring(string X, string Y) {
        int n=X.size();
        int m=Y.size();

        if(n == 0 || m == 0){
            return 0;
        }

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(X[i-1] == Y[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return ans;
    }
        
};

int main() {
    string X="abcd";
    string Y="abed";
    // int n=X.size();
    // int y=Y.size();

    Solution s;
    cout<<s.longestCommonSubstring(X,Y);
    
    return 0;
}