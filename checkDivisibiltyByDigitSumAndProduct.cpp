#include <iostream>
using namespace std;

class Solution {
public:
    bool checkDivisibility(int n) {
        int x=0;
        int sum=0;
        int product=1;
        int save=n;

        while(n>0){
            x=n%10;
            sum=sum+x;
            product=product*x;
            n=n/10;
        }
        
        int total=sum+product;

        if(save%total == 0){
            return true;
        }
        else{
            return false;
        }
    }
};

int main() {
    Solution s;
    cout<<s.checkDivisibility(99);
    
    return 0;
}