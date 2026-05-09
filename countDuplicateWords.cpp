#include <iostream>
using namespace std;

int countDuplicates(string str){
    unordered_map<string,int> map;
    string word="";
    for(char ch:str){
        if(ch!=' '){
            word+=ch;
        }
        else{
            if(!word.empty()){
                map[word]++;
                word="";
            }
        }
    }
    if(!word.empty()){
        map[word]++;    // for last word
    }
    int count=0;
    for(auto &i:map){
        if(i.second>1){
            count++;
        }
    }
    return count;
}

int main() {
    string s="Gojo Gojo Gojo Satoru is is ";
    cout<<countDuplicates(s);
    
    return 0;
}