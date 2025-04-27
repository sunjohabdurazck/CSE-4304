#include <iostream>
#include <vector>
using namespace std;

const int N = 100000;
int parent[N], rankSet[N], sizeSet[N];
int components, maxSize;

void init(int n) {
    components = n;
    maxSize = 1;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rankSet[i] = 0;
        sizeSet[i] = 1;
    }
}

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSet(int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu != pv) {
        if (rankSet[pu] > rankSet[pv]) {
            parent[pv] = pu;
            sizeSet[pu] += sizeSet[pv];
            maxSize = max(maxSize, sizeSet[pu]);
        } else if (rankSet[pu] < rankSet[pv]) {
            parent[pu] = pv;
            sizeSet[pv] += sizeSet[pu];
            maxSize = max(maxSize, sizeSet[pv]);
        } else {
            parent[pv] = pu;
            sizeSet[pu] += sizeSet[pv];
            maxSize = max(maxSize, sizeSet[pu]);
            rankSet[pu]++;
        }
        components--;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    init(n);

    while (m--) {
        int a, b;
        cin >> a >> b;
        unionSet(a, b);
        cout << components << " " << maxSize << endl;
    }
    return 0;
}
