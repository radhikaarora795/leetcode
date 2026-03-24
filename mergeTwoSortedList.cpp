/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *p1=list1,*p2=list2;
        ListNode *p3=nullptr;
        ListNode *last=nullptr;
        

        while(p1 != nullptr || p2 != nullptr){
            if(p1!= NULL && p2!= NULL ){
                if(p1->val <= p2->val){
                    if(p3 == nullptr){
                        p3=p1;
                        last = p3;
                        p1=p1->next;
                        last->next = nullptr;
                    }
                    else{
                        last->next=p1;
                        last=p1;
                        p1=p1->next;
                        last->next=nullptr;
                    }
                   
                }
                else if(p2->val < p1->val){
                    if(p3 == nullptr){
                        p3=p2;
                        last = p3;
                        p2=p2->next;
                        last->next = nullptr;
                    }
                    else{
                        last->next=p2;
                        last=p2;
                        p2=p2->next;
                        last->next=nullptr;
                    }
                    
                }
            } else if(p1==nullptr && p2!=nullptr){
                if(p3==nullptr){
                    p3=p2;
                } else{
                    last->next = p2;
                }
                break;
            } else if(p2==nullptr && p1!=nullptr){
                if(p3==nullptr){
                    p3=p1;
                } else{
                    last->next = p1;
                }
                break;
            } 
            
        }
    return p3;
    }
};

int main(){

    return 0;
}