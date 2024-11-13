#include <iostream>
#include <vector>
using namespace std;


void heapify(vector<int>& arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;


    if (left < n && arr[left] > arr[largest])
        largest = left;


    if (right < n && arr[right] > arr[largest])
        largest = right;


    if (largest != i)
    {
        swap(arr[i], arr[largest]);


        heapify(arr, n, largest);
    }
}


void build_max_heap(vector<int>& arr, int n)
{

    int startIdx = (n / 2) - 1;


    for (int i = startIdx; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}


void heap_sort(vector<int>& arr)
{
    int n = arr.size();


    build_max_heap(arr, n);


    cout << "Max Heap: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;


    for (int i = n - 1; i > 0; i--)
    {

        swap(arr[0], arr[i]);


        heapify(arr, i, 0);
    }


    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr;
    int num;


    while (true)
    {
        cin >> num;
        if (num == -1)
            break;
        arr.push_back(num);
    }

    if (!arr.empty())
    {
        heap_sort(arr);
    }

    return 0;
}
