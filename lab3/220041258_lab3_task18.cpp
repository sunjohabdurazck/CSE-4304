#include <iostream>
#include <queue>

using namespace std;

int lastStoneWeight(int stones[], int size) {
    priority_queue<int> maxHeap;

    for (int i = 0; i < size; i++) {
        maxHeap.push(stones[i]);
    }

    while (maxHeap.size() > 1) {
        int stone1 = maxHeap.top();
        maxHeap.pop();

        int stone2 = maxHeap.top();
        maxHeap.pop();

        if (stone1 != stone2) {
            maxHeap.push(stone1 - stone2);
        }
    }

    return maxHeap.empty() ? 0 : maxHeap.top();
}

int main() {
    const int MAX_SIZE = 100;
    int stones[MAX_SIZE];
    int size = 0;

    while (true) {
        int weight;
        cin >> weight;

        if (weight == -1) {
            break;
        }

        if (size < MAX_SIZE) {
            stones[size++] = weight;
        } else {
            cout << "Maximum stone limit reached." << endl;
        }
    }

    int lastWeight = lastStoneWeight(stones, size);
    cout<< lastWeight << endl;

    return 0;
}
