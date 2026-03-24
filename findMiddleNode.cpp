#include <iostream>
#include <unordered_map>
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
        ListNode *fast=head;
        ListNode *slow=head;

        while(fast != nullptr && fast->next !=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
};

int main() {
    ListNode *head=nullptr;
    Solution s;

    for(int i=1;i<=6;i++){
        s.insertAtEnd(&head,i);
    }

    s.display(head);

    ListNode *ptr=s.middleNode(head);

    if(ptr != nullptr){
        cout<<ptr->val<<endl;
    }
    else{
        cout<<"empty";
    }
    
    return 0;
}