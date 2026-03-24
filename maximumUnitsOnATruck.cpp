#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// greedy algorithm
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](const vector<int> &a,const vector<int> &b){
            return a[1]>b[1];
        });
        int total=0;
        for(const auto &row:boxTypes){
            int boxCount=min(truckSize,row[0]);
            total+=boxCount*row[1];
            truckSize-=boxCount;
            if(truckSize==0){
                break;
            }
        }
        /*for (const auto& row : boxTypes) {
            cout << "[" << row[0] << "," << row[1] << "] ";
        }*/

        return total;
    }
};

int main() {
    Solution s;
    vector<vector<int>> boxTypes={{5,10},{2,5},{4,7},{3,9}};
    cout<<s.maximumUnits(boxTypes,10);
    
    return 0;
}