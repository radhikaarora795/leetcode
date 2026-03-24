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
    ListNode *createNode(int data){
        return new ListNode(data);
    }

    void insertAtEnd(ListNode **head, int data){
        ListNode *ptr=createNode(data);

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

    ListNode* reverseList(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode *prev=nullptr;
        ListNode *current=head;
        ListNode *after=current->next;

        while(current != nullptr){
            after=current->next;
            current->next=prev;
            prev=current;
            current=after;
        }
        return prev;
    }

    void display(ListNode *ptr){
        while(ptr != nullptr){
            cout<<ptr->val<<" ";
            ptr=ptr->next;
        }
        cout<<endl;
    }
};


int main() {
    Solution s;
    ListNode *head=nullptr;

    /*for(int i=1;i<=5;i++){
        s.insertAtEnd(&head,i);
    }*/

    s.insertAtEnd(&head,1);
    s.insertAtEnd(&head,2);

    cout<<"before"<<endl;
    s.display(head);
    cout<<"after"<<endl;
    head=s.reverseList(head);
    s.display(head);

    return 0;
}