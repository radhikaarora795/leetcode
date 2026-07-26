#include <iostream>
using namespace std;

long long nCr(int n,int r){
    if( n < r || n < 0 || r < 0){
        return 0;
    }

    r=min(r,n-r);
    long long ans=1;
    // long long numerator=1;
    // long long denominator=1;

    for(int i=0;i<r;i++){
        // numerator=numerator*(n-i);
        // denominator=denominator*(i+1);
        ans=ans*(n-i);
        ans=ans/(i+1);
    }
    // ans=numerator/denominator;
    return ans;
}

long long getElement(int row,int col){
    return nCr(row-1,col-1);
}

int main() {
    cout<<getElement(5,3);
    
    return 0;
}