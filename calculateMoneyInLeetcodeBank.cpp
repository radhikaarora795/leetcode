#include <iostream>
using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int start=1;
        int week=1;
        int count=0;

        for(int i=1;i<=n;i++){
            count+=start;
            start++;
            if(i%7==0){ // after 7 days start a new week
                week++;
                start=week;
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    cout<<s.totalMoney(20);
    
    return 0;
}