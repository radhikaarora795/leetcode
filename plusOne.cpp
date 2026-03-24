#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length=digits.size();
        int i=length-1;

        while(i>=0){
            if(digits[i]<9){
                digits[i]=digits[i]+1;
                return digits;
            }
            digits[i]=0;
            i--;
        }
        digits.insert(digits.begin(),1);


        /*for(int i=0;i<digits.size();i++){
            cout<<digits[i]<<" ";
        }*/
    
    return digits;
    }

};

int main() {
    Solution s;
    vector<int> v={9,9};
    vector<int> result=s.plusOne(v);
    for(int i:result){
        cout<<i<<" ";
    }
    
    return 0;
}