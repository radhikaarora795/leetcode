#include <iostream>
using namespace std;

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int divisibleByM=0;
        int notDivisibleByM=0;

        for(int i=1;i<=n;i++){
            if(i%m == 0){
                divisibleByM+=i;
            }
            else{
                notDivisibleByM+=i;
            }
        }
        return (notDivisibleByM-divisibleByM);
    }
};

int main() {
    Solution s;
    cout<<s.differenceOfSums(5,1);
    
    return 0;
}