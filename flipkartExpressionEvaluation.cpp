/*
You’re given a string representing a expression, but each term may contain extra letters mixed in with its digits 
(or be entirely alphabetic). Your task is to:
1. Strip out all non‑digit characters from each term.
2. Interpret the remaining expression using BODMAS.

eg: Input:  "2a7a+175b-c"
After cleaning:  "27" + "175" - ""  →  27 + 175 - (no digits ⇒ 1)
Answer: 201
*/

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string infixToPostfix(string str){
    stack<int> opStack;
    string postfix="";

    for(int i=0;i<str.size();i++){
        string symbol=str[i];
        
    }
}

int main() {
    /*string str="2a7a+175b-c";

    str.erase(remove_if(str.begin(),str.end(),[](char c){
        return isalpha(c);
    }),str.end());

    cout<<str<<endl;

    cout<<stoi*/
    
    return 0;
}