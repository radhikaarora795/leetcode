#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int missing=0;
        unordered_set<int> set;
        for(int i=0;i<nums.size();i++){
            set.insert(nums[i]);
        }
        int i=k;
        while(true){
            auto it=set.find(i);
            if(it == set.end()){
               return i;
            }
            i+=k;
        }
    }
};

int main() {
    Solution s;
    vector<int> nums={1,4,7,10,15};
    cout<<s.missingMultiple(nums,5);
    
    return 0;
}