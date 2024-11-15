#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

pair<int, string> maxPointsOnLine(vector<vector<int>>& points)
{
    int n = points.size();
    if (n < 2) return {n, ""};

    int maxPoints = 0;
    string lineEquation = "";

    for (int i = 0; i < n; i++)
    {
        unordered_map<string, int> slopeMap;
        int duplicate = 1;
        int localMax = 0;

        for (int j = i + 1; j < n; j++)
        {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];

            if (dx == 0 && dy == 0)
            {
                duplicate++;
                continue;
            }

            int gcdVal = gcd(dx, dy);
            dx /= gcdVal;
            dy /= gcdVal;

            string slope = to_string(dy) + "/" + to_string(dx);
            slopeMap[slope]++;
            localMax = max(localMax, slopeMap[slope]);

            localMax += duplicate;
            if (localMax > maxPoints)
            {
                maxPoints = localMax;
                int intercept = points[i][1] - (dy * points[i][0] / dx);
                lineEquation = "y = " + to_string(dy) + "/" + to_string(dx) + "x + " + to_string(intercept);
            }
        }
    }
    return {maxPoints, lineEquation};
}

int main()
{
    int option;
    cin >> option;

    vector<vector<int>> points(option, vector<int>(2));

    for (int i = 0; i < option; i++)
    {
        cin >> points[i][0] >> points[i][1];
    }

    auto result = maxPointsOnLine(points);

    cout << result.second << endl;
    cout << result.first << endl;
    return 0;
}

