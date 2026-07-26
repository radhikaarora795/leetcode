public class knapsack01Tabulation{
    public int knapsack(int W, int val[], int wt[]) {
        // code here
        int n=wt.length;
        
        if(n == 0 || W == 0){
            return 0;
        }
        
        int [][]dp = new int[n+1][W+1];
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=W;j++){
                if(wt[i-1] <= j){
                    dp[i][j]=Math.max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return dp[n][W];
    }

    public static void main(String[] args) {
        int[] wt = {1, 3, 4, 5};
        int[] val = {1, 4, 5, 7};
        int W = 7;

        knapsack01Tabulation obj = new knapsack01Tabulation();

        int ans = obj.knapsack(W, val, wt);

        System.out.println("Maximum value = " + ans);
    }
}