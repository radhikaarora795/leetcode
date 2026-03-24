#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[4][4];

int mcm(vector<int>& arr, int i, int j){
    if(i == j){     // i cannot be greater than j so whenever i == j which means only one matrix so cost of multiplying one matrix = 0
        return dp[i][j]=0;
    }
    int n=arr.size();
    int ans=INT_MAX;

    if(dp[i][j] != -1){
        return dp[i][j];
    }
    for(int k=i;k<=j-1;k++){
        int temp=mcm(arr,i,k) + mcm(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        ans=min(ans,temp);
    }

    return dp[i][j]=ans;
}


int main() {
    vector<int> arr={1,2,3,4};
    memset(dp, -1, sizeof(dp));
    
    cout<<mcm(arr,1,arr.size()-1)<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}