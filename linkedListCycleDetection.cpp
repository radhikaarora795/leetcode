#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *createNode(int value){
        return new ListNode(value);
    }

    void insertAtEnd(ListNode **head,int value){
        ListNode *ptr=createNode(value);

        if((*head) == nullptr){
            (*head)=ptr;
            return;
        }

        ListNode *temp=(*head);
        while(temp->next != nullptr){
        temp=temp->next;
        }

        temp->next=ptr;
    }

    void display(ListNode *head){
        ListNode *ptr=head;
        while(ptr != nullptr){
            cout<<ptr->val<<" ";
            ptr=ptr->next;
        }
        cout<<endl;
    }

    bool hasCycle(ListNode *head) {
        ListNode *fast=head;
        ListNode *slow=head;

        while(fast != nullptr && fast->next != nullptr){
            fast=fast->next->next;
            slow=slow->next;

            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};

int main() {
    ListNode *head=nullptr;
    Solution s;

   s.insertAtEnd(&head,3);
   s.insertAtEnd(&head,2);
   s.insertAtEnd(&head,0);
   s.insertAtEnd(&head,-4);
    
    s.display(head);

    // create cycle: point last node (with value 5) to node with value 3
    ListNode *temp=head;
    ListNode *cycleStart=nullptr;
    
    while(temp->next != nullptr){
        if(temp->val == 2){
            cycleStart = temp;
        }
        temp = temp->next;
    }
    // temp now points to last node (value 5)
    temp->next = cycleStart;  // create cycle


    cout<<s.hasCycle(head);
    return 0;
}