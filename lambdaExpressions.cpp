#include <iostream>
using namespace std;

// passing lamba to a function:
void func(function<void()> f){      //A function that takes another function as parameter
    f();
    f();
}

int main() {
    /*
    A lambda expression in C++ is an anonymous function (a function without
    a name) 
    that can be defined directly in the body of code, often used for short 
    callbacks, 
    predicates, or custom sorting.

    syntax: 
    [capture] (parameters) { code };
    []: capture clause
    You can use the [ ] brackets to give a lambda access to variables outside 
    of it.

    */

    // basic lambda example
    auto message=[](){
        cout<<"message"<<endl;
    };

    message();

    // capture clause: in this example, the lambda captures the variable x by value (a copy):
    int x=10;
    auto show=[x](){
        cout<<x<<endl;
    };
    show();

    /*
    Capture By Reference:
    If you want the lambda to use the latest value of a variable (not just a copy), 
    you can use [&] to capture it by reference.
    This means the lambda will work with the original variable, not a separate copy:
    */

    int y=15;
    auto display=[&y](){
        cout<<"y: "<<y<<endl;
    };
    y=25;
    display();

    // lambda with parameters
    auto add = [](int a, int b) {
        return a + b;
    };

    cout << add(3, 4)<<endl;

     auto m=[](){
        cout<<"message2"<<endl;
    };

    func(m);

    // using lambda in loops
    for(int i=1;i<=3;++i){
        auto show=[i](){
            cout<<"number "<<i<<endl;
        };
        show();
    }
    
    return 0;
}