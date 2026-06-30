#include <iostream>
using namespace std;

// leetcode 26

/*
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }

        int i=0;
        int j=1;

        while(j<nums.size()){
            if(nums[i] != nums[j]){
                i++;
                nums[i]=nums[j];
            }
            j++;

        }

        return i+1;
    }
};

int main() {
    
    return 0;
}