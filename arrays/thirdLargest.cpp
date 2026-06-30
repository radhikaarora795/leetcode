#include <iostream>
using namespace std;

// leetcode 414

/*
Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.
Example 1:
Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.
*/

class Solution {
public:
    int thirdMax(vector<int>& arr) {
        long long first=arr[0];
        long long second=LLONG_MIN;
        long long third=LLONG_MIN;

        for(int i=1;i<arr.size();i++){
            // for duplicates
            if(arr[i] == first || arr[i] == second || arr[i] == third){
                continue;
            }

            if(arr[i] > first){
                third=second;
                second=first;
                first=arr[i];
            }
            else if(arr[i] < first && arr[i] > second){
                third=second;
                second=arr[i];
            }
            else if(arr[i] < second && arr[i] > third){
                third=arr[i];
            }
        }

        if(third != LLONG_MIN){
            return third;
        }

        return first;
    }
};

int main() {
    
    return 0;
}