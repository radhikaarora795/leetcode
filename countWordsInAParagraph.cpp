#include <iostream>
using namespace std;

void countWords(string paragraph){
    unordered_map<string,int> map;
    string word="";
    for(int i=0;i<paragraph.size();i++){
        char ch=paragraph[i];
        if(isalnum(ch)){
            word+=tolower(ch);
        }
        else{
            if(!word.empty()){
                map[word]++;
                word="";
            }
        }
    }
    // last wala
    if(!word.empty()){
        map[word]++;
    }

    for(auto i:map){
        cout<<i.first<<" "<<i.second<<endl;
    }
}

int main() {
    countWords("This is a test. This test is simple!");
    
    return 0;
}