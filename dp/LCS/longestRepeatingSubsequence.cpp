#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int longestRepeatingSubsequence(string &X) {
        int n=X.size();
        if(n == 0){
            return 0;
        }
        
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
            dp[0][i]=0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(X[i-1] == X[j-1] && i != j){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n][n];
    }
};

int main() {
    string X="axxzxy";
    string Y="abc";
    // int n=X.size();
    // int y=Y.size();

    Solution s;
    cout<<s.longestRepeatingSubsequence(X);
    
    return 0;
}