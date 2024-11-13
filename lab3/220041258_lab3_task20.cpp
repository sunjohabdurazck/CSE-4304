#include <iostream>
#include <queue>

using namespace std;


int largestSum(int arr[], int n, int k) {
    int sums[10000];
    int sumIndex = 0;

    for (int i = 0; i < n; ++i) {
        int current_sum = 0;
        for (int j = i; j < n; ++j) {
            current_sum += arr[j];
            sums[sumIndex++] = current_sum;
        }
    }

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < sumIndex; ++i) {
        minHeap.push(sums[i]);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    return minHeap.top();
}

int main() {
    int N;
    cin >> N;
    int arr[100];

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        if (i < N - 1) cin.ignore();
    }

    int K;
    cin >> K;
    int result = largestSum(arr, N, K);
    cout << result << endl;

    return 0;
}
