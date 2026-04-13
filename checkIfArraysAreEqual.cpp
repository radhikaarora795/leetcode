#include <iostream>
using namespace std;

/*
Array Equality: Check if two given arrays are equal — same elements at same frequency.
available on gfg
*/

class Solution {
  public:
    bool checkEqual(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int,int> map; // value, count
        
        for(int i:a){
            map[i]++;
        }
        
        for(int i:b){
            map[i]--;
        }
        
        for(auto i:map){
            if(i.second != 0){
                return false;
            }
        }
        return true;
    }
};

int main() {
    
    return 0;
}