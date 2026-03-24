#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>
#include <vector>
#include <string>

using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

// Function to perform arithmetic operations
int applyOp(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

// Convert infix to postfix (tokens separated by space)
vector<string> infixToPostfix(const string& expr) {
    stack<char> opStack;
    vector<string> output;
    size_t i = 0;
    while (i < expr.size()) {
        if (isspace(expr[i])) {
            ++i;
            continue;
        }
        if (isdigit(expr[i])) {
            // Read full number
            string number;
            while (i < expr.size() && isdigit(expr[i])) {
                number += expr[i++];
            }
            output.push_back(number);
        }
        else if (expr[i] == '(') {
            opStack.push(expr[i]);
            ++i;
        }
        else if (expr[i] == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                output.push_back(string(1, opStack.top()));
                opStack.pop();
            }
            if (!opStack.empty()) opStack.pop(); // remove '('
            ++i;
        }
        else {
            // operator
            char currOp = expr[i];
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(currOp)) {
                output.push_back(string(1, opStack.top()));
                opStack.pop();
            }
            opStack.push(currOp);
            ++i;
        }
    }
    while (!opStack.empty()) {
        output.push_back(string(1, opStack.top()));
        opStack.pop();
    }
    return output;
}

// Evaluate postfix expression
int evaluatePostfix(const vector<string>& tokens) {
    stack<int> st;
    for (const string& token : tokens) {
        if (isdigit(token[0])) {
            st.push(stoi(token));
        } else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int res = applyOp(a, b, token[0]);
            st.push(res);
        }
    }
    return st.top();
}

int main() {
    string expr;
    cout << "Enter the expression: ";
    getline(cin, expr);

    // Step 1: Convert to postfix
    vector<string> postfix = infixToPostfix(expr);

    cout << "Postfix expression: ";
    for (const string& token : postfix) cout << token << " ";
    cout << endl;

    // Step 2: Evaluate postfix
    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}
