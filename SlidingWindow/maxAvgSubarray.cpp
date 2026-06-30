#include <iostream>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double windowSum=0;
        for(int i=0;i<k;i++){
            windowSum+=nums[i];
        }
        double windowAvg=(double)windowSum/k;
        double maxAvg=windowAvg;
        for(int i=k;i<nums.size();i++){
            windowSum=windowSum+nums[i]-nums[i-k];
            windowAvg=windowSum/k;
            maxAvg=max(maxAvg,windowAvg);
        }
        return maxAvg;
    }
};

int main() {
    
    return 0;
}