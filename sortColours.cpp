#include <iostream>
#include <vector>
#include <algorithm> // for swap()
using namespace std;

// Approach : Dutch National Flag algorithm

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high=nums.size()-1;

        while(mid<=high){
            if(nums[mid] == 0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{   // nums[mid]==2
                swap(nums[mid],nums[high]);
                high--;
            }
        }

        /*for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }*/
    }
};

int main() {
    Solution s;
    vector<int> v={2,0,1};
    s.sortColors(v);
    
    return 0;
}