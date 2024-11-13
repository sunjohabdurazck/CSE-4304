#include <iostream>

using namespace std;

class MinHeap {
private:
    int* heap;
    int capacity;
    int size;

    void heapify(int index) {
        int smallest = index;
        int leftChild = 2 * index ;
        int rightChild = 2 * index + 1;

        if (leftChild < size && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < size && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapify(smallest);
        }
    }

public:
    MinHeap(int cap) {
        capacity = cap;
        size = 0;
        heap = new int[capacity];
    }

    ~MinHeap() {
        delete[] heap;
    }

    void insert(int value) {
        if (size < capacity) {
            heap[size] = value;
            size++;
        }
    }

    void buildMinHeap() {
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    void printMinHeap() {
        cout << "Min Heap: ";
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    void heapSort() {
        buildMinHeap();
        printMinHeap();

        int sorted[100];
        int sortedIndex = 0;

        while (size > 0) {
            sorted[sortedIndex++] = heap[0];
            heap[0] = heap[size - 1];
            size--;
            heapify(0);
        }

        cout << "Sorted: ";
        for (int i = 0; i < sortedIndex; i++) {
            cout << sorted[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int value;
    MinHeap minHeap(100);

    while (true) {
        cin >> value;
        if (value == -1) {
            break;
        }
        minHeap.insert(value);
    }

    minHeap.heapSort();

    return 0;
}
