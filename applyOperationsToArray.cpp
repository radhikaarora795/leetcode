#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]){
                nums[i]=nums[i]*2;
                nums[i+1]=0;
            }
        }
        int left=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0){
                swap(nums[i],nums[left]);
                left++;
            }
        }
        return nums;
    }
};

int main() {
    Solution s;
    vector<int> nums={0,1};
    vector<int> result;

    result=s.applyOperations(nums);

    for(int r:result){
        cout<<r<<" ";
    }
    
    return 0;
}