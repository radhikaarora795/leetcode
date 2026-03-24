#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isValid(string word) {
        const string vowels="aeiouAEIOU";
        bool hasVowel=false;
        bool hasConsonant=false;
        if(word.size()<3){
            return false;
        }
        for(char c:word){
            if(!isalpha(c) && !isdigit(c)){
                return false;
            }
            if(isalpha(c)){
                if(vowels.find(c) != string::npos){
                    hasVowel=true;
                }
                else{
                    hasConsonant=true;
                }
            }
        }
        return hasVowel&&hasConsonant;
    }
};

int main() {
    Solution s;
    cout<<s.isValid("a3$e");
    
    return 0;
}