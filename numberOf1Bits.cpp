#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n>0){
            if(n%2 != 0){
                count++;
            }
            n=n/2;
        }
        return count;
    }
};

int main() {
    Solution s;
    cout<<s.hammingWeight(11);
    
    return 0;
}