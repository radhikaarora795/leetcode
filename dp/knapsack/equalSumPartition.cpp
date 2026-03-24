#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool subsetSum(vector<int>& arr, int sum){
        int n=arr.size();
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1));
        int j=0;
        while(j<sum+1){
            dp[0][j]=false;
            j++;
        }
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
        return dp[n][sum];
    }

    bool equalSumPartition(vector<int>& arr){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        if(sum%2 != 0){
            return false;
        }
        return subsetSum(arr,sum/2);
    }
};

int main() {
    vector<int> arr={1,5,11,5};
    Solution s;
    cout<<s.equalSumPartition(arr);
    
    return 0;
}