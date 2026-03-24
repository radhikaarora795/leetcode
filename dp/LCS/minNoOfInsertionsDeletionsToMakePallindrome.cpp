#include <iostream>
using namespace std;

class Solution {
public:
    int minInsertions(string &Y) {
        int n=Y.size();
        if(n == 0){
            return 0;
        }
        string X=Y;
        reverse(Y.begin(),Y.end());
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++){
            dp[0][i]=0;
            dp[i][0]=0;
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
        return n-dp[n][n];
    }
};

int main() {
    
    return 0;
}