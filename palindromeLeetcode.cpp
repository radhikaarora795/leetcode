#include <iostream>
using namespace std;

bool checkPalindrome(int x){
    int save=x;
    if(x<0){
        return false;
    }
    long long int reverse=0;
    while(x>0){
        reverse=reverse*10 + x%10;
        x=x/10;
    }
    if(reverse != save){
        return false;
    }
    return true;
}

int main(){
    int x=1234567899;
    int y=-121;

    cout<<checkPalindrome(x);

    return 0;
}