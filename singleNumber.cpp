#include <iostream>
#include <vector>
using namespace std;

/*
XOR has the following properties:
 1) a ^ a = 0  (same numbers cancel each other)
 2) a ^ 0 = a  (XOR with 0 gives the number itself)
 3) XOR is commutative and associative (order does not matter)
 Since every number appears twice except one,
 all duplicate numbers cancel out when XORed together,
 leaving only the single number.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int length=nums.size();
        int result=0;
        for(int i=0;i<length;i++){
            result=result^(nums[i]);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> v={1,2,2,1};
    cout<<s.singleNumber(v);
    
    return 0;
}