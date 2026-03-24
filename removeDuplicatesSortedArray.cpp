#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto it=unique(nums.begin(),nums.end());
        nums.erase(it,nums.end());
        return nums.size();
    }
};

int main() {
    Solution s;
    vector<int> v={0,0,1,1,1,2,2,3,3,4};
    cout<<s.removeDuplicates(v);
    
    return 0;
}