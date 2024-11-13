#include <iostream>

using namespace std;


void maxHeapify(int heap[], int size, int i) {
    int largest = i;
    int leftChild = 2 * i+1 ;
    int rightChild = 2 * i + 2;

    if (leftChild < size && heap[leftChild] > heap[largest]) {
        largest = leftChild;
    }

    if (rightChild < size && heap[rightChild] > heap[largest]) {
        largest = rightChild;
    }

    if (largest != i) {
        swap(heap[i], heap[largest]);
        maxHeapify(heap, size, largest);
    }
}

void buildMaxHeap(int heap[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(heap, size, i);
    }
}

int Heap_Maximum(int heap[], int size) {
    return heap[0];
}


int Heap_extract_max(int heap[], int &size) {
    if (size < 1) {
        cout << "Heap underflow" << endl;
        return -1;
    }
    int max = heap[0];
    heap[0] = heap[size - 1];
    size--;
    maxHeapify(heap, size, 0);
    return max;
}

void Max_heap_insert(int value, int heap[], int &size) {
    if (size >= 100) {
        cout << "Heap overflow" << endl;
        return;
    }
    heap[size] = value;
    size++;

    for (int i = size - 1; i > 0 && heap[i] > heap[(i - 1) / 2]; i = (i - 1) / 2) {
        swap(heap[i], heap[(i - 1) / 2]);
    }
}

void Heap_decrease_key(int heap[], int i, int k, int size) {
    heap[i] -= k;
    maxHeapify(heap, size, i);
}

void Heap_increase_key(int heap[], int i, int k, int size) {
    heap[i] += k;
    for (; i > 0 && heap[i] > heap[(i - 1) / 2]; i = (i - 1) / 2) {
        swap(heap[i], heap[(i - 1) / 2]);
    }
}

void printHeap(int heap[], int size) {
    cout << "Heap: ";
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    int heap[100];
    int size = 0;
    int value;
    while (true) {
        cin >> value;
        if (value == -1) {
            break;
        }
        heap[size++] = value;
    }

    buildMaxHeap(heap, size);
    printHeap(heap, size);

    while (true) {
        int input;
        cin >> input;

        switch (input) {
            case 1: {
                cout <<Heap_Maximum(heap, size) << endl;
                break;
            }
            case 2: {
                int maxValue = Heap_extract_max(heap, size);
                if (maxValue != -1) {
                    cout << maxValue << endl;
                }
                break;
            }
            case 3: {
                cin >> value;
                Max_heap_insert(value, heap, size);
                break;
            }
            case 4: {
                int index, decreaseBy;
                cin >> index >> decreaseBy;
                Heap_decrease_key(heap, index, decreaseBy, size);
                break;
            }
            case 5: {
                int index, increaseBy;
                cin >> index >> increaseBy;
                Heap_increase_key(heap, index, increaseBy, size);
                break;
            }

                cout << "Invalid command!" << endl;
                break;
        }

        printHeap(heap, size);
    }

    return 0;
}
