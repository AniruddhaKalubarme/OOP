#include<iostream>
using namespace std;

typedef class node
{
    public:
    int data;
    node * next;
    node * prev;

    node(int iNo)
    {
        data = iNo;
        next = NULL;
        prev = NULL;
    }
}NODE, *PNODE;

PNODE AddBin(PNODE Tail1, PNODE Tail2)
{
    PNODE Head = NULL;
    int carry = 0;
    while(Tail1 != NULL || Tail2 != NULL || carry != 0)
    {
        // cout<<"INSIDE THE LOOP"<<endl;
        int bit1 = 0;
        if(Tail1!=NULL)
        {
            bit1 = Tail1->data;
            Tail1 = Tail1->prev;
        }

        int bit2 = 0;
        if(Tail2!=NULL)
        {
            bit2 = Tail2->data;
            Tail2 = Tail2->prev;
        }

        int iSum = bit1+bit2+carry;
        carry = iSum/2;
        iSum = iSum % 2;

        PNODE newn = new node(iSum);
        if(Head == NULL)
        {
            Head = newn;
        }
        else
        {
            newn -> next = Head;
            Head -> prev = newn;
            Head = newn;
        }
    }
    return Head;
}

void complement2s(PNODE Head, PNODE Tail)
{
    while(Tail != NULL && Tail->data == 0)
    {
        Tail = Tail->prev;
    }

    if(Tail == NULL)
    {
        while(Head != NULL)
        {
            cout<<0;
            Head= Head->next;
        }
    }
    while(Head!=Tail)
    {
        cout<<1-Head->data;
        Head = Head -> next;
    }
    while(Head!=NULL)
    {
        cout<<Head->data;
        Head = Head -> next;
    }
}

void complement1s(PNODE Head, PNODE Tail)
{
    while(Head != NULL)
    {
        cout<<1-Head->data;
        Head = Head->next;
    }
}

void InsertLast(PNODE &Head,PNODE &Tail, int iNo)
{
    PNODE newn = new node(iNo);

    if(Head == NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->prev = Tail;
        Tail->next = newn;
        Tail = newn;
    }
}

void Display(PNODE Head)
{
    while(Head!=NULL)
    {
        cout<<Head->data;
        Head = Head->next;
    }
}

int main()
{
    PNODE Head = NULL;
    PNODE Tail = NULL;
    InsertLast(Head,Tail, 1);
    InsertLast(Head,Tail, 0);
    InsertLast(Head,Tail, 0);
    InsertLast(Head,Tail, 1);

    PNODE Head2 = NULL;
    PNODE Tail2 = NULL;
    InsertLast(Head2,Tail2, 1);
    InsertLast(Head2,Tail2, 0);
    InsertLast(Head2,Tail2, 1);
    InsertLast(Head2,Tail2, 0);
    // InsertLast(Head,Tail, 1);
    Display(Head);
    cout<<endl;
    // Display(Head2);
    // cout<<endl;
    // cout<<endl;
    // complement2s(Head, Tail);

    complement1s(Head, Tail);
    cout<<endl;
    complement2s(Head, Tail);








    // PNODE ans = AddBin(Tail, Tail2);
    // Display(ans);
    return 0;
}