#include <iostream>

using namespace std;

void enqueue(int queue[], int item, int &rear, int maxQ)
{
    if(rear == maxQ+1)
        cout << "Overflow" << endl;
    else
    {
        queue[rear] = item;
        rear++;
    }
}

int fronts(int queue[], int front)
{
    return queue[front];
}

int size(int front, int rear)
{
    return (rear - front);
}

void dequeue(int queue[], int &front, int rear)
{
    if(front == rear)
        cout << "Underflow" << endl;
    else
    {
        front++;
    }
}

bool isEmpty(int front, int rear)
{
    return (front == rear);
}

bool isFull(int front, int rear, int maxQ)
{
    return ((rear+1)%maxQ==front);
}

void printQueue(int queue[], int front, int rear)
{
    if (front == rear)
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        cout << "Queue elements: ";
        for (int i = front; i < rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int a = 100;
    int queue[100];
    int front = 0;
    int rear = 0;
    int arr[100];
    int i = 0;

 cin>>a;
    while (true)
    {
        cin >> arr[i];
        if (arr[i] == -1) break;
        i++;
    }

    i = 0;
    while (arr[i] != -1)
    {
        switch (arr[i])
        {
        case 1:
        {
            enqueue(queue, arr[i + 1], rear, a);
            printQueue(queue, front, rear);
            i++;
            break;
        }
        case 2:
        {
            dequeue(queue, front, rear);
            break;
        }
        case 3:
        {
            if (isEmpty(front, rear))
            {
                cout << "isEmpty: True" << endl;
            }
            else
            {
                cout << "isEmpty: False" << endl;
            }
            break;
        }
        case 4:
        {
            if (isFull(front, rear,  a))
            {
                cout << "isFull: True" << endl;
            }
            else
            {
                cout << "isFull: False" << endl;
            }
            break;
        }
        case 5:
        {
            int s = size(front, rear);
            if (s > 5)
            {
                s = 5;
            }
            cout <<"Size: "<< s << endl;
            break;
        }
        case 6:
        {
            int w = fronts(queue, front);
            cout << "Front: " << w << endl;
            break;
        }
        }
        i++;
    }

    return 0;
}
