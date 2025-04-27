#include <iostream>
#include <string>

using namespace std;

struct Node {
    bool endmark;
    Node *next[26];
    Node() {
        endmark = false;
        for (int i = 0; i < 26; i++)
            next[i] = nullptr;
    }
};

Node *root;

void insert(string str) {
    Node *current = root;
    for (int i = 0; i < str.length(); i++) {
        int index = str[i] - 'a';
        if (current->next[index] == nullptr)
            current->next[index] = new Node();
        current = current->next[index];
    }
    current->endmark = true;
}

bool search(string str) {
    Node *current = root;
    for (int i = 0; i < str.length(); i++) {
        int index = str[i] - 'a';
        if (current->next[index] == nullptr)
            return false;
        current = current->next[index];
    }
    return current->endmark;
}

void display(Node *current, string str) {
    if (current->endmark)
        cout << str << endl;
    for (int i = 0; i < 26; i++) {
        if (current->next[i] != nullptr) {
            char ch = 'a' + i;
            display(current->next[i], str + ch);
        }
    }
}

int main() {
    root = new Node();
    string words;
  string check; while (true) {
        getline(cin, words);
        if (words.empty())
            break;
        insert(words);
    }

    display(root, "");

    while (true) {

        getline(cin, check);
        if (check.empty())
            break;
 cout << (search(check) ? "T" : "F") << endl;
    }

    return 0;
}

