#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        int n1=0;
        int n2=1;
        int n3=0;
        int i=0;
        
        while(i<n){
            n3=n1+n2;
            n1=n2;
            n2=n3;
            i++;
        }
        return n1;
    }
};

int main() {
    Solution s;
    cout<<s.fib(4);
    
    return 0;
}