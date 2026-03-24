#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank = 0;  // total gas - total cost 
                             // total_tank keeps track of left of start/i
        int curr_tank = 0;   // current accumulated balance
        int start = 0;       // candidate starting station

        for (int i = 0; i < gas.size(); ++i) {
            total_tank += gas[i] - cost[i];
            curr_tank += gas[i] - cost[i];
            
            // If curr_tank < 0, we cannot start from 'start' to here
            if (curr_tank < 0) {
                // Choose next station as starting point
                start = i + 1;
                curr_tank = 0; // reset current tank
            }
        }

        return total_tank >= 0 ? start : -1;
    }
};

int main() {
    Solution s;
    vector<int> gas={2,3,4};
    vector<int> cost={3,4,3};
    cout<<s.canCompleteCircuit(gas,cost);
    
    return 0;
}