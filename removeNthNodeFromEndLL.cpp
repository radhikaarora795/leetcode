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


    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy=new ListNode(0);   
        dummy->next=head;
        ListNode *fast=dummy;
        ListNode *slow=dummy;

        // Move fast pointer n+1 steps ahead so that there is a gap of n between fast and slow
        for(int i=0;i<=n;i++){
            fast=fast->next;
        }

        while(fast != nullptr){
            fast=fast->next;
            slow=slow->next;
        }

        ListNode *toDel=slow->next;
        slow->next=slow->next->next;

        delete toDel;

        /*
        The dummy node helps handle special cases, like:
        Removing the first node (head).
        List with only one node.
        */
        ListNode *newHead=dummy->next;
        delete dummy;
        return newHead;
    }
};

int main() {
    Solution s;
    ListNode *head=nullptr;

    for(int i=1;i<=2;i++){
        s.insertAtEnd(&head,i);
    }
    s.display(head);

    head=s.removeNthFromEnd(head,1);
    s.display(head);

    return 0;
}