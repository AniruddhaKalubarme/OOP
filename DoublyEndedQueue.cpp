#include<iostream>
using namespace std;
const int size = 10;
int front = -1, rear = -1;
int arr[size];

void enqueueFront(int iNo)
{
    if((rear+1)%size == front)
    {
        cout<<"Cant insert from front side"<<endl;
    }
    else if(front == -1 && rear == -1)
    {
        front = 0, rear = 0;
        arr[front] = iNo;
    }
    else if(front == 0)
    {
        front = size-1;
        arr[front] = iNo;
    }
    else
    {
        front--;
        arr[front] = iNo;
    }
}

void enqueueRear(int iNo)
{
    if((rear+1)%size == front)
    {
        cout<<"Cant insert from back side"<<endl;
    }
    else if(front == -1 && rear == -1)
    {
        front = 0, rear = 0;
        arr[front] = iNo;
    }
    else if(rear == size-1)
    {
        rear = 0;
        arr[rear] = iNo;
    }
    else
    {
        rear++;
        arr[rear] = iNo;
    }
}

void dequeueRear()
{
    if(rear == -1)
    {
        cout<<"Deque is empty"<<endl;
    }
    else if(rear == front)
    {
        cout<<"Element Deleted: "<<arr[rear]<<endl;
        rear = -1;
        front = -1;
    }
    else if(rear == 0)
    {
        cout<<"Element Deleted: "<<arr[rear]<<endl;
        rear = size-1;
    }
    else
    {
        cout<<"Element Deleted: "<<arr[rear]<<endl;
        rear--;
    }
}

void dequeueFront()
{
    if(front == -1)
    {
        cout<<"Deque is empty"<<endl;
    }
    else if(rear == front )
    {
        cout<<"Element deleted: "<<arr[front]<<endl;
        front = -1;
        rear = -1;
    }
    else if(front == size-1)
    {
        cout<<"Element deleted: "<<arr[front]<<endl;
        front = 0;
    }
    else
    {
        cout<<"Element deleted: "<<arr[front]<<endl;
        front++;
    }
}

void Display()
{
    if(front == -1)
    {
        cout<<"Empty"<<endl;
    }
    else
    {
        int temp = front;
        while((rear+1)%size != temp)
        {
            cout<<arr[temp]<<" ";
            temp = (temp+1) % size;
        }
        cout<<endl;
    }
}

int main()
{
    enqueueFront(5);
    enqueueFront(4);
    enqueueFront(3);
    enqueueRear(6);
    enqueueRear(7);
    enqueueRear(8);
    Display();
    dequeueFront();
    dequeueFront();
    dequeueRear();
    dequeueRear();
    Display();
    return 0;
}