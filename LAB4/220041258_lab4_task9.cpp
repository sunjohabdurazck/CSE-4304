#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, capacity;
    int* arr;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % capacity == front);
    }

    void EnQueue(int x) {
        if (isFull()) {
            cout << "EnQueue: Overflow" << endl;
            return;
        }
        cout << "EnQueue: ";
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = x;
        printQueue();
    }

    void DeQueue() {
        if (isEmpty()) {
            cout << "DeQueue: Underflow" << endl;
            return;
        }
        cout << "DeQueue: ";
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        printQueue();
    }

    void size() {
        if (isEmpty()) {
            cout << "Size: 0" << endl;
        } else {
            int currentSize = (rear - front + capacity) % capacity + 1;
            cout << "Size: " << currentSize << endl;
        }
    }

    void frontElement() {
        if (isEmpty()) {
            cout << "Front: Empty" << endl;
        } else {
            cout << "Front: " << arr[front] << endl;
        }
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i != rear; i = (i + 1) % capacity) {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;
    }
};

int main() {
    int N;
    cin >> N;

    Queue q(5);

    while (true) {
        int functionID;
        cin >> functionID;

        if (functionID == -1) break;

        switch (functionID) {
            case 1: {
                int value;
                cin >> value;
                q.EnQueue(value);
                break;
            }
            case 2:
                q.DeQueue();
                break;
            case 3:
                cout << "isEmpty: " << (q.isEmpty() ? "True" : "False") << endl;
                break;
            case 4:
                cout << "isFull: " << (q.isFull() ? "True" : "False") << endl;
                break;
            case 5:
                q.size();
                break;
            case 6:
                q.frontElement();
                break;
            default:
                cout << "Invalid function ID" << endl;
        }
    }

    cout << "Exit" << endl;
    return 0;
}
