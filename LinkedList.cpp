#include <iostream>
#include <string>

using namespace std;

struct Node {
    char value;
    Node* next;
    Node(char c) : value(c), next(nullptr) {}
};
class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void push(char ch) {
        Node* newNode = new Node(ch);
        newNode->next = head;
        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            cout << "Error: Stack is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    char top() {
        if (head == nullptr) {
            cout << "Error: Stack is empty." << endl;
            return -1;
        }
        return head->value;
    }

    bool isEmpty() {
        return head == nullptr;
    }
};

bool Match(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool Balanced(const string &expr) {
    LinkedList stack;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.isEmpty()) {
                return false;
            }
            char topChar = stack.top();
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
        "a + (b * [c - d])"
    }; 
    for (int i = 0; i < 3; i++) {
        cout << test[i] << " - ";
        if (Balanced(test[i])) {
            cout << "Balanced";
        } else {
            cout << "Not Balanced";
        }
        cout << endl;
    }
    return 0;
}
