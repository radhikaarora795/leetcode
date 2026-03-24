#include <iostream>
#include <unordered_set>
using namespace std;

/* use Floyd's cycle algorithm 
two pointers: slow=slow->next;
fast=fast->next->next (linked list)
no extra space used
*/

class Solution {
public:
    int sumSquares(int n){
        int sum=0;
        int x=0;

        while(n>0){
            x=n%10;
            sum+=x*x;
            n=n/10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow=n;
        int fast=sumSquares(n);
        // Loop until the fast pointer reaches 1 (happy) or both pointers meet (cycle)
        while(fast!=1 && fast!=slow){
            slow=sumSquares(slow);              // slow=slow->next;
            fast=sumSquares(sumSquares(fast));  //fast=fast->next->next;
        }
        if(fast == 1){
            return true;
        }
        else{
            return false;
        }
    }

    // unordered set approach
    bool isHappy2(int n){
        unordered_set<int> set; // Set to keep track of numbers we have already seen, If a number repeats, we have detected a cycle
          // Continue until we either reach 1 or detect a cycle
        while(n != 1){
            // If n is already in the set, a cycle exists
            // This means the number is not happy
            if(set.count(n)){
                return false;
            }
            // Mark the current number as visited
            set.insert(n);
            // Move to the next number in the sequence
            // by replacing n with the sum of squares of its digits
            n=sumSquares(n);
        }
        return true;
    }
};

int main() {
    Solution s;
    cout<<s.isHappy(2);
    
    return 0;
}