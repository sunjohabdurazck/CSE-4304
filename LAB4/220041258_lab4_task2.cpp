#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void print_list()
    {
        if (head == nullptr)
        {
            cout << "Empty" << endl;
            cout << "NULL (HEAD) (TAIL)" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data;
            if (temp == head)
            {
                cout << " (HEAD)";
            }
            if (temp == tail)
            {
                cout << " (TAIL)";
            }
            if (temp->next != nullptr)
            {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    void insert_front(int key)
    {
        Node* new_node = new Node();
        new_node->data = key;
        new_node->prev = nullptr;
        new_node->next = head;

        if (head != nullptr)
            head->prev = new_node;
        head = new_node;

        if (tail == nullptr)
            tail = new_node;

        print_list();
    }

    void insert_back(int key)
    {
        Node* new_node = new Node();
        new_node->data = key;
        new_node->next = nullptr;
        new_node->prev = tail;

        if (tail != nullptr)
            tail->next = new_node;
        tail = new_node;

        if (head == nullptr)
            head = new_node;

        print_list();
    }

    void insert_after_node(int key, int v)
    {
        Node* temp = head;
        while (temp != nullptr && temp->data != v)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Value Not found" << endl;
            print_list();
            return;
        }

        Node* new_node = new Node();
        new_node->data = key;
        new_node->next = temp->next;
        new_node->prev = temp;

        if (temp->next != nullptr)
            temp->next->prev = new_node;
        temp->next = new_node;

        if (new_node->next == nullptr)
            tail = new_node;

        print_list();
    }

    void update_node(int key, int v)
    {
        Node* temp = head;
        while (temp != nullptr && temp->data != v)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Value Not found" << endl;
            print_list();
            return;
        }

        temp->data = key;

        print_list();
    }

    void remove_head()
    {
        if (head == nullptr)
        {
            cout << "Underflow" << endl;
            cout << "Empty" << endl;
            print_list();
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;

        delete temp;

        print_list();
    }

    void remove_end()
    {
        if (tail == nullptr)
        {
            cout << "Underflow" << endl;
            cout << "Empty" << endl;
            print_list();
            return;
        }

        Node* temp = tail;
        tail = tail->prev;

        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr;

        delete temp;

        print_list();
    }

    void remove_element(int key)
    {
        if (head == nullptr)
        {
            cout << "Value Not found" << endl;
            cout << "Empty" << endl;
            print_list();
            return;
        }

        Node* temp = head;
        while (temp != nullptr && temp->data != key)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Value Not found" << endl;
            print_list();
            return;
        }

        if (temp->prev != nullptr)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next != nullptr)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev;

        delete temp;

        print_list();
    }
};

int main()
{
    DoublyLinkedList list;
    string option;

    while (true)
    {
        cin >> option;
        if (option == "EXIT")
            break;

        if (option == "INSERT_FRONT")
        {
            int insert;
            cin >> insert;
            list.insert_front(insert);
        }
        else if (option == "INSERT_BACK")
        {
            int insert;
            cin >> insert;
            list.insert_back(insert);
        }
        else if (option == "INSERT_AFTER")
        {
            int insert, key;
            cin >> insert >> key;
            list.insert_after_node(insert, key);
        }
        else if (option == "UPDATE")
        {
            int insert, key;
            cin >> insert >> key;
            list.update_node(insert, key);
        }
        else if (option == "REMOVE_HEAD")
        {
            list.remove_head();
        }
        else if (option == "REMOVE")
        {
            int remove;
            cin >> remove;
            list.remove_element(remove);
        }
        else if (option == "REMOVE_TAIL")
        {
            list.remove_end();
        }
        else
        {
            exit(0);
        }
    }

    return 0;
}
