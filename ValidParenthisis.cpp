/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
Input: s = "()"
Output: true
*/
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s){
    stack<char> stack;
    unordered_map<char,char> map;
    map['(']=')'; map['[']=']'; map['{']='}';

    int length=s.length();
    for(int i=0;i<length;i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            stack.push(s[i]);
        }
        else{
            if (stack.empty()) {
                return false;
            }
            char c=stack.top();
            if(map.at(c) == s[i]){
                stack.pop();
                continue;
            }
            else{
                return false;
            }
        }
    }
    if(!stack.empty()){
        return false;
    }
    return true;
}

int main(){
    string s="({)}";

    cout<<isValid(s);

    return 0;
}