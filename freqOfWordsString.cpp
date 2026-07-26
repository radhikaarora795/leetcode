#include <iostream>
#include <cctype>
using namespace std;

void freqOfWords(string str){
    unordered_map<string,int> map;
    string word="";

    for(char ch:str){
        if(ch != ' '){
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
        map[word]++;    // count last word
    }

    for(auto i:map){
        cout<<i.first<<": "<<i.second<<endl;
    }
}

bool isSeperator(char ch){
    return isspace(ch) || ispunct(ch);
}

int countWords(string str){
    int count=0;
    for(int i=0;i<str.size();i++){
        if (!isSeperator(str[i]) && (i == 0 || isSeperator(str[i-1]))){
            count++;
        }
    }
    return count;
}

/*
### `freqOfWords()`

This function counts how many times each word appears in a string. 
It uses an `unordered_map<string, int>` where the **key** is a word and 
the **value** is its frequency. It reads the string character by character, 
building a word until it encounters a space. When a space is found, 
the completed word is inserted into the map (or its count is incremented 
if it already exists), and the temporary word is cleared to start 
collecting the next one. After the loop, it checks if there is a 
remaining word (the last word, since the string may not end with a space) 
and updates its count. Finally, it traverses the map and prints each 
word along with its frequency.

### `countWords()`

This function counts the total number of words in a string by detecting 
the **start of each word**. It scans the string from left to right and 
increments the count only when the current character is **not** 
a separator (`isspace()` or `ispunct()`) and either it is the 
**first character** of the string or the previous character is a separator. 
This ensures that each word is counted exactly once, regardless of its 
length or the number of spaces and punctuation marks between words. 
The function returns the total word count with **O(n)** time complexity 
and **O(1)** extra space.

*/

int main() {
    string str="Satoru Gojo is the strongest Satoru Satoru Satoru Gojo Gojo strongest Gojo";
    freqOfWords(str);
    
    return 0;
}