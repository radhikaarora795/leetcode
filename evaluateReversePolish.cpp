#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int length=tokens.size();

        for(int i=0;i<length;i++){
            string str=tokens[i];
            if(str == "+" || str == "-" || str == "*" || str == "/"){
                int operand2=st.top();
                st.pop(); // does not return anything
                int operand1=st.top();
                st.pop();

                if(str == "+"){
                    st.push(operand1+operand2);
                }
                else if(str == "-"){
                    st.push(operand1-operand2);
                }
                else if(str == "*"){
                    st.push(operand1*operand2);
                }
                else if(str == "/"){
                    st.push(operand1/operand2);
                }
            }
            else{
                st.push(stoi(str)); // convert string to integer
            }
        }
        return st.top();
    }
};

int main() {
    Solution s;
    vector<string> v={"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout<<s.evalRPN(v);
    
    return 0;
}