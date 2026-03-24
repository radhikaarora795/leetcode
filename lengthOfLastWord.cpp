#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string> v;
        stringstream ss(s);
        string temp;

        char delimiter=' ';

        while(getline(ss,temp,delimiter)){
            if(!temp.empty()){
                v.push_back(temp);
            }
        }
        
        int length=v.size();
        return v[length-1].size();
    }
};

int main(){
    Solution s;
    string str="luffy is still joyboy";
    cout<<s.lengthOfLastWord(str);

    return 0;
}