#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
int arr[MAX_SIZE];
int front = 0;
int rear = -1;
int count = 0;

void push_front(int key)
{
    if (count == MAX_SIZE)
    {
        cout << "Overflow\n";
        return;
    }
    front = (front - 1 + MAX_SIZE) % MAX_SIZE;
    arr[front] = key;
    count++;
}

void push_back(int key)
{
    if (count == MAX_SIZE)
    {
        cout << "Overflow\n";
        return;
    }
    rear = (rear + 1) % MAX_SIZE;
    arr[rear] = key;
    count++;
}

int pop_front()
{
    if (count == 0)
    {
        cout << "Underflow\n";
        return -1;
    }
    int item = arr[front];
    front = (front + 1) % MAX_SIZE;
    count--;
    return item;
}

int pop_back()
{
    if (count == 0)
    {
        cout << "Underflow\n";
        return -1;
    }
    int item = arr[rear];
    rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
    count--;
    return item;
}

int size()
{
    return count;
}
bool isEmpty(int front,int rear)
{

    return(front==rear);
}
bool isFull(int front, int rear,  int maxQ) {
    return rear == maxQ;
}
void printQueue()
{
    if (count == 0)
    {
        cout << "Queue is empty." << endl;
        return;
    }

    for (int i = 0; i < count; i++)
    {
        cout << arr[(front + i) % MAX_SIZE] << " ";
    }
    cout << endl;
}

int main()
{
    int queue[100];
    int a = 100;
    string choice;
         int value;
         cin>>a;
 while (true)
    {
        cin >> choice;
while(choice!="-1"){

         if(choice=="PF"){
            cin >> value;
            push_front(value);
            printQueue();
         }
        else if(choice=="PB"){
            cin >> value;
            push_back(value);
            printQueue();
        }
        else if(choice=="DF"){
            value = pop_front();
            if (value != -1)
            {

            }
            printQueue();
        }
        else if(choice=="DB"){
            value = pop_back();
            if (value != -1)
            {

            }
            printQueue();
        }
        else if(choice=="S"){
            cout << size() << endl;

        }
        else if(choice=="F")
            cout << "Front Index : " << front << endl;

        else if(choice=="R")
            cout << "Rear Element : " << queue[rear - 1] << endl;
       else if(choice=="STAT"){
            if(isFull(front, rear,  a)){
                cout<<"Full";
            }
            else if(isEmpty(front, rear)){
                cout<<"Empty";
            }
            else
                cout<<"None";
       }
       else if(choice=="E")
            cout << "Exiting...\n";
            return 0;
        //else
           // cout << "Invalid choice. Please try again.\n";
        }

    }
    return 0;
}
