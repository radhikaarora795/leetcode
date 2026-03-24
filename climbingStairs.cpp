#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int count=0;
        int n1=0;
        int n2=1;
        int n3=0;

        while(count<n){
            n3=n1+n2;
            n1=n2;
            n2=n3;
            count++;
        }
        return n3;
    }
};

int main() {
    Solution s;
    cout<<s.climbStairs(5);
    
    return 0;
}

// calculate manually and it turns out to be fibonacci