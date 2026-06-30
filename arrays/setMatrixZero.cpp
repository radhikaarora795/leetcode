#include <iostream>
using namespace std;

// leetcode 73
/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row 
and column to 0's.
You must do it in place.

Eg:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/

// optimal solution

/*
Key Idea

Instead of using extra arrays to record which rows/columns should become zero, use:

First row to mark columns.
First column to mark rows.

The only issue is that matrix[0][0] belongs to both the first row and 
first column, so we need another variable (firstCol) to remember whether 
the first column should become zero.

Algorithm
Step 1: Record markers

Traverse the matrix.

If matrix[i][j] == 0

mark row:

matrix[i][0] = 0;

mark column:

matrix[0][j] = 0;

Need a separate flag for the first column.

Step 2: Fill from back

Traverse from bottom-right.

If

matrix[i][0] == 0
||
matrix[0][j] == 0

then

matrix[i][j] = 0;

Finally process the first column using firstCol.

Traversing backwards prevents destroying the markers too early.

Why traverse backwards?

Suppose we go from top to bottom.

When processing the first row, we may overwrite the column markers (matrix[0][j]) before using them for the remaining rows.

By traversing bottom-up, the markers in the first row remain intact until all other rows have been processed.

Complexity
Time: O(m × n)
Space: O(1)
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        bool firstCol=false;

        for(int i=0;i<n;i++){
            if(matrix[i][0] == 0){
                firstCol=true;
            }
            for(int j=1;j<m;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                    
                }
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=1;j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j]=0;
                }
            }
            if(firstCol == true){
                matrix[i][0]=0;
            }
        }
    }
};

// brute force
class Solution2 {
public:
    void setRowZero(int i,vector<vector<int>>& matrix){
        int m=matrix[0].size();
        for(int k=0;k<m;k++){
            matrix[i][k]=0;
        }
    }

    void setColZero(int j, vector<vector<int>>& matrix){
        int n=matrix.size();
        for(int k=0;k<n;k++){
            matrix[k][j]=0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> coordinates;
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    coordinates.push_back({i,j});
                }
            }
        }

        for(auto& v:coordinates){
            setRowZero(v.first,matrix);
            setColZero(v.second,matrix);
        }
    }
};

int main() {
    
    return 0;
}