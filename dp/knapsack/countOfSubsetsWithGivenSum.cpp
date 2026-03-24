#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int noOfSubsets(vector<int>& arr, int sum){
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        int i=0;
        while(i<n+1){
            dp[i][0]=1;
            i++;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
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
    vector<int> arr={2,3,5,6,8,10};
    int sum=10;
    Solution s;
    cout<<s.noOfSubsets(arr,sum);
    
    return 0;
}