#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;
    int currentSize;
    int maxSize;

public:
    Stack(int size) {
        top = nullptr;
        currentSize = 0;
        maxSize = size;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    bool isFull() {
        return currentSize == maxSize;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Overflow";
            return;
        }
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        currentSize++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Underflow";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        currentSize--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty";
            return -1;
        }
        return top->data;
    }

    int size() {
        return currentSize;
    }

    void printStack() {
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int N;
    cin >> N;
    Stack stack(N);

    int command;
    while (cin >> command && command != -1) {
        switch (command) {
            case 1: {
                int value;
                cin >> value;
                stack.push(value);
                stack.printStack();
                break;
            }
            case 2: {
                stack.pop();
                stack.printStack();
                break;
            }
            case 3: {
                cout << (stack.isEmpty() ? "True" : "False") << endl;
                break;
            }
            case 4: {
                cout << (stack.isFull() ? "True" : "False") << endl;
                break;
            }
            case 5: {
                cout << stack.size() << endl;
                break;
            }
            case 6: {
                cout << stack.peek() << endl;
                break;
            }
            default:
                break;
        }
    }

    return 0;
}
