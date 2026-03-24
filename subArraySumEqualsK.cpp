#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0]=1;
        // This handles the case where the prefix sum itself equals k,
        // i.e., a subarray that starts from index 0 and sums to k.
        int sum=0;
        int count=0;

        for(int n:nums){
            sum+=n;

            if(map.find(sum-k) != map.end()){
                count+=map[sum-k];
            }

            map[sum]++;
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> nums={1,2,3};
    cout<<s.subarraySum(nums,3);
    
    return 0;
}