#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adjecent;
    vector<int> distance;
    vector<int> predecessor;
    vector<string> color;
    vector<pair<int, int>> treeEdges;

public:
    Graph(int V)
    {
        this->V = V;
        adjecent.resize(V + 1);
        distance.resize(V + 1, -1);
        predecessor.resize(V + 1, -1);
        color.resize(V + 1, "WHITE");
    }

    void addEdge(int u, int v)
    {
        adjecent[u].push_back(v);
        adjecent[v].push_back(u);
    }

    void printAdjacencyList()
    {
        cout << "Adjacency list:\n";
        for (int i = 1; i <= V; i++)
        {
            cout << i << ": ";
            for (int neighbor : adjecent[i])
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void BFS(int s)
    {
        queue<int> q;
        color[s] = "GRAY";
        distance[s] = 0;
        q.push(s);
        cout << "\nBFS order: ";

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (int v : adjecent[u])
            {
                if (color[v] == "WHITE")
                {
                    color[v] = "GRAY";
                    distance[v] = distance[u] + 1;
                    predecessor[v] = u;
                    q.push(v);
                    treeEdges.push_back({u, v});
                }
            }
            color[u] = "BLACK";
        }
        cout << endl;
    }

    void printDistances()
    {
        cout << "\nDistance from source:\n";
        for (int i = 1; i <= V; i++)
        {
            cout << i << "(" << distance[i] << ") ";
        }
        cout << endl;
    }

    void printPaths(int s)
    {
        cout << "\nPaths from source:\n";
        for (int i = 1; i <= V; i++)
        {
            cout << i << ": ";
            printPathUtil(i);
            cout << endl;
        }
    }

    void printPathUtil(int v)
    {
        if (v == -1) return;
        if (predecessor[v] == -1)
        {
            cout << v;
        }
        else
        {
            printPathUtil(predecessor[v]);
            cout << "->" << v;
        }
    }

    void printTreeEdges()
    {
        cout << "\nEdges of BFS tree:\n";
        for (auto edge : treeEdges)
        {
            cout << edge.first << " " << edge.second << endl;
        }
    }
};

int main()
{
    int V, E, s;
    cin >> V >> E >> s;
    Graph g(V);

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.printAdjacencyList();
    g.BFS(s);
    g.printDistances();
    g.printPaths(s);
    g.printTreeEdges();

    return 0;
}
