#include <iostream>
#include <cctype> 
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        bool isNegative=false;
        bool signencountered=false; 
        //int length=s.size();
        int j=0;
        int result=0;

        while(s[j]==' '){
            j++;
        }

        if(s[j]=='-'){
            isNegative=true;
            j++;
        } else if (s[j]=='+'){
            j++;
        }

        for(int i=j; i<s.size();i++){
            
            if(s[i] == ' '){
                break;
            }
            else if(isdigit(s[i])){
                /*Rounding: if the final computed number is less than INT_MIN, return INT_MIN.
                If the final number is greater than INT_MAX, return INT_MAX. */
                if (result > (INT_MAX - (s[i] - '0')) / 10) { //add overflow checks while processing
                    return isNegative ? INT_MIN : INT_MAX;
                }

                result=result*10+(s[i]-'0');
            }
            else{
                if(isNegative){
                    result=result*(-1);
                }
                return result;
            }
        }
        if(isNegative){
            result=result*(-1);
        }
        return result;
    }
};

int main() {
    Solution s;
    cout<<endl<<s.myAtoi("1337c")<<endl;
    cout<<s.myAtoi("1-0")<<endl;
    cout<<s.myAtoi("words 1555")<<endl;
    cout<<s.myAtoi("4193 with words")<<endl;
    cout<<s.myAtoi("     -042")<<endl;
    cout<<s.myAtoi("          +045")<<endl;
    cout<<s.myAtoi("   123")<<endl;
    return 0;
}