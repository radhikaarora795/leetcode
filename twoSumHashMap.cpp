/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

/*#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int> map; // int value int index
        for(int i=0;i<nums.size();i++){
            int temp=target-nums[i];
            if(map.count(temp)>0){
                result.push_back(i);
                result.push_back(map[temp]);
                break; 
            }
            map[nums[i]]=i;                
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> v1={1,2,3,4};
    int target = 6;

    vector<int> result = s.twoSum(v1,target);

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

    return 0;
}
*/

// better above uses two lookups, this uses one lookup
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
    public:
        vector<int> twoSum(vector<int>& nums, int target){
            vector<int> result;
            unordered_map<int,int> map;

            for(int i=0;i<nums.size();i++){ 
                int temp=target-nums[i];
                auto it=map.find(temp);
                if(it != map.end()){
                    result.push_back(map[temp]);
                    result.push_back(i);
                    break;
                }
                map[nums[i]]=i;
            }
            return result;
        }
};


int main(){
    Solution s;
    vector<int> v={3,3};
    int target=6;

    vector<int> result=s.twoSum(v,target);

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

    return 0;
}
