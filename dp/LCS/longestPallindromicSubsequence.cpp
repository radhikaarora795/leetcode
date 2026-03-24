#include <iostream>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string &X) {
        int n=X.size();
        if(n == 0 ){
            return 0;
        }
        string Y(X.rbegin(),X.rend());
        int dp[n+1][n+1];
        for(int j=0;j<=n;j++){
            dp[0][j]=0;
            dp[j][0]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(X[i-1] == Y[j-1]){
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
    
    return 0;
}