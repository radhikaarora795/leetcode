#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int LCS(string X, string Y, int n, int m) {
        if(n == 0 || m == 0){
            return 0;
        }
        if(X[n-1] == Y[m-1]){
            return 1+LCS(X,Y,n-1,m-1);
        }
        else{
            return max(LCS(X,Y,n,m-1), LCS(X,Y,n-1,m));
        }
    }
};

int main() {
    Solution s;
    string X="abc";
    string Y="abc";
    // int n=X.size();
    // int y=Y.size();

    cout<<s.LCS(X,Y,X.size(),Y.size());
    
    return 0;
}