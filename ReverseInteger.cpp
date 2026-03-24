#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int reverse(long x) {
        bool negative=false;
        if(x<0){
            negative=true;
            x=x*(-1);
        }
        long rev=0;
        while(x>0){
            int n=x%10;
            rev=rev*10+n;
            x=x/10;
        }
        if(negative==true){
            rev=rev*(-1);
            if(rev<pow(-2,31)){
               rev=0; 
            }
        }
        else{
            if(rev>pow(2,31)){
               rev=0; 
            }
        }

        return rev;
    }
};

int main() {
    Solution s;
    cout<<s.reverse(-2147483648);

    return 0;
}