#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

void bfs(vector<vector<int>>& map, vector<vector<bool>>& reachable, queue<pair<int, int>>& q)
{
    int m = map.size();
    int n = map[0].size();

    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n)
            {
                if (!reachable[nr][nc] && map[nr][nc] <= map[r][c])
                {
                    reachable[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
}

vector<vector<char>> findValidStartPositions(vector<vector<int>>& map)
{
    int m = map.size();
    int n = map[0].size();

    vector<vector<bool>> canReachGreen(m, vector<bool>(n, false));
    vector<vector<bool>> canReachRed(m, vector<bool>(n, false));
    queue<pair<int, int>> greenQueue, redQueue;

    for (int i = 0; i < m; i++)
    {
        canReachGreen[i][0] = true;
        greenQueue.push({i, 0});
        canReachRed[i][n - 1] = true;
        redQueue.push({i, n - 1});
    }
    for (int j = 0; j < n; j++)
    {
        canReachGreen[0][j] = true;
        greenQueue.push({0, j});
        canReachRed[m - 1][j] = true;
        redQueue.push({m - 1, j});
    }

    bfs(map, canReachGreen, greenQueue);
    bfs(map, canReachRed, redQueue);

    vector<vector<char>> result(m, vector<char>(n, 'X'));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (canReachGreen[i][j] && canReachRed[i][j])
            {
                result[i][j] = 'O';
            }
        }
    }

    return result;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> map(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    cout<<"\n";
    vector<vector<char>> output = findValidStartPositions(map);


    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
