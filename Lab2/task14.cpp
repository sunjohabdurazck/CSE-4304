#include <iostream>
#include <unordered_map>
#include <queue>


using namespace std;
void circular_enqueue(int queue[], int item, int &rear, int maxQ, int &count) {
    if (count == maxQ)
        cout << "Overflow";
    else {
        queue[rear] = item;
        rear = (rear + 1) % maxQ;
        count++;
    }
}
void circular_dequeue(int queue[], int &front, int rear, int &count,int maxQ) {
    if (count == 0)
        cout << "Underflow";
    else {
        front = (front + 1) % maxQ;
        count--;
    }
}
int main() {
    int t, scenario = 1;

    while (cin >> t && t != 0) {
        unordered_map<int, int> personToCircle;
        queue<int> queueCircles;
        unordered_map<int, queue<int>> circleQueues;
        unordered_map<int, bool> inQueue;


        for (int i = 0; i < t; ++i) {
            int groupSize, person;
            cin >> groupSize;
            while (groupSize--) {
                cin >> person;
                personToCircle[person] = i;
            }
        }

        cout << "Scenario #" << scenario++ << endl;

        string command;
        while (cin >> command && command != "STOP") {
            if (command == "ENQUEUE") {
                int person;
                cin >> person;
                int circle = personToCircle[person];

                if (!inQueue[circle]) {
                    queueCircles.push(circle);
                    inQueue[circle] = true;
                }

                circleQueues[circle].push(person);
            }
            else if (command == "DEQUEUE") {

                int frontCircle = queueCircles.front();
                cout << circleQueues[frontCircle].front() << endl;
                circleQueues[frontCircle].pop();

                if (circleQueues[frontCircle].empty()) {
                    queueCircles.pop();
                    inQueue[frontCircle] = false;
                }
            }
        }

        cout << endl;
    }

    return 0;
}

