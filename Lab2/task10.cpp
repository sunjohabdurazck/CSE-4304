#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
int arr[MAX_SIZE];
int front = 0;
int rear = -1;
int count = 0;

void push_front(int key) {
    if (count == MAX_SIZE) {
        cout << "Overflow\n";
        return;
    }
    front = (front - 1 + MAX_SIZE) % MAX_SIZE;
    arr[front] = key;
    count++;
}

void push_back(int key) {
    if (count == MAX_SIZE) {
        cout << "Overflow\n";
        return;
    }
    rear = (rear + 1) % MAX_SIZE;
    arr[rear] = key;
    count++;
}

int pop_front() {
    if (count == 0) {
        cout << "Underflow\n";
        return -1;
    }
    int item = arr[front];
    front = (front + 1) % MAX_SIZE;
    count--;
    return item;
}

int pop_back() {
    if (count == 0) {
        cout << "Underflow\n";
        return -1;
    }
    int item = arr[rear];
    rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
    count--;
    return item;
}

int size() {
    return count;
}

void printQueue() {
    if (count == 0) {
        cout << "Queue is empty." << endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        cout << arr[(front + i) % MAX_SIZE] << " ";
    }
    cout << endl;
}

int main() {
    int choice, value;

    while (true) {
        cin >> choice;

        switch (choice) {
            case 1:

                cin >> value;
                push_front(value);
                printQueue();
                break;
            case 2:
                cin >> value;
                push_back(value);
                printQueue();
                break;
            case 3:
                value = pop_front();
                if (value != -1) {

                }
                printQueue();
                break;
            case 4:
                value = pop_back();
                if (value != -1) {

                }
                printQueue();
                break;
            case 5:
                cout << size() << endl;
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
