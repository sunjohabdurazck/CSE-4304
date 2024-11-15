#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int T, M, N;
    cin >> T >> M >> N;

    unordered_map<string, vector<string>> mazeMap;

    for (int i = 0; i < T; i++)
    {
        string name;
        cin >> name;

        string maze;
        for (int j = 0; j < M; j++)
        {
            string row;
            cin >> row;
            maze += row;
        }

        mazeMap[maze].push_back(name);
    }

    bool found = false;
    for (const auto &entry : mazeMap)
    {
        if (entry.second.size() >= 1)
        {
            found = true;
            for (const auto &student : entry.second)
            {
                cout << student << " ";
            }
            cout << endl;
        }
    }

    if (!found)
    {
        cout << "No identical submissions found." << endl;
    }

    return 0;
}




