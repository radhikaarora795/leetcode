#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution{
public:
    bool equalSumPartition(vector<int>& arr){
        int n=arr.size();
        int sum = accumulate(arr.begin(),arr.end(),0);
        if(sum% 2 != 0){
            return false;
        } 
        sum /=2;
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

   
};

int main() {
    vector<int> arr={1,5,11,5};
    Solution s;
    cout<<s.equalSumPartition(arr);
    
    return 0;
}