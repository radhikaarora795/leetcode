#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> result;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                    //break;
                }
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> v1={1,2,3,4};
    int target = 3;

    vector<int> result = s.twoSum(v1,target);

    return 0;
}

