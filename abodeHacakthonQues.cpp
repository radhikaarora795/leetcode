#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// binary to decimal;

int binaryToDecimal(string binary){
    int length=binary.size()-1;
    int result=0;
    int base=1;

    for(int i=length;i>=0;i--){
        if(binary[i] == '1'){
            result=result+base;;
        }
        base=base*2;
    }
    return result;
}

// checkmif strings are rotation of each other

bool isRotation(string s1, string s2) {
    if(s1.length() != s2.length())
        return false;

    string temp = s1 + s1;
    if(temp.find(s2) != string::npos)
        return true;
    else
        return false;
}

int main() {
    cout<<binaryToDecimal("10001000")<<endl;
    cout<<isRotation("letuslet","usletlet");
    
    return 0;
}