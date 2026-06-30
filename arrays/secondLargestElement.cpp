#include <iostream>
using namespace std;

// gfg

/*

Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

Note: The second largest element should not be equal to the largest element.

Examples:

Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.

*/

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int first=arr[0];       // first largest
        int second=INT_MIN;     // second largest
        
        for(int i=1;i<arr.size();i++){
            if(arr[i] > first){
                second=first;
                first=arr[i];
            }
            else{
                if(arr[i] > second && arr[i] < first){
                    second=arr[i];
                }
            }
        }
        
        if(second == INT_MIN){
            return -1;
        }
        return second;
    }
};

int main() {
    
    return 0;
}