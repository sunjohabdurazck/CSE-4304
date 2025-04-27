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

void insert(const string &str) {
    Node *current = root;
    for (char ch : str) {
        int index = ch - 'a';
        if (current->next[index] == nullptr)
            current->next[index] = new Node();
        current = current->next[index];
    }
    current->endmark = true;
}

bool canSegment(const string &s) {
    int n = s.size();
    bool dp[n + 1];
    fill(dp, dp + n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        Node *current = root;
        for (int j = i - 1; j >= 0; j--) {
            int index = s[j] - 'a';
            if (current->next[index] == nullptr)
                break;
            current = current->next[index];
            if (current->endmark && dp[j]) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

int main() {
    root = new Node();
    string word;

    while (true) {
        cin >> word;
        if (word == "-1")
            break;
        insert(word);
    }

    string s;
    cin >> s;

    if (canSegment(s))
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;

    return 0;
}

