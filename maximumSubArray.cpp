/*
use Kadane's Algorithm
Kadane’s Algorithm finds the biggest sum of numbers next to each other in an array.
It does this by checking at each step whether to start fresh from the current number or keep adding to the previous sum.
This way, it quickly finds the highest possible subarray sum in one pass.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=nums[0];
        int currentSum=0;
        int length=nums.size();

        for(int i=0;i<length;i++){
            currentSum=max(nums[i],nums[i]+currentSum);

            if(currentSum>maxSum){
                maxSum=currentSum;
            }
        }

        return maxSum;
    }
};

int main() {
    Solution s;
    vector<int> v={5,4,-1,7,8};

    cout<<s.maxSubArray(v);
    
    return 0;
}