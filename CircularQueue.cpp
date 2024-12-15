#include <iostream>
using namespace std;

const int M = 10;
string arr[M];
int front = -1, rear = -1;

void enqueue(string order)
{
    if((rear+1)%M == front)
    {
        cout<<"Queue is full"<<endl;
        return;
    }
    else if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        arr[rear] = order;
    }
    else
    {
        rear = (rear + 1)%M;
        arr[rear] = order;
    }
}

void dequeue()
{
    if(rear == -1 && front == -1)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    else if(rear == front)
    {
        rear = -1;
        front = -1;
    }
    else
    {
        cout<<"Order is Completed: "<<arr[front]<<endl;
        front = (front + 1)%M;
    }
}

void Display()
{
    if(front == -1 && rear == -1)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    else
    {
        int temp = front;
        while(temp != rear)
        {
            cout<<arr[temp]<<" ";
            temp = (temp + 1)%M;
        }
        cout<<arr[rear]<<endl;
    }
}



int main()
{
    enqueue("Pizza");
    enqueue("Burger");
    enqueue("omlet");
    enqueue("Eggs fry");
    enqueue("boiled egg");
    enqueue("pizza");
    enqueue("Burger");
    enqueue("shreyash");
    enqueue("hajare");
    enqueue("eggs");
    enqueue("eggs");

    Display();

    dequeue();
    dequeue();
    Display();
    return 0;
}