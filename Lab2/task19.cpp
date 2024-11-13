#include <iostream>
#include <queue>

using namespace std;

int countStudentsUnableToEat(int N, int preferences[], int dishes[])
{
    queue<int> studentQueue;
    for (int i = 0; i < N; i++)
    {
        studentQueue.push(preferences[i]);
    }

    for (int i = 0; i < N; i++)
    {
        int dish = dishes[i];
        int length = studentQueue.size();

        for (int j = 0; j < length; j++)
        {
            int student = studentQueue.front();
            studentQueue.pop();

            if (student == dish)
            {
                break;
            }
            else
            {
                studentQueue.push(student);
            }
        }

        if (studentQueue.size() == length)
        {
            break;
        }
    }

    return studentQueue.size();
}

int main()
{
    int N;
    cin >> N;

    int preferences[N];
    for (int i = 0; i < N; i++)
    {
        cin >> preferences[i];
    }

    int dishes[N];
    for (int i = 0; i < N; i++)
    {
        cin >> dishes[i];
    }

    int result = countStudentsUnableToEat(N, preferences, dishes);
    cout << result << endl;
    return 0;
}
