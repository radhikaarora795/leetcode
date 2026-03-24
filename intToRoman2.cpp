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

class Solution{
public:
    string convert(int num){
        unordered_map<int,string> map;
        map[1]="I";
        map[2]="II";
        map[3]="III";
        map[4]="IV";
        map[5]="V";
        map[6]="VI";
        map[7]="VII";
        map[8]="VIII";
        map[9]="IX";
        map[10]="X";
        map[20]="XX";
        map[30]="XXX";
        map[40]="XL";
        map[50]="L";
        map[60]="LX";
        map[70]="LXX";
        map[80]="LXXX";
        map[90]="XC";
        map[100]="C";
        map[200]="CC";
        map[300]="CCC";
        map[400]="CD";
        map[500]="D";
        map[600]="DC";
        map[700]="DCC";
        map[800]="DCCC";
        map[900]="CM";
        map[1000]="M";
        map[2000]="MM";
        map[3000]="MMM";

        string result="";
        int count=0;

        while(num>0){
            int n1=num%10;
            n1=n1*pow(10,count);
            auto it=map.find(n1);
            if (it !=map.end()){
                result=(it->second)+result;
            }
            num=num/10;
            count++;
        }
        return result;
    }
};

int main() {
    Solution s;
    cout<<s.convert(1994);
    return 0;
}