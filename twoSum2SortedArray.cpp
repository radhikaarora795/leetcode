#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0;
        int right=numbers.size()-1;

        while(left<right){
            int sum=numbers[left]+numbers[right];
            if(sum == target){
                return {left+1,right+1};    // return vector (1-indexed)
            }
            else if(sum < target){
                left++;
            }
            else{
                right--;
            }
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> v={-1,0};
    vector<int> result=s.twoSum(v,-1);

    for(int i:result){
        cout<<i<<" ";
    }
    
    return 0;
}