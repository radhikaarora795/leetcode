#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        int twenty=0;

        for(int i:bills){
            if(i==5){
                five++;
            }
            else if(i==10){
                if(five<=0){
                    return false;
                }
                five--;
                ten++;
            }
            else if(i==20){
                if(ten>=1 && five>=1){
                    ten--;
                    five--;
                }
                else if(five>=3){
                    five-=3;
                }
                else{
                    return false;
                }
                twenty++;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> bills={5,5,10,10,20};
    cout<<s.lemonadeChange(bills);
    
    return 0;
}
