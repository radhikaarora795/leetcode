#include <iostream>
#include <vector>
using namespace std;

/*
Given a maze with n cells. Each cell may have multiple entry points but not more than one exit 
point (i.e entry/exit points are unidirectional doors like valves).

You are given an array exits[], where exits[i] contains the exit point of the ith cell.
If exits[i] is -1, then ith cell doesn't have an exit.

The task is to find the cell with maximum weight (The weight of a cell i is the sum of all 
the cell indexes that have exit point as i ). If there are multiple cells with the maximum 
weight return the cell with highest index.

Note: The cells are indexed with an integer value from 0 to n-1.
A cell i has weight 0 if no cell has exit point as i.

Examples:

Input: exits[] = [2, 0, -1, 2}
Output: 2
Explanation: 
1 -> 0 -> 2 <- 3
weight of 0th cell = 1
weight of 1st cell = 0 (because there is no cell pointing to the 1st cell)
weight of 2nd cell = 0+3 = 3
weight of 3rd cell = 0
There is only one cell which has maximum weight (i.e 2)
So, cell 2 is the output.
*/

// User function Template for C++
class Solution {
  public:
    // array mei random access allowed hai
    int maxWeightCell(vector<int> &exits){
        int n=exits.size();
        vector<int> weights(n,0);
        for(int i=0;i<n;i++){
            if(exits[i] != -1){
                weights[exits[i]]+=i;
            }
        }
        int m=weights[0];
        int savei=0;
        for(int i=0;i<n;i++){
            if(weights[i]>=m){
                m=weights[i];
                savei=i;
            }
        }
        return savei;
    }
};

int main() {
    Solution s;
    vector<int> v={4, 4, 1, 4, 13, 8, 8, 8, 0, 8, 14, 9, 15, 11, -1, 10, 15, 22, 22, 22, 22, 22, 21};
    cout<<s.maxWeightCell(v);
    
    return 0;
}