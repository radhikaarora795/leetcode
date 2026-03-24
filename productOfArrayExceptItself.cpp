#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1;
        int zeroCount=0;
        int length=nums.size();
        for(int i=0;i<length;i++){
            if(nums[i]==0){
                zeroCount++;
            }
            else{
                product*=nums[i];
            }
        }
        if(zeroCount>1){
            // If more than one zero, all products are zero
            nums.assign(length,0);  //Reinitialize an Existing vector, Sets size to length, all values to 0
            return nums;
        }
        else{
            for(int i=0;i<length;i++){
                if(zeroCount==0){
                    nums[i]=product/nums[i];
                }
                else{
                    // Only one zero: only this position gets the product
                    /*
                    Only the index with 0 should get the full product
                    All other indices must become 0 because their product includes a 0
                    */
                    nums[i] = (nums[i] == 0) ? product : 0;
                }
            }
        }
        return nums;
    }
};

// without divison:
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);  // Final result array

        // Step 1: Build prefix product array in result[]
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            result[i] = prefix;
            prefix *= nums[i];
        }

        // Step 2: Multiply with suffix product from right
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= suffix;
            suffix *= nums[i];
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums={-1, 1, 0, -3, 3};
    vector<int> result=s.productExceptSelf(nums);
    for(int i:result){
        cout<<i<<" ";
    }
    
    return 0;
}