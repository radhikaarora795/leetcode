/*
If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
using namespace std;

// 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).

class Solution {
public:
    string convert(int num){
        unordered_map<int,string> map;
        map[1]="I";
        map[2]="II";
        map[3]="III";
        map[4]="IV";
        map[5]="V";
        map[9]="IX";
        map[10]="X";
        map[40]="XL";
        map[50]="L";
        map[90]="XC";
        map[100]="C";
        map[400]="CD";
        map[500]="D";
        map[900]="CM";
        map[1000]="M";

        string str="";
        //cout<<"  n1 "<<num <<endl;
        while(num>0){
            
            if(num>=1000){
                str=str+map[1000];
                num=num-1000;
            }
            else if(num==900 || num==400 || num == 90 || num == 40 || num ==4 || num == 9){
                str=str+map[num];
                break;                
            }
            else if(num>=500){
                str=str+map[500];
                num=num-500;
            }
            else if(num>=100){
                str=str+map[100];
                num=num-100;
            }
            else if(num>=50){
                str=str+map[50];
                num=num-50;
            }            
            else if(num>=10){
                str=str+map[10];
                num=num-10;
            }
            else if(num>=5){
                str=str+map[5];
                num=num-5;
            }
            else {
                str=str+map[num];
                break;
            }
        }
        return str;
    }

    string intToRoman(int num) {

        int count=0;
        string result;
        while(num>0){
            int n1=num%10;
            n1=n1*pow(10,count);
            result=convert(n1) + result;            
            num=num/10;
            count++;
        }
    return result;
    }  
};


int main() {
    Solution s;
    cout<<s.intToRoman(1994);
    return 0;
}