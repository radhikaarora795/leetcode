#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// integer overlow giving run time error so use unsigned long long

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        unsigned long long mn=INT_MAX;
        int n=coins.size();
        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(amount+1,INT_MAX-1));
        for(int i=1;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                    dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
                    mn=min(mn,dp[i][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                    mn=min(mn,dp[i][j]);
                }
            }
        }
        return mn;
    }
};

int main() {
    vector<int> coin={10};
    int amount=10;
    Solution s;
    cout<<s.change(amount,coin);
    
    return 0;
}