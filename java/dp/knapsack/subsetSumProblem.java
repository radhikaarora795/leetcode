class subsetSumProblem {
    static boolean isSubsetSum(int arr[], int sum) {
        // code here
        int n=arr.length;
        
        boolean [][] dp=new boolean[n+1][sum+1];
        
        for(int j=1;j<=sum;j++){
            dp[0][j]=false;
        }
        
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1] <= j){
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
    }

    public static void main(String[] args) {
        
    }
}