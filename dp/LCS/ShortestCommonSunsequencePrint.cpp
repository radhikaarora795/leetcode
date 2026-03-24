#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string X, string Y) {
        const int n=X.size();
        const int m=Y.size();

        if(n == 0){
            return Y;
        }
        if(m == 0){
            return X;
        }

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
                    dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        string result="";
        int i=n;
        int j=m;

        while(i>0 && j>0){
            if(X[i-1] == Y[j-1]){
                result=X[i-1]+result;
                i--;
                j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    result=X[i-1]+result;
                    i--;
                }
                else{
                    result=Y[j-1]+result;
                    j--;
                }
            }
        }
        while(i>0){
            result=X[i-1]+result;
            i--;
        }
        while(j>0){
            result=Y[j-1]+result;
            j--;
        }
        return result;
    }
};

int main() {
    Solution s;
    cout<<s.shortestCommonSupersequence("abac","cab");
    
    return 0;
}