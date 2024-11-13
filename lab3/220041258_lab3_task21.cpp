#include <iostream>
#include <cstring>

using namespace std;


struct Student {
    string name;
    string department;
    double cgpa;
};


class MaxHeap {
private:
    Student* heap;
    int capacity;
    int size;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void swap(Student& a, Student& b) {
        Student temp = a;
        a = b;
        b = temp;
    }

public:
    MaxHeap(int capacity) {
        this->capacity = capacity;
        heap = new Student[capacity];
        size = 0;
    }

    ~MaxHeap() {
        delete[] heap;
    }

    void insert(Student student) {
        if (size < capacity) {
            heap[size] = student;
            size++;
            heapifyUp(size - 1);
        }
    }

    Student extractMax() {
        if (size == 0) {
            throw runtime_error("Heap is empty");
        }
        Student maxStudent = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return maxStudent;
    }

    int getSize() {
        return size;
    }

private:
    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)].cgpa < heap[index].cgpa) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int leftIndex = left(index);
        int rightIndex = right(index);

        if (leftIndex < size && heap[leftIndex].cgpa > heap[largest].cgpa) {
            largest = leftIndex;
        }
        if (rightIndex < size && heap[rightIndex].cgpa > heap[largest].cgpa) {
            largest = rightIndex;
        }
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }
};

int main() {
    int N;
    cin >> N;
    cin.ignore();

    MaxHeap maxHeap(N);
    for (int i = 0; i < N; i++) {
        Student student;
        cin >> student.name >> student.department >> student.cgpa;
        maxHeap.insert(student);
    }


    for (int rank = 1; rank <= N; rank++) {
        Student student = maxHeap.extractMax();
        if (rank == 1) {
            cout << student.name << "Shiny Gold Medal\n";
        } else if (rank == 2) {
            cout << student.name << "First to lose\n";
        } else if (rank == 3) {
            cout << student.name << "Best among the leftovers\n";
        } else {
            cout << student.name << "Thank you for participating (" << (rank - 3) << ")\n";
        }
    }

    return 0;
}
