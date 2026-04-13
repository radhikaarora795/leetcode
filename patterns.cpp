#include <iostream>
using namespace std;

void p1(){
// Floyd's Triangle
    /*
    1
    2 3
    4 5 6
    7 8 9 10
    11 12 13 14 15
    */

    int n=5;
    int count=1;
    for(int i=0;i<5;i++){
        for(int j=0;j<=i;j++){
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
}

void p2(){
    int n=5;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void p3(){
    /*
    * * * * *
    * * * *
    * * *
    * *
    *
    */
   int n=5;
   for(int i=5;i>=1;i--){
    for(int j=0;j<i;j++){
        cout<<"*"<<" ";
    }
    cout<<endl;
   }
}

void diamond(){
    /*
    
    *
   ***
  *****
   ***
    *
    
    */

    int n=5;
    bool even=true;
    if(n%2 != 0){
        even=false;
    }
    if(!even){
        for(int i=0;i<n/2+1;i++){
            for(int j=0;j<=i;j++){
                cout<<"*"<<" ";
            }
            cout<<endl;
        }
    }

}

int main() {
    // p3();

    return 0;
}