#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode *ptr=head;
        while(ptr != nullptr){
            arr.push_back(ptr->val);
            ptr=ptr->next;
        }
        sort(arr.begin(),arr.end());
        // to sort in descending order 
        //sort(arr.begin(), arr.end(), greater<int>());
        ptr=head;
        for(int i:arr){
            ptr->val=i;
            ptr=ptr->next;
        }
        return head;
    }
};

int main() {
    
    return 0;
}