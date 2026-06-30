#include <iostream>
using namespace std;

/*
leetcode 88

You are given two integer arrays nums1 and nums2, sorted in non-decreasing 
order, and two integers m and n, representing the number of elements in nums1 
and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be 
stored inside the array nums1. To accommodate this, nums1 has a length of 
m + n, where the first m elements denote the elements that should be merged, 
and the last n elements are set to 0 and should be ignored. nums2 has a length 
of n.

eg:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming 
from nums1.
*/

/*

We start filling nums1 from the end because the front contains valid elements 
that we don't want to overwrite. Compare the largest remaining elements of 
nums1 and nums2, place the larger one at the last available position, and 
move the corresponding pointer backward. If any elements remain in nums2, 
copy them since any remaining elements in nums1 are already in the correct 
position.

Approach (Two Pointers from the End)
Let:
i = m - 1 → last valid element of nums1
j = n - 1 → last element of nums2
k = m + n - 1 → last position of nums1
Compare nums1[i] and nums2[j].
Place the larger one at nums1[k].
Move the corresponding pointer backward.
If elements remain in nums2, copy them.

Why don't we copy the remaining elements of nums1?

If i >= 0 and j < 0, the remaining elements of nums1 are already in their 
correct positions. No further work is needed.

Complexity
Time: O(m + n)
Space: O(1)

*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;  // last non zero element of nums1
        int j=n-1;  // last element of nums2
        int k=m+n-1;  // last 0 element of nums1

        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[k]=nums1[i];
                i--;
            }
            else{
                nums1[k]=nums2[j];
                j--;
            }
            k--;
        }

        while(j>=0){
            nums1[k]=nums2[j];
            j--;
            k--;
        }
    }
};

int main() {
    
    return 0;
}