#include <iostream>
#include <vector>
using namespace std;

// Iterative binary search is better in practice: it avoids stack overflow, uses less memory, and is standard in production code.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg=0;
        int end=nums.size()-1;
        int mid;

        while(end>=beg){
            mid=(beg+end)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                beg=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums={-1,0,3,5,9,12};
    cout<<s.search(nums,2);

    
    return 0;
}
