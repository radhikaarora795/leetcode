#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node *createNode(int d){
    node *ptr = new node;
    ptr->data=d;
    ptr->next=nullptr;
    return ptr;
}

void appendNode(node **start, int d){
    node *ptr=createNode(d);
    if(ptr == nullptr){
        return;
    }
    if((*start) == nullptr){
        (*start)=ptr;
    }
    node *temp=(*start);
    while(temp->next != nullptr){
        temp=temp->next;
    }
    temp->next=ptr;
}

node *search(node *start, int val){
    if(start == nullptr){
        return nullptr;
    }
    node *ptr=start;
    while(ptr != nullptr && ptr->data != val){
        ptr=ptr->next;
    }
    return ptr;
}

int main() {
    
    return 0;
}