#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        if(nums[0]+nums[1]<=nums[2] || nums[0]+nums[2]<=nums[1] || nums[1]+nums[2]<=nums[0] ){
            return "none";
        }
        if(nums[0]==nums[1] && nums[1]==nums[2]){
            return "equilateral";
        }
        else if(nums[0]==nums[1] || nums[1]==nums[2] || nums[0]==nums[2]){
            return "isosceles";
        }
        else{
            return "scalene";
        }
    }
};

int main() {
    Solution s;
    vector<int> nums={3,4,5};
    cout<<s.triangleType(nums);
    
    return 0;
}