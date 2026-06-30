// Maximum sum of k cosecutive elements in an array using sliding window

// first cal sum of first k elements and set it as maxSum
// similair to 2 pointers at start and end 
// for next sum delete start pointer val & add end pointer val

#include <iostream>
using namespace std;

int maxSum(int arr[],int n, int k){
    int maxS=0;
    int windowSum=0;
    if ( k > n) {
        return -1;
    }
    for(int i=0;i<k;i++){
        windowSum+=arr[i];
    }
    
    maxS=windowSum;
    for (int i=k;i<n;i++){
        windowSum=windowSum+arr[i]-arr[i-k];
        // if(windowSum > maxS){
        //     maxS=windowSum;
        // }
        maxS=max(maxS,windowSum);
    }
    return maxS;

}

int main(){

    return 0;
}