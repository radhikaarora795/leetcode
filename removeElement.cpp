#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*class Solution{
    public:
        int removeElement(vector<int>& nums, int val){
            nums.erase(remove(nums.begin(),nums.end(),val),nums.end());

            return nums.size();
        }
};*/

// better for interviews
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != val){
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};

int main(){
    Solution s;
    vector<int> nums={3,3,3,2,2,3};
    int val=3;
    
    cout<<s.removeElement(nums,val);

    return 0;
}