#include <iostream>
using namespace std;

class Solution {
public:
    int count=0;
    vector<bool> col,diag1,diag2;
    int n;

    void solve(int row){
        if(row == n){
            count++;
            return;
        }
        for(int c=0;c<n;c++){
            if(!col[c] && !diag1[row-c+n-1] && !diag2[row+c]){
                col[c]=true;
                diag1[row-c+n-1]=true;
                diag2[row+c]=true;

                solve(row+1);

                col[c]=false;
                diag1[row-c+n-1]=false;
                diag2[row+c]=false;
            }
        }
    }

    int totalNQueens(int n) {
        this->n=n;

        col=vector<bool>(n,false);
        diag1=vector<bool>(2*n-1,false);
        diag2=vector<bool>(2*n-1,false);

        solve(0);

        return count;
    }
};

int main() {
    Solution s;
    cout<<s.totalNQueens(8);
    
    return 0;
}