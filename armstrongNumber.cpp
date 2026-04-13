#include <iostream>
#include <cmath>
using namespace std;

// Armstrong: sum of digits^n == number
// e.g. 153 = 1³ + 5³ + 3³

bool isArmstrong(int n){
    int save=n;
    int digits=0;
    int sum=0;

    while(n>0){
        digits++;
        n=n/10;
    }
    n=save;

    while(n>0){
        int x=n%10;
        sum+=(int)pow(x,digits);
        n=n/10;
    }

    if(sum == save){
        return true;
    }
    return false;
}

int main() {
    cout<<isArmstrong(143234);
    
    return 0;
}