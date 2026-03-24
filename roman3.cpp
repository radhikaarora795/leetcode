#include <iostream>
#include <string>
using namespace std;


int convert(string str){
    int length=str.length();
    int i=0;
    int ans=0;
    int map[128];
    map['I']=1;
    map['V']=5;
    map['X']=10;
    map['L']=50;
    map['C']=100;
    map['D']=500;
    map['M']=1000;
    
    while(i<length){
        int j=i+1;
        if(j<length && map[str[i]]  <  map[str[j]]) {
            ans = ans-map[str[i]];
        }
        else{
            ans = ans + map[str[i]];
        }   
        i++;
    }
    return ans;
}

int main(){

    cout<<convert("MCCCXXIV");
    return 0;
}
