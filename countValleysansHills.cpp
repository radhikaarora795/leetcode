#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count=0;
        int i,j,k;
        int l=nums.size();
        for(i=1;i<l-1;i++){
            if(nums[i] == nums[i+1]){
                continue;
            }
            j=i-1;
            k=i+1;

            while(j>=0 && nums[i]==nums[j]){
                j--;
            }
            while(k<l && nums[i]==nums[k]){
                k++;
            }
            //cout<<"i: "<<nums[i]<<" j: "<< nums[j]<<" k: "<< nums[k]<<endl;
            if(j!=-1 && k!=l){
                if(( nums[i]<nums[j] && nums[i]<nums[k]) || (nums[i]>nums[j] && nums[i]>nums[k])){
                    //cout<<"inserting"<<endl;
                    count++;
                    //cout<<"count: "<<count<<endl;
                }
            }
        }
        return count;
    }
};


int main() {
    Solution s;
    vector<int> nums={8,2,5,7,7,2,10,3,6,2};
    cout<<s.countHillValley(nums);

    
    return 0;
}