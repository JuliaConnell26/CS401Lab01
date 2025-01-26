#include <iostream>
#include <string>

using namespace std;

class Array {
private:
    static const int MAX_SIZE = 100000;
    char stack[MAX_SIZE];
    int topIndex; 

public:
    Array() {
        topIndex = -1;
    }

    void push(char ch) {
        if (topIndex >= MAX_SIZE - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        stack[++topIndex] = ch;
    }

    void pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        topIndex--;
    }

    char top() { 
        if (topIndex == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return stack[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};

bool Match(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}
bool Balanced(const string &expr) {
    Array stack;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.isEmpty()) {
                return false;
            }
            char topChar = stack.top();
            if (topChar == -1) return false; 
            stack.pop();
            if (!Match(topChar, ch)) {
                return false;
            }
        }
    }

    return stack.isEmpty();
}
int main() {
    string test[] = {
        "((()))",
        "{[()]}",
        "(hello world[])",
        "a + (b * [c - d])"
    };
    for (int i = 0; i < 4; i++) {
        if (Balanced(test[i])) {
            cout << test[i] << " is Balanced" << endl;
        } else {
            cout << test[i] << " is Not Balanced" << endl;
        }
    }
    return 0;
}
