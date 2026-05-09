#include <iostream>
using namespace std;

class Solution {
  public:
    int firstRepeated(vector<int> &arr) {
        // code here
        unordered_map<int,int> map;   // value,count
        
        for(int i:arr){
            map[i]++;
        }
        
        for(int i=0;i<arr.size();i++){
            if(map[arr[i]] > 1){
                return i+1;
            }
        }
        return -1;
    }
};

int main() {
    
    return 0;
}