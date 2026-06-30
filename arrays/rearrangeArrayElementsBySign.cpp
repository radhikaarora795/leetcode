#include <iostream>
using namespace std;

// leetcode 2149

/*
You are given a 0-indexed integer array nums of even length consisting of an 
equal number of positive and negative integers.

You should return the array of nums such that the array follows the given 
conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in 
nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the 
aforementioned conditions.

Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions 
is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] 
are incorrect because they do not satisfy one or more conditions. 
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int i=0;    // postive elements at even index
        int j=1;    // negative elements at odd index

        for(int n : nums){
            if(n > 0){
                ans[i]=n;
                i+=2;
            }
            else{
                ans[j]=n;
                j+=2;
            }
        }

        return ans;
    }

    // If the number of positive and negative elements is not equal

    /*
    Approach
    Store all positives in one vector.
    Store all negatives in another vector.
    Merge them alternately.
    Append the remaining elements from the longer vector.
    */

    vector<int> rearrange(vector<int>& nums){
        vector<int> positive;
        vector<int> negative;

        for(int n:nums){
            if(n >= 0){
                positive.push_back(n);
            }
            else{
                negative.push_back(n);
            }
        }

        vector<int> ans;
        int i=0;
        int j=0;

        while(i < positive.size() && j<negative.size()){
            ans.push_back(positive[i]);
            ans.push_back(negative[j]);
            i++;
            j++;
        }

        while(i < positive.size()){
            ans.push_back(positive[i]);
            i++;
        }

        while(j < negative.size()){
            ans.push_back(negative[j]);
            j++;
        }

        return ans;
    }
};

/*
Can it be optimized to O(1) space?

Not for this problem while preserving order.

The problem states:

Equal number of positive and negative numbers.
Relative order of positive numbers must remain the same.
Relative order of negative numbers must remain the same.

Maintaining stable order while rearranging in-place is much harder. There is no simple linear-time, constant-space algorithm.

The in-place methods involve repeated rotations/shifts, leading to:

Time: O(n²)
Space: O(1)
*/

int main() {
    
    return 0;
}