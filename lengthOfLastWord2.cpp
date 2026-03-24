#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length=s.size();
        int i=length-1;

        while(i>=0 && s[i]==' '){
            i--;
        } 

        int count=0;
        while(i>=0 && s[i] != ' '){
            count++;
            i--;
        }
        
        return count;
    }
};

int main(){
    Solution s;
    string str="Hello World";
    cout<<s.lengthOfLastWord(str);

    return 0;
}