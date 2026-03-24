#include <iostream>
#include <vector>
using namespace std;

/*
The first and last element of each row is always 1.
For any element at row[i][j] (where j ≠ 0 and j ≠ i),
row[i][j] = row[i-1][j-1] + row[i-1][j].
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=0;i<numRows;i++){
            vector<int> row(i+1,1); // create row of size i+1 filled with 1s
            for(int j=1;j<i;j++){
                row[j]=result[i-1][j-1]+result[i-1][j];
            }
            result.push_back(row);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> result=s.generate(5);
    cout<<endl;
    for(const auto& row:result){
        for(int val:row){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}