// dp[i][j] = number of subsets from the first i elements with sum j.
// dp[0][0] = 1 because the empty subset is the only subset available before processing any elements.
// Do not initialize dp[i][0] = 1; after processing zeros, there can be multiple subsets with sum 0.
// Start the inner loop from j = 0 so the DP can correctly update dp[i][0], allowing each zero to double the number of subsets with sum 0.
// The transition counts both possibilities: exclude the current element and include the current element.

class Solution {
    int perfectSum(int[] arr, int target) {
        // code here
        int n=arr.length;
        int MOD = 1000000007;
        
        int [][]dp=new int[n+1][target+1];
        
        // for(int j=0;j<=target;j++){
        //     dp[0][j]=0;
        // }
        
        // for(int i=0;i<=n;i++){
        //     dp[i][0]=1;
        // }
        
        dp[0][0]=1;
        
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=target;j++){
                if(arr[i-1] <= j){
                    dp[i][j]=( dp[i-1][j] + dp[i-1][j-arr[i-1]] ) % MOD;
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return dp[n][target];
    }
}

public class countSubsetsWithGivenSum {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] arr={5, 2, 3, 10, 6, 8};
        System.out.println(s.perfectSum(arr, 10));
    }
}

