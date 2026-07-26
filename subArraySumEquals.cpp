#include <iostream>
using namespace std;

// leetcode 560

/*
Given an array of integers nums and an integer k, return the total number
 of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
*/


class Solution {
public:
    int subarraySum(vector<int>& nums, int target) {
        int n=nums.size();
        if(n == 0){
            return -1;
        }

        vector<int> ps(n);
        ps[0]=nums[0];

        unordered_map<int,int> map;     // prefix sum, freq
        map[0]=1;

        for(int i=1;i<n;i++){
            ps[i]=ps[i-1]+nums[i];
        }

        // ps[i-1]=ps[j]-target
        // we will iterate over j and look for ps[i-1] in map

        int count=0;
        for(int j=0;j<n;j++){
            if(map.find(ps[j]-target) != map.end()){
                count+= map[ps[j]-target];
                /*
                if(count >= 1){
                    return true;
                }
                */
            }
            
            map[ps[j]]++;
        }

        return count;
    }
};

int main() {
    
    return 0;
}