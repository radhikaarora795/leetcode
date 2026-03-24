#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        int noOfZeroes=log10(num);
        int result=0;
        int digit=0;
        bool flag=true;

        while(num>0){
            digit=num/pow(10,noOfZeroes);
            if(digit == 6 && flag==true){
                result=result*10+9;
                flag=false;
            }
            else{
                result=result*10+digit;
            }
            num=num-digit*pow(10,noOfZeroes);
            noOfZeroes--;
            //cout<<endl<<count<<" "<<result<<endl;
        
        }

        return result;
    }
};

int main() {
    Solution s;
    cout<<s.maximum69Number(9);
    
    return 0;
}