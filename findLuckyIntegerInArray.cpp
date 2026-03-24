#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // better
    int findLucky(vector<int>& arr){
        unordered_map<int,int> m;
        int maximum=-1;
        for(auto i:arr){
            m[i]++;
        }
        for(auto i:m){
            if(i.first == i.second){
                maximum=max(maximum,i.first);
            }
        }
        return maximum;
    }

    int findLucky2(vector<int>& arr) {
        unordered_map<int,int> map;

        for(auto x:arr){
            map[x]++;
        }

        auto it=map.begin();
        int max=-1;

        if(it->first == it->second){
            max=it->first;
        }

        for(auto i:map){
            if(i.first == i.second){
                if(i.first>max){
                    max=i.first;
                }
            }
        }
        return max;
    }
};

int main() {
    Solution s;
    vector<int> v={2,2,2,3,3};
    cout<<s.findLucky(v);
    
    return 0;
}