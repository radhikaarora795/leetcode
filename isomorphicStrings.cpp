#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> map;

        for(int i=0;i<s.length();i++){
            char c1=s[i];
            char c2=t[i];

            auto it=map.find(c1);
            if(it != map.end()){
                if(it->second != c2){
                    return false;
                }
            }
            else{
                for(auto i:map){
                    if(i.second == c2){
                        return false;
                    }
                }
                map[c1]=c2;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    cout<<s.isIsomorphic("paper","title");
    
    return 0;
}