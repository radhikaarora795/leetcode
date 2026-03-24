#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;    // value, count
        unordered_set<int> set;        // to store count 

        for(int x:arr){
            map[x]++;
        }

        for(auto i:map){
            set.insert(i.second);
        }

        if(map.size() != set.size()){
            return false;
        }

        return true;
    } 
};

int main() {
    Solution s;
    vector<int> v={1,2};
    cout<<s.uniqueOccurrences(v);
    
    return 0;
}