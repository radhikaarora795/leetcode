#include <iostream>
#include <cmath>
using namespace std;

/*
A number N is Fibonacci if and only if one of these is a perfect square:
5*N*N + 4
5*N*N - 4
*/

bool isPerfectSquare(long long n){
    long long s=sqrt(n);
    return (s*s == n);
}

bool check(int n){
    long long a=5*n*n+4;
    long long b=5*n*n-4;

    if(isPerfectSquare(a) || isPerfectSquare(b)){
        return true;
    }
    else{
        return false;
    }

}

int main() {
    cout<<check(34);
    
    return 0;
}