#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// betters
class Solution1 {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> set;
        int sum=0;

        int max=*max_element(nums.begin(),nums.end());

        if(max<=0){
            return max;
            /*
            If the maximum value in nums is <=0 
            then every element is non-positive.
            In that case, the highest subarray sum is simply max itself
            (picking the single largest non-positive element). 
            */
        }
        /*
        If max > 0, you should collect all distinct positive numbers in the array, because:
        Negative numbers or zeros don't help the sum.
        Duplicate positive numbers only contribute once (due to the uniqueness requirement).
        There is no benefit to leaving out a distinct positive.
        */
        for(int n:nums){
            if(n>0 && set.find(n) == set.end()){
                set.insert(n);
                sum+=n;
            }
        }
        return sum;
    }
};

// bekaar 
class Solution {
public:
    int maxSum(vector<int>& nums) {
        bool seen[201]={};
        int sum=0;

        int max=*max_element(nums.begin(),nums.end());

        if(max<=0){
            return max;
            /*
            If the maximum value in nums is <=0 
            then every element is non-positive.
            In that case, the highest subarray sum is simply max itself
            (picking the single largest non-positive element). 
            */
        }
        /*
        If max > 0, you should collect all distinct positive numbers in the array, because:
        Negative numbers or zeros don't help the sum.
        Duplicate positive numbers only contribute once (due to the uniqueness requirement).
        There is no benefit to leaving out a distinct positive.
        */
        for(int n:nums){
            if(n>0 && !seen[n]){
                seen[n]=true;
                sum+=n;
            }
        }
        return sum;
    }
};

int main() {
    Solution s;
    vector<int> nums={1,2,3,4,5};
    cout<<s.maxSum(nums);
    
    return 0;
}