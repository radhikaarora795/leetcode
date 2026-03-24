#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t pos=haystack.find(needle);
        /* size_t is an unsigned integer type used to represent sizes or indexes of objects in memory (like arrays or strings). It's the return type of functions like .size() and .find() in the C++ Standard Library.*/
        if(pos == string::npos){
            return -1;
        }
        else{
            return pos;
        }
    }
}; 

int main() {
    Solution s;
    cout<<s.strStr("leetcode","leeto");
    
    return 0;
}