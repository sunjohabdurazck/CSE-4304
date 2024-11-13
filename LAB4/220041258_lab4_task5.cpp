#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insert(Node*& head, int data) {
    if (head == nullptr) {
        head = new Node(data);
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new Node(data);
    }
}

void printList(Node* head) {
    if (head == nullptr) {
        cout << "Empty" << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


Node* findIntersection(Node* head1, Node* head2) {
    Node* result = nullptr;
    Node* temp1 = head1;
    Node* temp2 = head2;


    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1->data == temp2->data) {
            insert(result, temp1->data);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->data < temp2->data) {
            temp1 = temp1->next;
        } else {
            temp2 = temp2->next;
        }
    }
    return result;
}


Node* takeInput() {
    Node* head = nullptr;
    int value;
    while (cin >> value && value != -1) {
        insert(head, value);
    }
    return head;
}

int main() {
    Node* head1 = takeInput();
    Node* head2 = takeInput();

    Node* intersection = findIntersection(head1, head2);

    printList(intersection);

    return 0;
}
