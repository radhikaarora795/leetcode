#include <iostream>
using namespace std;

class Solution {
public:
    int dp[101][10001];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int superEggDrop(int e, int f) {
        if(f==0 || f==1){
            return f;
        }
        if(e==1){
            return f;
        }
        if(dp[e][f] != -1){
            return dp[e][f];
        }
        int mn=INT_MAX;
        for(int k=1;k<=f;k++){
            int low,high;
            if(dp[e-1][k-1] != -1){
                low=dp[e-1][k-1];
            }
            else{
                low=superEggDrop(e-1,k-1);
                dp[e-1][k-1]=low;
            }
            if(dp[e][f-k] != -1){
                high=dp[e][f-k];
            }
            else{
                high=superEggDrop(e,f-k);
                dp[e][f-k]=high;
            }
            int temp=1+max(low,high);
            mn=min(mn,temp);
        }
        return dp[e][f]=mn;
    }
};

int main() {
    
    return 0;
}