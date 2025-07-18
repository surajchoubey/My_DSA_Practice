// https://www.youtube.com/watch?v=4pIc9UBHJtk

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// Function to check if a character is operator
bool isOperator(char c) {
    return (!isalnum(c) && c != ' ');
}

// Priority of operators
int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

// Convert INFIX to POSTFIX
string infixToPostfix(string infix) {
    stack<char> st;
    string result;

    for(char c : infix) {
        if(isalnum(c)) {
            result += c;
        } else if(c == '(') {
            st.push(c);
        } else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                result += st.top(); st.pop();
            }
            st.pop(); // Pop '('
        } else {
            while(!st.empty() && precedence(st.top()) >= precedence(c)) {
                result += st.top(); st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()) {
        result += st.top(); st.pop();
    }

    return result;
}

// Convert INFIX to PREFIX
string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }
    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

// Convert PREFIX to INFIX
string prefixToInfix(string prefix) {
    stack<string> st;
    for(int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        if(isalnum(c)) {
            st.push(string(1, c));
        } else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string expr = "(" + op1 + c + op2 + ")";
            st.push(expr);
        }
    }
    return st.top();
}

// Convert PREFIX to POSTFIX
string prefixToPostfix(string prefix) {
    stack<string> st;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isalnum(c)) {
            st.push(string(1, c));
        } else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string expr = op1 + op2 + c;
            st.push(expr);
        }
    }
    return st.top();
}

// Convert POSTFIX to INFIX
string postfixToInfix(string postfix) {
    stack<string> st;
    for(char c : postfix) {
        if(isalnum(c)) {
            st.push(string(1, c));
        } else {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            string expr = "(" + op1 + c + op2 + ")";
            st.push(expr);
        }
    }
    return st.top();
}

// Convert POSTFIX to PREFIX
string postfixToPrefix(string postfix) {
    stack<string> st;
    for(char c : postfix) {
        if(isalnum(c)) {
            st.push(string(1, c));
        } else {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            string expr = c + op1 + op2;
            st.push(expr);
        }
    }
    return st.top();
}

// Main function to test
int main() {
    string infix = "a+b*c";
    string prefix = "+a*bc";
    string postfix = "abc*+";

    cout << "Infix to Prefix:   " << infixToPrefix(infix) << endl;
    cout << "Infix to Postfix:  " << infixToPostfix(infix) << endl;

    cout << "Prefix to Infix:   " << prefixToInfix(prefix) << endl;
    cout << "Prefix to Postfix: " << prefixToPostfix(prefix) << endl;

    cout << "Postfix to Infix:  " << postfixToInfix(postfix) << endl;
    cout << "Postfix to Prefix: " << postfixToPrefix(postfix) << endl;

    return 0;
}
