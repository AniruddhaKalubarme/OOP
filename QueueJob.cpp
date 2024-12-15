#include<iostream>
using namespace std;

int rear = -1, front = -1;
const int size = 10;
int arr[size];

void addJob(int iNo)
{
    if(rear == -1)
    {
        front = 0;
        rear = 0;
        arr[rear] = iNo;
    }
    else if(rear == size-1)
    {
        cout<<"Queue is FULL"<<endl;
    }
    else
    {
        rear++;
        arr[rear] = iNo;
    }
}

void DeleteJob()
{
    if(rear == -1)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    else if(front == rear)
    {
        cout<<"Deleted element: "<<arr[rear]<<endl;
        front = -1;
        rear  = -1;
    }
    else
    {
        cout<<"Deleted element: "<<arr[front]<<endl;
        front++;
    }
}

void Display()
{
    if(rear == -1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        int temp = front;
        while(temp != rear)
        {
            cout<<arr[temp]<<" ";
            temp++;
        }
        cout<<arr[temp]<<endl;
    }
}

int main()
{
    bool flag = true;
    cout<<"1) Enter JOB ";
    cout<<"\n2) Delete JOB ";
    cout<<"\n3) Display JOB ";
    cout<<"\n4) Exit JOB ";

    int Option, value;
    while(flag)
    {
        cout<<"\nEnter the Option: ";
        cin>>Option;

        switch(Option)
        {
            case 1:
                cout<<"\nEnter the value: ";
                cin>>value;
                addJob(value);
                break;
            case 2:
                DeleteJob();
                break;
            case 3:
                Display();
                break;
            case 4:
                flag = false;
        }
    }

    return 0;
}