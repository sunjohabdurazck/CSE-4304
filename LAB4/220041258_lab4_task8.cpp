#include <iostream>
#include<cstring>
#include <sstream>

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

    void insert_back(char key) {
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


    void rearrange_odd_even() {
        if (head == nullptr || head->next == nullptr) return;

        Node* odd = head;
        Node* even = head->next;
        Node* even_head = even;


        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = even_head;
    }

    void print_list() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;

        }
        cout<<"NULL";
        cout << endl;
    }
};


int main() {
    SinglyLinkedList list;
    string input;


    while (getline(cin, input)) {

        if (input.empty()) break;


        istringstream ss(input);
        int value;

        while (ss >> value) {
            list.insert_back(value);
        }

        list.rearrange_odd_even();

        list.print_list();


    }

    return 0;
}
