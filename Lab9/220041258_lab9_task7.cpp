#include <iostream>
#include <string>
using namespace std;

struct Node {
    bool endmark;
    Node *next[52];
    Node() {
        endmark = false;
        for (int i = 0; i < 52; i++)
            next[i] = nullptr;
    }
};

Node *root;

int charToIndex(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    }
    else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 26;
    }
    return -1;
}

void insert(const string &str) {
    Node *current = root;
    for (char ch : str) {
        int index = charToIndex(ch);
        if (current->next[index] == nullptr)
            current->next[index] = new Node();
        current = current->next[index];
    }
    current->endmark = true;
}

bool searchAbbreviation(Node *current, const string &abbr, int index) {
    if (index == abbr.size())
        return true;

    int idx = charToIndex(abbr[index]);
    if (idx == -1 || !current->next[idx])
        return false;

    return searchAbbreviation(current->next[idx], abbr, index + 1);
}

bool matchesAbbreviation(const string &abbr) {
    return searchAbbreviation(root, abbr, 0);
}

int main() {
    root = new Node();
    string words;
    while (1) {
        cin >> words;

        if (words == "-1")
           break;
           else
            insert(words);

    }
    string option;
    cin >> option;
    cout << (matchesAbbreviation(option) ? "T" : "F") << endl;

    return 0;
}
