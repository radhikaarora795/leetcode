#include <iostream>
using namespace std;

// leetcode 442
/*
Given an integer array nums of length n where all the integers of nums are in 
the range [1, n] and each integer appears at most twice, return an array of 
all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant 
auxiliary space, excluding the space needed to store the output

Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]

Example 2:
Input: nums = [1,1,2]
Output: [1]

Example 3:
Input: nums = [1]
Output: []

*/

/*
Since the array contains numbers from 1 to n, every number should ideally be 
placed at index number - 1.

Swap each element to its correct position until it is either:
already in the correct place, or
its correct place already contains the same number (duplicate).
Finally, traverse the array.
If nums[i] != i + 1, then nums[i] is a duplicate.
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i=0;
        int n=nums.size();

        // cyclic sort
        while(i < n){
            int correctIndex=nums[i]-1;
            if(nums[i] != nums[correctIndex]){
                swap(nums[i],nums[correctIndex]);
            }
            else{
                i++;
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i] != i+1){
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};

int main() {
    
    return 0;
}