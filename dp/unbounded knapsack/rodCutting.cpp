#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int rodCutting(vector<int>& prices,int N){
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(N+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=N;j++){
                if(i<=j){   // not prices[i-1]<=j because Index i itself represents rod length
                    dp[i][j]=max(dp[i-1][j], prices[i-1]+dp[i][j-i]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][N];
    }
};

int main() {
    vector<int> prices={1,5,8,9,10,17,17,20};
    int N=8;
    Solution s;
    cout<<s.rodCutting(prices,8);
    
    return 0;
}