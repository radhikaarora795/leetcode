#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());

        int left=0;
        int right=people.size()-1;
        int count=0;

        while(left<=right){
            if(people[left]+people[right]<=limit){
                left++;
            }
            right--;
            count++;
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> v={3,5,3,4};
    cout<<s.numRescueBoats(v,5);
    
    return 0;
}