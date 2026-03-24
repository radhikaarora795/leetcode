#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced=0;
        for(int i=0;i<fruits.size();i++){
            bool placed=false;
            for(int j=0;j<baskets.size();j++){
                if(baskets[j]!=-1 && baskets[j]>=fruits[i]){
                    baskets[j]=-1;
                    placed=true;
                    break;
                }
            }
            if(!placed){
                unplaced++;
            }
        }
        return unplaced;
    }
};

int main() {
    Solution s;
    vector<int> fruits={4,2,5};
    vector<int> baskets={3,5,4};
    cout<<s.numOfUnplacedFruits(fruits,baskets);
    
    return 0;
}