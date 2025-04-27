#include <iostream>
#include <vector>
using namespace std;

const int N = 1000;
int parent[N], rankSet[N];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rankSet[i] = 0;
    }
}

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

bool unionSet(int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu == pv) return false;
    if (rankSet[pu] > rankSet[pv]) parent[pv] = pu;
    else if (rankSet[pu] < rankSet[pv]) parent[pu] = pv;
    else {
        parent[pv] = pu;
        rankSet[pu]++;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    init(n);

    vector<pair<int, int>> edges, extraEdges;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        if (!unionSet(u, v)) {
            extraEdges.push_back({u, v});
        } else {
            edges.push_back({u, v});
        }
    }

    vector<pair<int, int>> newEdges;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (find(i) != find(j)) {
                newEdges.push_back({i, j});
                unionSet(i, j);
            }
        }
    }

    cout << extraEdges.size() << endl;
    for (int i = 0; i < extraEdges.size(); i++) {
        cout << extraEdges[i].first << " " << extraEdges[i].second << "   "
             << newEdges[i].first << " " << newEdges[i].second << endl;
    }

    return 0;
}
