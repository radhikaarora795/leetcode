#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    /*int calcRungs(int small,int big,int dist){
        int count=0;
        while(small<big){
            small=small+dist;
            if(small<big){
                count++;
            }
        }
        return count;
    }*/

    int addRungs(vector<int>& rungs, int dist) {
        int num=0;
        int i=0;
        if(rungs[0]>dist){
            num+=(int)(rungs[0]-1)/dist;
        }
        while(i<rungs.size()-1){
            if(rungs[i+1]-rungs[i]>dist){
                num+=(int)(rungs[i+1]-rungs[i]-1)/dist;
                // The -1 avoids counting the existing rung.
                //num+=calcRungs(rungs[i],rungs[i+1],dist);
            }
            i++;
        }
        return num;
    }
};

int main() {
    Solution s;
    vector<int> v={3,6};
    cout<<s.addRungs(v,1); 
    
    return 0;
}