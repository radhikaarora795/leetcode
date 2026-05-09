#include <iostream>
using namespace std;

int countPrime(int L,int R){
    vector<bool> prime(R+1,true);

    if(R>=0) prime[0]=false;
    if(R>=1) prime[1]=false;

    for(int i=2;i*i<=R;i++){
        if(prime[i]){
            for(int j=i*i;j<=R;j+=i){
                prime[j]=false;
            }
        }
    }
    int count=0;
    for(int i=max(2,L);i<=R;i++){
        if(prime[i]){
            count++;
        }
    }
    return count;
}

bool validDigits(int n){
    while(n>0){
        int x=n%10;
        if(x!=2 && x!=3 && x!=5 && x!=7){
            return false;
        }
        n/=10;
    }
    return true;
}

bool isPrime(int n){
    if(n<2){
        return false;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int countMegaPrime(int L,int R){
    int count=0;
    for(int i=L;i<=R;i++){
        if(validDigits(i) && isPrime(i)){
            count++;
        }
    }
    return count;
}

int main() {
    
    return 0;
}