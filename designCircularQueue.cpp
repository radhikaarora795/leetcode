#include <iostream>
using namespace std;

class MyCircularQueue {
    int *q;
    int front,rear,size,capacity;
public:
    MyCircularQueue(int k) {
        q=new int[k];
        capacity=k;
        front=-1;
        rear=-1;
        size=0;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        if(front == -1){
            front=0;
        }
        rear=(rear+1)%capacity;
        q[rear]=value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        front=(front+1)%capacity;
        size--;
        if(size == 0){
            front=-1;
            rear=-1;
        }
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        else{
            return q[front];
        }
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        else{
            return q[rear];
        }
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main() {
    MyCircularQueue q(3);
    cout << q.enQueue(1) << endl; // true
    cout << q.enQueue(2) << endl; // true
    cout << q.enQueue(3) << endl; // true
    cout << q.enQueue(4) << endl; // false (queue full)
    cout << q.Rear() << endl;     // 3
    cout << q.isFull() << endl;   // true
    cout << q.deQueue() << endl;  // true
    cout << q.enQueue(4) << endl; // true
    cout << q.Rear() << endl;     // 4
    return 0;
    
    return 0;
}