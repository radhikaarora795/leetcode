#include <iostream>
#include <string>

using namespace std;

bool isSeparator(char ch){
    if (ch ==' ' || ch =='.' || ch ==',' || ch ==';' || ch ==':' || ch=='?')
        return true;
    return false;
    
}

int countWords(string str){
    int count = 0;

    for(int i=0;i<str.size();i++){
        if(!isSeparator(str[i]) && (i==0 || isSeparator(str[i-1]))){ // start of word
            count++;
        }
    }

    return count;
}

int main() {
    cout<<countWords("  hello, world cpp. ");
    
    return 0;
}