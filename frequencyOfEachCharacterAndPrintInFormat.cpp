#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void printFrequency(string s){
    unordered_map<char,int> map;
    for(char ch:s){
        map[ch]++;
    }

    unordered_set<char> set;

    for(char ch:s){
        if(set.count(ch) == 0){
            auto it=map.find(ch);
            cout<<it->second<<" "<<it->first<<endl;
            set.insert(ch);
        }
    }
}

int main() {
    printFrequency("hello");
    
    return 0;
}