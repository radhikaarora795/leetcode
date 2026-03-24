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

    ListNode* createNode(int info){
        ListNode *ptr=new ListNode(info);

        return ptr;
    }

    void append(ListNode **first,ListNode** last, int info){
        ListNode *p=nullptr;
        if((*first)==nullptr){
            (*first)=createNode(info);
            (*last)=(*first);
            return;
        }
        (*last)->next=createNode(info);
        (*last)=(*last)->next;
        
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3=nullptr;
        ListNode *last=l3;
        int carry=0;
        while(l1!=nullptr || l2!=nullptr){
            if(l1!=nullptr && l2!=nullptr){
                int sum=(l1->val)+(l2->val)+carry;
                if(sum>9){
                    sum=sum%10;
                    carry=1;
                }else{
                    carry=0;
                }
               append(&l3,&last,sum);
                
            }
        
            else if(l1 != nullptr && l2 == nullptr){
                int sum=(l1->val)+carry;
                if(sum>9){
                    sum=sum%10;
                    carry=1;
                }else{
                    carry=0;
                }
                append(&l3,&last,sum);
            }
            else if(l1 == nullptr && l2 != nullptr){
                int sum=(l2->val)+carry;
                if(sum>9){
                    sum=sum%10;
                    carry=1;
                }else{
                    carry=0;
                }
                append(&l3,&last,sum);
            }
            
            if(l1 != nullptr){
                l1=l1->next;
            }
            if(l2 != nullptr){
                l2=l2->next;
            }
        }
        if(l1==nullptr && l2==nullptr){
            if(carry==1){
                append(&l3,&last,1);
            }
        }
        return l3;
    }

    void wasteAppend(ListNode ** l,int i){
        ListNode * ptr = (*l);
        if (ptr == nullptr){
            *l = createNode(i);
            return;
        }
        
        while( ptr->next != nullptr){
            ptr=ptr->next;
        }
        ptr->next=createNode(i);
        
        
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

    ListNode *head1=nullptr;
    ListNode *head2=nullptr;
    ListNode *l3=nullptr;
    //head1=s.createNode(1);

    s.wasteAppend(&head1,9);
    s.wasteAppend(&head1,9);
    s.wasteAppend(&head1,9);
    s.wasteAppend(&head1,9);
    s.wasteAppend(&head1,9);
    s.wasteAppend(&head1,9);
    s.wasteAppend(&head1,9);


    s.wasteAppend(&head2,9);
    s.wasteAppend(&head2,9);
    s.wasteAppend(&head2,9);
    s.wasteAppend(&head2,9);

    l3=s.addTwoNumbers(head1,head2);
    s.display(l3);

    return 0;
}