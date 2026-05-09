#include <iostream>
using namespace std;

string doubleVowels(string s){
    string result="";
    for(char ch:s){
        result+=ch;
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
            result+=ch;
        }
    }
    return result;
}

int main() {
    cout<<doubleVowels("hello");

    return 0;
}