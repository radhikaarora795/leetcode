/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool find(vector<int>& v,int n,int start){
        int i=start;
        while(i<v.size()){
            if(v[i]==n) return true;
            i++;
        }

        return false;
    }

    vector<int> twoSum(vector<int>& nums, int target,int start){  // this gives actual numbers and not indices
            vector<int> result;
            for(int i=start;i<nums.size();i++){ 
                int temp=target-nums[i];
                bool it=find(nums,temp,i);
                if(it){
                    result.push_back(nums[i]);
                    result.push_back(temp);
                    break;
                }
                
            }
            return result;
        }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        int length=nums.size();
        int target=0;
        for(int i=0;i<length;i++){
            int temp=target-nums[i];
            vector<int> result= twoSum(nums,temp,(i+1)); 
            if(!result.empty()){
                v.push_back({nums[i],result[0],result[1]});
            }
        }

        for(int i=0;i<v.size();i++){
            for(int j=0;j<3;j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
        return v;
    }
};

int main() {
    Solution s;
    vector<int> v={-1,0,1,2,-1,4};

    s.threeSum(v);

    return 0;
}