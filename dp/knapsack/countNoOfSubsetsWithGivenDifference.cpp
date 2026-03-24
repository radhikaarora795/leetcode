#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution{
public:
    int noOfSubsetsWithMinDifference(vector<int>& arr, int diff){
        int total=accumulate(arr.begin(),arr.end(),0);
        if(total < diff) return 0;
        if((total+diff) % 2 != 0){
            return 0;
        }
        int n=arr.size();
        int sum=(total+diff)/2;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        int i=0;
        while(i<n+1){
            dp[i][0]=1;
            i++;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
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
    vector<int> arr={1,1,2,3};
    Solution s;
    cout<<s.noOfSubsetsWithMinDifference(arr,1);
    
    return 0;
}