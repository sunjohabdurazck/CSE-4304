#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Graph
{
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list
    vector<string> color; // Node colors: WHITE, GRAY, BLACK
    vector<int> discovery; // Discovery time
    vector<int> finish; // Finishing time
    vector<int> predecessor; // Predecessor
    int time; // Global time for timestamps

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V + 1);  // 1-based indexing
        color.resize(V + 1, "WHITE");
        discovery.resize(V + 1, -1);
        finish.resize(V + 1, -1);
        predecessor.resize(V + 1, -1);
        time = 0;
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v); // Directed edge
    }

    void printAdjacencyList()
    {
        cout << "Adjacency list:\n";
        for (int i = 1; i <= V; i++)
        {
            cout << i << ": ";
            for (int neighbor : adj[i])
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void DFS()
    {
        cout << "\nDFS order: ";
        for (int i = 1; i <= V; i++)
        {
            if (color[i] == "WHITE")
            {
                DFSVisit(i);
            }
        }
        cout << endl;
    }

    void DFSVisit(int u)
    {
        color[u] = "GRAY";
        discovery[u] = ++time;
        cout << u << " ";

        for (int v : adj[u])
        {
            if (color[v] == "WHITE")
            {
                predecessor[v] = u;
                DFSVisit(v);
            }
        }

        color[u] = "BLACK";
        finish[u] = ++time;
    }

    void printTimestamps()
    {
        cout << "\nTimestamps of Vertex (discovery/finishing):\n";
        for (int i = 1; i <= V; i++)
        {
            cout << i << "(" << discovery[i] << "/" << finish[i] << ") " << endl;
        }
    }

    void classifyEdges()
    {
        cout << "\nEdge classification:\n";
        for (int u = 1; u <= V; u++)
        {
            for (int v : adj[u])
            {
                classifyEdge(u, v);
            }
        }
    }

    void classifyEdge(int u, int v)
    {
        if (discovery[u] < discovery[v] && finish[v] < finish[u])
        {
            cout << u << " " << v << ": Tree Edge" << endl;
        }
        else if (discovery[u] < discovery[v] && finish[v] > finish[u])
        {
            cout << u << " " << v << ": Forward Edge" << endl;
        }
        else if (discovery[u] > discovery[v] && finish[v] > finish[u])
        {
            cout << u << " " << v << ": Back Edge" << endl;
        }
        else
        {
            cout << u << " " << v << ": Cross Edge" << endl;
        }
    }
};

int main()
{
    int V, E;
    cin >> V >> E;
    Graph g(V);

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.printAdjacencyList();
    g.DFS();
    g.printTimestamps();
    g.classifyEdges();

    return 0;
}

