#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


int convert(string str){
    int length=str.length();
    int i=0;
    int ans=0;
    unordered_map<string,int> map;
    map["I"]=1;
    map["IV"]=4;
    map["V"]=5;
    map["IX"]=9;
    map["X"]=10;
    map["XL"]=40;
    map["L"]=50;
    map["XC"]=90;
    map["C"]=100;
    map["CD"]=400;
    map["D"]=500;
    map["CM"]=900;
    map["M"]=1000;
    
    while(i<length){
        int j=i+1;
        
        if(j<length && map.at(string(1,str[i]))  <  map.at(string(1,str[j])) ){
            ans = ans + map.at(str.substr(i, 2));
            i+=2;
            continue;
        }
        ans = ans + map.at(string(1,str[i]));   // 1,str[i] one char ka string
        i++;
    }
    return ans;
}

int main(){

    cout<<convert("MCCCXXIV");
    return 0;
}
