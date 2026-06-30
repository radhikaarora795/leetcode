#include <iostream>
using namespace std;

// leetcode 128

/*
Given an unsorted array of integers nums, return the length of the longest 
consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. 
Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Example 3:
Input: nums = [1,0,1,2]
Output: 3
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }

        int longest=1;
        int maxLength=1;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1] == nums[i]){
                continue;
            }
            else if(nums[i+1] == nums[i]+1){
                longest++;
                maxLength=max(maxLength,longest);
            }
            else{
                maxLength=max(maxLength,longest);
                longest=1;
            }
        }
        maxLength=max(maxLength,longest);
        return maxLength;
    }
};

int main() {
    
    return 0;
}