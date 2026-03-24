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

    int getDecimalValue(ListNode* head) {
        int num=0;
        while(head!=nullptr){
            num=num*2 + head->val;
            head=head->next;
        }
        return num;
    }
};

int main() {
    ListNode *head=nullptr;
    Solution s;
   // s.insertAtEnd(&head,1);
    s.insertAtEnd(&head,0);
    //s.insertAtEnd(&head,1);
    s.display(head);
    cout<<s.getDecimalValue(head);
    
    return 0;
}