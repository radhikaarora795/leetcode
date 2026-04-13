#include <iostream>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // floyd's cycle detection
        // linked list cycle problem
        int slow=0;
        int fast=0;
        while(true){
            slow=nums[slow];    // slow=slow->next;
            fast=nums[nums[fast]];  // fast=fast->next->next
            if(slow == fast){
                break;
            }
        }
        slow=0;
        while(slow != fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};

int main() {
    
    return 0;
}