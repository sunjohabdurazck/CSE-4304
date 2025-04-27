#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct Node
{
    unordered_map<char, Node*> next;
    bool endmark;
    int count;
    Node()
    {
        endmark = false;
        count = 0;
    }
};

Node *root;

void insert(string str)
{
    Node *current = root;
    for (char ch : str)
    {
        if (current->next.find(ch) == current->next.end())
            current->next[ch] = new Node();
        current = current->next[ch];
        current->count++;
    }
    current->endmark = true;
}

int longestCommonPrefix()
{
    Node *current = root;
    int length = 0;
    while (current && current->next.size() == 1)
    {
        auto it = current->next.begin();
        if (it->second->count > 1)
        {
            current = it->second;
            length++;
        }
        else
            break;
    }
    return length;
}

int main()
{
    int n1, n2, num;
    cin >> n1 >> n2;

    root = new Node();
    for (int i = 0; i < n1; i++)
    {
        cin >> num;
        insert(to_string(num));
    }

    for (int i = 0; i < n2; i++)
    {
        cin >> num;
        insert(to_string(num));
    }

    cout << longestCommonPrefix() << endl;

    return 0;
}

