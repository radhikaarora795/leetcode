#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) {
        int total=accumulate(arr.begin(),arr.end(),0);
        if(abs(target)>total) return 0;
        if((total+target) % 2 != 0){
            return 0;
        }
        int n=arr.size();
        int sum=(total+target)/2;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
       
       dp[0][0]=1;

        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};

int main() {
    vector<int> arr={0};
    Solution s;
    cout<<s.findTargetSumWays(arr,0);
    
    return 0;
}