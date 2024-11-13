#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }


    void insert_back(int key) {
        Node* new_node = new Node();
        new_node->data = key;
        new_node->next = nullptr;

        if (head == nullptr) {
            head = new_node;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }


    void remove_duplicates() {
        if (head == nullptr) return;

        Node* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->data == current->next->data) {
                Node* duplicate = current->next;
                current->next = current->next->next;
                delete duplicate;
            } else {
                current = current->next;
            }
        }
    }


    void print_list() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int value;



    while (true) {
        cin >> value;
        if (value == -1) {
            break;
        }
        list.insert_back(value);
    }

    list.remove_duplicates();

    list.print_list();

    return 0;
}
