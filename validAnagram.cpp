#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        unordered_map<char,int> map;

        for(char ch:s){
            map[ch]++;
        }

        for(char ch:t){
            if(map.find(ch) == map.end() || map[ch] == 0){
                return false;
            }
            map[ch]--;
        }
        return true;
    }
};*/

// better use array
// Since we deal with only lowercase English letters, use an array of size 26 to count frequencies.
/*
Steps:

Initialize int count[26] = {0}.
For every char c in s, do count[c - 'a']++.
For every char c in t, do count[c - 'a']--.
Finally, check if all elements in count are 0.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        int arr[26]={0};

        for(char ch:s){
            arr[ch-'a']++;
        }
        for(char ch:t){
            arr[ch-'a']--;
        }
        for(int i=0;i<26;i++){
            if(arr[i] != 0){
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    cout<<s.isAnagram("a","ab");
    
    return 0;
}