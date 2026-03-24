#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> mainStack;
    stack<int> minStack;

    MinStack() {
        
    }
    
    void push(int val) {
        mainStack.push(val);
        if(minStack.empty() || val<= minStack.top()){
            minStack.push(val);
        }
    }
    
    void pop() {
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }
    
    int top() {
      return mainStack.top();  
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout<<minStack.getMin()<<endl; // return -3
    minStack.pop();
    cout<<minStack.top()<<endl;    // return 0
    cout<<minStack.getMin()<<endl; // return -2
    
    return 0;
}