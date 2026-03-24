#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// two pointer

class Solution {
public:
    int maxArea(vector<int>& height) {
        int length=height.size();
        int vol=0;
        int maxVol=0;
        int p=0;
        int q=length-1;

        while(q>p){
            vol=min(height[p],height[q])*(q-p);
            if(vol>maxVol){
                maxVol=vol;
            }
            if(height[p]<=height[q]){
                p++;
            }
            else{
                q--;
            }
        }
        return maxVol;
    }
};

int main() {
    Solution s;
    vector<int> height={1};
    cout<<s.maxArea(height);               

    return 0;
}

/*

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
 

Constraints:

n == height.length
2 <= n <= 10^5
0 <= height[i] <= 10^4

*/