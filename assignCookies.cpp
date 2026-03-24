#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int content=0;
        int i=0;    // g
        int j=0;    // s

        while(i<g.size() && j<s.size()){
            if(s[j]>=g[i]){
                content++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return content;
    }
};

int main() {
    Solution s;
    vector<int> g={10,9,8,7};
    vector<int> s1={5,6,7,8};
    cout<<s.findContentChildren(g,s1);
    
    return 0;
}