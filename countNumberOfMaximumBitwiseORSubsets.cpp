#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int goal = 0, ans = 0;
        for (int x : nums) goal = goal | x;
        int total = 1 << n;     // 2^n
        for (int mask = 1; mask < total; ++mask) {
            int cur = 0;
            for (int i = 0; i < n; ++i){
                if (mask & (1 << i))
                    cur |= nums[i];
            }
            if (cur == goal)
                ++ans;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums={3,2,1,5};
    cout<<s.countMaxOrSubsets(nums);
    
    return 0;
}