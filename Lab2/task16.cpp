#include <iostream>
using namespace std;

void circular_enqueue(int queue[], int item, int &rear, int &front, int maxQ, int &count)
{
    if (count == maxQ)
    {
        cout << "Overflow" << endl;
    }
    else
    {
        queue[rear] = item;
        rear = (rear + 1) % maxQ;
        count++;
    }
}

void circular_dequeue(int queue[], int &front, int &rear, int &count, int maxQ)
{
    if (count == 0)
    {
        cout << "Underflow" << endl;
    }
    else
    {
        front = (front + 1) % maxQ;
        count--;
    }
}

bool isEmpty(int count)
{
    return (count == 0);
}

bool isFull(int count, int maxQ)
{
    return (count == maxQ);
}

int size(int count)
{
    return count;
}

void printQueue(int queue[], int front, int rear, int count)
{
    if (isEmpty(count))
    {
        cout << "Queue Elements: " << endl;
        return;
    }

    cout << "Queue Elements: ";
    for (int i = 0; i < count; ++i)
    {
        cout << queue[(front + i) % 100] << " ";
    }
    cout << endl;
}

int main()
{
    int maxQ;
    int queue[100];
    int front = 0;
    int rear = 0;
    int count = 0;
    char command;
    int item;


    cin >> maxQ;
    while (true)
    {
        cin >> command;
        if (command == '-') break;

        switch (command)
        {
        case 'E':
        {
            cin >> item;
            circular_enqueue(queue, item, rear, front, maxQ, count);
            break;
        }
        case 'D':
        {
            circular_dequeue(queue, front, rear, count, maxQ);
            break;
        }
        default:
        {
            cout << "Invalid command!" << endl;
            break;
        }
        }

        int currentSize = size(count);
        cout << "Current Size: " << currentSize << endl;
        if(isFull(count, maxQ))
           cout<<"Full: Yes"<< endl;
           else
        cout <<"Full: No"<<endl;
                    if((isEmpty(count)))
           cout<<"Empty: Yes"<< endl;
           else
        cout <<"Empty: No"<<endl;

        if (!isEmpty(count))
        {
            cout << "Front Element: " << queue[front] << endl;
            cout << "Front Index: " << front << endl;
            cout << "Rear Element: " << queue[(rear - 1 + maxQ) % maxQ] << endl;
            cout << "Rear Index: " << (rear - 1 + maxQ) % maxQ << endl;
        }
        else
        {
            cout << "Front Element: -" << endl;
            cout << "Rear Element: -" << endl;
        }

        printQueue(queue, front, rear, count);
    }

    return 0;
}
