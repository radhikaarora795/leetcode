#include <iostream>
using namespace std;

int maxSubArray(vector<int>& arr){
    int currSum=0;
    int maxSum=INT_MIN;
    int ansStart=-1;
    int ansEnd=-1;
    int start=0;

    // for(int x:arr){
    //     currSum+=x;
    //     maxSum=max(maxSum,currSum);
    //     if(currSum < 0){
    //         currSum=0;
    //     }
    // }

    for(int i=0;i<arr.size();i++){
        if(currSum == 0){
            start=i;
        }
        currSum+=arr[i];
        if(currSum > maxSum){
            maxSum=currSum;
            ansStart=start;
            ansEnd=i;
        }
        if(currSum < 0){
            currSum=0;
        }

    }

    for(int i=ansStart;i<=ansEnd;i++){
        cout<<arr[i]<<" ";
    }

    return maxSum;
}

int main() {
    vector<int> arr={-2,1,-3,4,-1,2,1,-5,4};
    maxSubArray(arr);

    
    return 0;
}