#include <iostream>
#include <vector>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

void dfs(vector<vector<char>>& grid, int x, int y)
{
    int m = grid.size(), n = grid[0].size();

    grid[x][y] = '0';

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1')
        {
            dfs(grid, nx, ny);
        }
    }
}

int countIslands(vector<vector<char>>& grid)
{
    int m = grid.size(), n = grid[0].size();
    int islandCount = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
            {
                islandCount++;
                dfs(grid, i, j);
            }
        }
    }
    return islandCount;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));

    for (int i = 0; i < m; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++)
        {
            grid[i][j] = row[j];
        }
    }

     cout << countIslands(grid) << endl;

    return 0;
}




