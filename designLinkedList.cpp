/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

#include <iostream>
using namespace std;

class MyLinkedList {
public:
    struct node{
        int val;
        node *next;

        node(int v): val(v), next(nullptr)
            {}
    };

    node *createNode(int info){
    return new node(info); // uses constructor
    }

    node *head;
    int size;

    MyLinkedList(): head(nullptr), size(0) 
        {}
    
    int get(int index) {
        node *ptr=head;
        if(index<0 || index>=size){
            return -1;
        }
        for(int i=0;i<index;i++){
            ptr=ptr->next;
        }
        return ptr->val;
    }
    
    void addAtHead(int val) {
        node *ptr=createNode(val);
        ptr->next=head;
        head=ptr;
        ++size;
    }
    
    void addAtTail(int val) {
        node *ptr=createNode(val);

        if(head == nullptr){
            head=ptr;
            ++size;
            return;
        }

        node *temp=head;

        while(temp->next != nullptr){
            temp=temp->next;
        }

        temp->next=ptr;
        ++size;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>size){
            return;
        }
        if(index == 0){
            addAtHead(val);
            return;
        }
        node *ptr=createNode(val);
        node *temp=head;

        for(int i=0;i<index-1;i++){
            temp=temp->next;
        }
        ptr->next=temp->next;
        temp->next=ptr;
        ++size;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size){
            return;
        }

        node *toDel=head;

        if(index == 0){
            head=head->next;
        }
        else{
            node *temp=head;
            for(int i=0;i<index-1;i++){
                temp=temp->next;
            }
            toDel=temp->next;
            temp->next=toDel->next;
        }
        delete toDel;
        --size;
    }

    /*void display(){
    node *ptr=head;
    while(ptr != nullptr){
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
    }*/
};

int main() {
    MyLinkedList *obj=new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1,2);
    obj->display();
    cout<<obj->get(1)<<endl;
    obj->deleteAtIndex(1);
    obj->display();
    cout<<obj->get(1);
    
    return 0;
}