#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    string generateTag(string caption){
        string result="#";
        bool capitalizeNext=false;
        bool firstWord=true;
        for(char ch:caption){
            if(ch == ' '){
                if(!firstWord){
                    capitalizeNext=true;
                }
            }
            else if(isalpha(ch)){
                if(firstWord){
                    char lower=tolower(ch);
                    result+=lower;
                    firstWord=false;
                }
                else if(capitalizeNext){
                    char upper=toupper(ch);
                    result+=upper;
                    capitalizeNext=false;
                }
                else{
                    char lower=tolower(ch);
                    result+=lower;
                }
                if(result.size() == 100){
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    cout<<s.generateTag("#fPysartlqlimkvvrhmkkdlnedqkffpncjbitbtovhovjikbfsawvpisdanzxjctqkn");
    return 0;
}