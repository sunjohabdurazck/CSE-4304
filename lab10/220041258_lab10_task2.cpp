#include <iostream>
using namespace std;

const int N = 1000;
int parent[N], rankSet[N];

void printSet(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << parent[i] << "(" << rankSet[i] << ") ";
    }
    cout << endl;
}

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rankSet[i] = 0;
    }
}

int find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSet(int u, int v)
{
    int pu = find(u), pv = find(v);
    if (pu != pv)
    {
        if (rankSet[pu] > rankSet[pv])
            parent[pv] = pu;
        else if (rankSet[pu] < rankSet[pv])
            parent[pu] = pv;
        else
        {
            parent[pv] = pu;
            rankSet[pu]++;
        }
    }
}

void display(int n)
{
    printSet(n);
}

int main()
{
    int n, a;
    cin >> n;
    init(n);
    while (cin >> a)
    {
        if (a == 1)
        {
            printSet(n);
        }
        else if (a == 2)
        {
            int b;
            cin >> b;
            cout << find(b) << endl;
        }
        else if (a == 3)
        {
            int c, d;
            cin >> c >> d;
            unionSet(c, d);
            printSet(n);
        }
        else if (a == 4)
        {
            display(n);
        }
    }
    return 0;
}

