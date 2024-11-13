#include <iostream>

using namespace std;



const int MAX_SIZE = 5;
int arr[MAX_SIZE];
int front = 0;
int rear = -1;
int count = 0;

void push(int key)
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



int pop()
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

bool isEmpty(int front,int rear)
{

    return(front==rear);
}
bool isFull(int front, int rear,  int maxQ) {
    return rear == maxQ;
}
int size()
{
    return count;
}
//int top(){
//return
//}
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
    int i;

        cin>>a;
         int value;

    while (true)
    {
        cin >> choice;
while(choice!="-1"){
if(choice=="push"){
            cin >> value;
                      if (isFull(front, rear,  a))
            {
                cout << "Overflow!!" << endl;
            }

            else
                push(value);
            printQueue();
}

        else if(choice=="pop"){
            value = pop();
            if (value != -1)
            {

            }
            printQueue();
        }
        else
            cout<<"Invalid";
            break;

    }
}
return 0;
}
