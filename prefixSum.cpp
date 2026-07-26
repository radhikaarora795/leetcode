#include <iostream>
using namespace std;

// gfg

/*
Given an array arr[], the goal is to compute its prefix sum array. 
The prefix sum array, prefixSum[], should be of the same length as arr[], 
where each element prefixSum[i] represents the sum of all elements from 
the start of the array up to index i, i.e., 
prefixSum[i] = arr[0] + arr[1] + .... + arr[i].

Examples:

Input: arr[] = [10, 20, 10, 5, 15]
Output: [10, 30, 40, 45, 60]
Explanation: For each index i, add all the elements from 0 to i:
prefixSum[0] = 10, 
prefixSum[1] = 10 + 20 = 30, 
prefixSum[2] = 10 + 20 + 10 = 40 and so on.
*/

// in place
class Solution {
  public:
    vector<int> prefSum(vector<int> &arr) {
        // code here
        for(int i=1;i<arr.size();i++){
            arr[i]+=arr[i-1];
        }
        
        return arr;
    }
};


// using prefixSum array
class Solution1 {
  public:
    vector<int> prefSum(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int> prefixSum(n);
        
        prefixSum[0]=arr[0];
        
        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+arr[i];
        }
        
        return prefixSum;
    }
};

int main() {
    
    return 0;
}