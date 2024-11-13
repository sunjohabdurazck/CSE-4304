#include <iostream>

using namespace std;


struct Node {
    int data;
    Node* prev;
    Node* next;
};

class Deque {
private:
    Node* head;
    Node* tail;
    int count;

public:
    Deque() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    void push_front(int key) {
        Node* new_node = new Node();
        new_node->data = key;
        new_node->prev = nullptr;
        new_node->next = head;

        if (head != nullptr) {
            head->prev = new_node;
        }
        head = new_node;

        if (tail == nullptr) {
            tail = new_node;
        }

        count++;
        print_deque();
    }


    void push_back(int key) {
        Node* new_node = new Node();
        new_node->data = key;
        new_node->next = nullptr;
        new_node->prev = tail;

        if (tail != nullptr) {
            tail->next = new_node;
        }
        tail = new_node;

        if (head == nullptr) {
            head = new_node;
        }

        count++;
        print_deque();
    }


    int pop_front() {
        if (head == nullptr) {
            cout << "Error: Deque is empty!" << endl;
            return -1;
        }

        int val = head->data;
        Node* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete temp;
        count--;

        print_deque();
        return val;
    }


    int pop_back() {
        if (tail == nullptr) {
            cout << "Error: Deque is empty!" << endl;
            return -1;
        }

        int val = tail->data;
        Node* temp = tail;
        tail = tail->prev;

        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }

        delete temp;
        count--;

        print_deque();
        return val;
    }


    int size() {
        cout<< count << endl;
        return count;
    }

    void print_deque() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "Empty";
        }
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Deque list;
    int option;
while (1){
    cin>>option;
    if(option==1){

            int insert;
    cin>>insert;
            list.push_front(insert);

    }
    else if(option==2){
            int insert;
    cin>>insert;
   list.push_back(insert);

    }
    else if(option==3){
           list.pop_front();


    }
    else if(option==4){
   list.pop_back();

    }
    else if(option==5){
     list.size();
    }
    else if(option==6){
    exit(0);
    }
}
    return 0;
}
