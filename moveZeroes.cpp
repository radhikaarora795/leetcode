#include <iostream>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZero=0;  // index to place last non zero element;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0){
                swap(nums[i],nums[lastNonZero]);
                lastNonZero++;
            }
        }
    }
};

int main() {
    
    return 0;
}