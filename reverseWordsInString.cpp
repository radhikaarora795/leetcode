#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());

        int length=s.size();

        for(int i=0;i<length;i++){
            if(s[i] != ' '){
                int j=i;
                while(j<length && s[j] != ' '){
                    j++;
                }
                reverse(s.begin()+i,s.begin()+j);
                i=j;
            }
        }

        // remove extra spaces

        string result;
        int i=0;

        while(i<length){
            while(i<length && s[i] == ' '){
                i++;
            }
            if(i>=length){
                break;
            }
            if(!result.empty()){
                result=result+' ';
            }
            while(i<length && s[i] != ' '){
                result=result+s[i];
                i++;
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    cout<<s.reverseWords("  Bob    Loves  Alice   ");
    
    return 0;
}