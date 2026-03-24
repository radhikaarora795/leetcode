#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> set;
        int left=0;
        int right=0;
        int currentSum=0;
        int maxSum=0;

        while(right<nums.size()){
            while(set.count(nums[right])){
                set.erase(nums[left]);
                currentSum-=nums[left];
                left++;
            }
            set.insert(nums[right]);
            currentSum+=nums[right];
            maxSum=max(maxSum,currentSum);
            right++;
        }
        return maxSum;
    }
};

int main() {
    Solution s;
    vector<int> v={5,2,1,2,5,2,1,2,5};
    cout<<s.maximumUniqueSubarray(v);
    
    return 0;
}