#include <iostream>
#include <unordered_set>
using namespace std;

/*
leetcode 349

Given two integer arrays nums1 and nums2, return an array of their 
intersection. Each element in the result must be unique and you may 
return the result in any order.

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
*/

/*
Approach 1: Hash Set (Optimal)

Idea:

Insert all elements of nums1 into a set.
Traverse nums2.
If an element exists in the set, add it to the answer and erase it from the 
set to avoid duplicates.

Time Complexity: O(n + m) (average)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set(nums1.begin(),nums1.end());
        vector<int> ans;

        for(int i:nums2){
            if(set.find(i) != set.end()){
                ans.push_back(i);
                set.erase(i);
            }
        }

        return ans;
    }
};

int main() {
    
    return 0;
}