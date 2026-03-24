#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if(num<=9 && num>=0){
            return num;
        }

        int sum=0;
        int x=0;
        while(num>0){
            x=num%10;
            sum=sum+x;
            num=num/10;
            
        }
        sum=addDigits(sum);
        
        return sum;

    }
};

int main() {
    Solution s;
    cout<<s.addDigits(48);
    
    return 0;
}