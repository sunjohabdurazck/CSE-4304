#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* parent;
    int height;

    Node(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr), height(0) {}
};

class AVLTree
{
public:
    Node* root;

    AVLTree() : root(nullptr) {}

    void insertion(int key)
    {
        Node* newNode = new Node(key);
        if (!root)
        {
            root = newNode;
        }
        else
        {
            Node* current = root;
            Node* parent = nullptr;

            while (current)
            {
                parent = current;
                if (key < current->data)
                {
                    current = current->left;
                }
                else if (key > current->data)
                {
                    current = current->right;
                }
                else
                {
                    return;
                }
            }

            newNode->parent = parent;
            if (key < parent->data) parent->left = newNode;
            else parent->right = newNode;
        }

        Update_height(newNode->parent);
        if (!check_balance(newNode->parent))
        {

        }

        print_avl(root);
        cout << "\nBalanced";
        cout << "\nRoot=" << root->data << endl;
    }

    void Update_height(Node* node)
    {
        while (node)
        {
            node->height = 1 + max(height(node->left), height(node->right));
            node = node->parent;
        }
    }

    int height(Node* node)
    {
        return node ? node->height : -1;
    }

    int balance_factor(Node* node)
    {
        return node ? height(node->left) - height(node->right) : 0;
    }

    void left_rotate(Node* x)
    {
        cout << "Left_rotate(" << x->data << ")" << endl;
        Node* y = x->right;
        x->right = y->left;
        if (y->left) y->left->parent = x;
        y->parent = x->parent;

        if (!x->parent) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;

        y->left = x;
        x->parent = y;

        Update_height(x);
        Update_height(y);
    }

    void right_rotate(Node* y)
    {
        cout << "Right_rotate(" << y->data << ")" << endl;
        Node* x = y->left;
        y->left = x->right;
        if (x->right) x->right->parent = y;
        x->parent = y->parent;

        if (!y->parent) root = x;
        else if (y == y->parent->right) y->parent->right = x;
        else y->parent->left = x;

        x->right = y;
        y->parent = x;

        Update_height(y);
        Update_height(x);
    }

    bool check_balance(Node* node)
    {
        bool balanced = true;
        while (node)
        {
            Update_height(node);
            int bf = balance_factor(node);

            if (bf > 1)
            {
                print_avl(root);
                cout << "\nImbalance at node: " << node->data << endl;
                if (balance_factor(node->left) >= 0)
                {
                    cout << "LL case" << endl;
                    right_rotate(node);
                }
                else
                {
                    cout << "LR case" << endl;
                    left_rotate(node->left);
                    right_rotate(node);
                }
                balanced = false;
            }
            else if (bf < -1)
            {
                print_avl(root);
                cout << "\nImbalance at node: " << node->data << endl;
                if (balance_factor(node->right) <= 0)
                {
                    cout << "RR case" << endl;
                    left_rotate(node);
                }
                else
                {
                    cout << "RL case" << endl;
                    right_rotate(node->right);
                    left_rotate(node);
                }
                balanced = false;
            }
            node = node->parent;
        }
        return balanced;
    }

    void print_avl(Node* node)
    {
        if (node)
        {
            print_avl(node->left);
            cout << node->data << "(" << balance_factor(node) << ") ";
            print_avl(node->right);
        }
    }


    Node* min_value_node(Node* node)
    {
        Node* current = node;
        while (current && current->left)
        {
            current = current->left;
        }
        return current;
    }

    void deletion(int key)
    {
        Node* node = find_node(root, key);
        if (!node)
        {
            cout << "Node with key " << key << " not found!" << endl;
            return;
        }


        if (!node->left && !node->right)
        {
            if (node == root)
            {
                root = nullptr;
            }
            else if (node == node->parent->left)
            {
                node->parent->left = nullptr;
            }
            else
            {
                node->parent->right = nullptr;
            }
            delete node;
        }
        else if (!node->left || !node->right)
        {
            Node* child = node->left ? node->left : node->right;

            if (node == root)
            {
                root = child;
            }
            else if (node == node->parent->left)
            {
                node->parent->left = child;
            }
            else
            {
                node->parent->right = child;
            }

            child->parent = node->parent;
            delete node;
        }

        else
        {

            Node* successor = min_value_node(node->right);

            node->data = successor->data;


            deletion(successor->data);
        }

        Node* current = node->parent;
        while (current)
        {
            Update_height(current);
            check_balance(current);
            current = current->parent;
        }

        print_avl(root);
        cout << "\nRoot=" << root->data << endl;
    }

    Node* find_node(Node* node, int key)
    {
        while (node)
        {
            if (key < node->data)
            {
                node = node->left;
            }
            else if (key > node->data)
            {
                node = node->right;
            }
            else
            {
                return node;
            }
        }
        return nullptr;
    }
};

int main()
{
    AVLTree avl;
    string command;
    int key;

    while (true)
    {
        cin >> command;

        if (command == "exit")
        {
            break;
        }
        else if (command == "insert")
        {
            cin >> key;
            avl.insertion(key);
        }
        else if (command == "delete")
        {
            cin >> key;
            avl.deletion(key);
        }
        else
        {
            cout << "Unknown command." << endl;
        }
    }

    return 0;
}
