#include <iostream>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> map;
        for(char ch:s){
            map[ch]++;
        }

        for(int i=0;i<s.size();i++){
            if(map[s[i]] == 1){
                return i;
            }
        }

        return -1;
    }
};

class Solution1 {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26,0);

        for(char ch:s){
            freq[ch-'a']++;
        }

        for(int i=0;i<s.size();i++){
            if(freq[s[i]-'a'] == 1){
                return i;
            }
        }
        return -1;        
    }
};

int main() {
    
    return 0;
}