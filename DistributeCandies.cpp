/*
To maximize the number of different kinds your sister gets:
Count how many different kinds of candies are there.
She can get at most n/2 candies.
So, the answer is: min(number of different kinds,n/2)
*/

// The goal: maximize the number of different kinds of candies your sister gets.
/*
To know how many different kinds of candies there are, we need to:
Ignore duplicates.
Count only unique types.
This is exactly what a set or unordered_set is built for.
*/

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> set;
        int length=candyType.size();

        for(int i=0;i<length;i++){
            set.insert(candyType[i]);
        }

        return min((int)set.size(),(length/2));
    }
};

int main() {
    Solution s;
    vector<int> v={6,6,6,6};
    cout<<s.distributeCandies(v);
    
    return 0;
}