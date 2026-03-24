#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        for(int i=0;i<n;i++){
            dp[i][i]=0;
        }

        for(int l=2;l<n;l++){
            for(int i=1;i<=(n-l);i++){
                int j=i+l-1;
                dp[i][j]=INT_MAX;
                for(int k=i;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j]);
                }
            }
        }
        return dp[1][n-1];
    }
};

int main() {
    Solution s;
    vector<int> arr={2,1,3,4,5};
    cout<<s.matrixMultiplication(arr);
    
    return 0;
}