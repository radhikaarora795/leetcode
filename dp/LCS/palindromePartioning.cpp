#include <iostream>
using namespace std;

// User function Template for C++

class Solution {
  public:
    bool isPallindrome(string s,int i,int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int solve(string &s, int i,int j,vector<vector<int>> &dp){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i>=j){
            return 0;
        }
        if(isPallindrome(s,i,j)){
            return 0;
        }
        int ans=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int left;
            if(dp[i][k] != -1){
                left=dp[i][k];
            }
            else{
                left=solve(s,i,k,dp);
            }
            int right;
            if(dp[k+1][j] != -1){
                right=dp[k+1][j];
            }
            else{
                right=solve(s,k+1,j,dp);
            }
            int temp=1+left+right;
            ans=min(ans,temp);
        }
        return dp[i][j]=ans;
    }


  
    int palPartition(string &s) {
        // code here
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(s,0,n-1,dp);
    }
};

int main() {
    Solution s;
    string str="nitit";
    cout<<s.palPartition(str);
    
    return 0;
}