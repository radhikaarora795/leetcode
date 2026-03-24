#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

ListNode *createNode(ListNode *head,int data){
    ListNode *newNode=new ListNode();
    newNode->val=data;
    newNode->next=nullptr;
    if(head == nullptr){
        head=newNode;
    }
    else{
        ListNode *ptr=head;
        while(ptr->next != nullptr){
            ptr=ptr->next;
        }
        ptr->next=newNode;
    }
    return head;
}

void print(ListNode *head){
    ListNode *ptr=head;
    while(ptr != nullptr){
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }
}

ListNode* middleOfLinkedList(ListNode *head){
    ListNode *fast=head;
    ListNode *slow=head;

    while(fast!= nullptr && fast->next != nullptr){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

ListNode* spiral(ListNode *head){
    ListNode *middle=middleOfLinkedList(head);
    stack<ListNode*> s;
    queue<ListNode*> q;

    ListNode *ptr=head;

    while(ptr != nullptr && ptr != middle){
        s.push(ptr);
        ptr=ptr->next;
    }
    ptr=ptr->next;
    middle->next=nullptr;
    while(ptr != nullptr){
        q.push(ptr);
        ptr = ptr->next;
    }
    ptr=middle;
    while(!s.empty() || !q.empty()){
        if(!s.empty()){
            ptr->next=s.top();
            s.pop();
            ptr=ptr->next;
        }
        if(!q.empty()){
            ptr->next=q.front();
            q.pop();
            ptr=ptr->next;
        }
    }
    ptr->next=nullptr;
    return middle;
}

int main() {
    ListNode *head=nullptr;

    for(int i=1;i<=6;i++){
        head=createNode(head,i);
    }
    head=spiral(head);
    print(head);
    
    return 0;
}