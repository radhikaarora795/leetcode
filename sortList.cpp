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

    ListNode* middleNode(ListNode* head) {
        // middleNode returns the node before the midpoint so we can break the list safely.
        ListNode *slow=head;
        ListNode *fast=head->next;

        while(fast != nullptr && fast->next !=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* l1,ListNode* l2){
        if(l1 == nullptr){ 
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }

        if(l1->val < l2->val){
            l1->next=merge(l1->next,l2);
            return l1;
        }
        else{
            l2->next=merge(l1,l2->next);
            return l2;
        }
    }


    ListNode* sortList(ListNode* head) {
        //Recursively splits the list into halves until 1-element lists remain.
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* mid=middleNode(head);
        ListNode* midNext=mid->next;
        mid->next=nullptr; 
        
        //sort each half
        ListNode* left=sortList(head);
        ListNode* right=sortList(midNext);

        return merge(left,right);
    } 
};

int main() {
    Solution s;
    ListNode *head=nullptr;
    // s.insertAtEnd(&head,-1);
    // s.insertAtEnd(&head,5);
    // s.insertAtEnd(&head,3);
    // s.insertAtEnd(&head,4);
    // s.insertAtEnd(&head,0);

    s.display(head);
    head=s.sortList(head);
    s.display(head);

    
    return 0;
}