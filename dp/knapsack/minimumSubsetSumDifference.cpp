#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>
using namespace std;

class Solution{
public:
    int minimumSubsetSumDifference(vector<int>& arr){
        int n=arr.size();
        int sum=accumulate(arr.begin(),arr.end(),0);
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        int i=0;
        while(i<n+1){
            dp[i][0]=true;
            i++;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        int minSumDifference=INT_MAX;
        for(int j=0;j<=sum/2;j++){  // Why check only till sum/2 ? Checking after sum/2 gives duplicate results.
            if(dp[n][j]==true){
                minSumDifference=min(minSumDifference,sum-2*j);
            }
        }
        return minSumDifference;
    }
};

int main() {
    vector<int> arr={1,3,7};
    Solution s;
    cout<<s.minimumSubsetSumDifference(arr);
    
    return 0;
}