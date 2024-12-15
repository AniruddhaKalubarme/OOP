#include<iostream>
using namespace std;

typedef class node
{
    public:
    string name;
    long long prn;
    node *next;
    static int iCnt;
    node(string str, long long iNo)
    {
        iCnt++;
        name = str;
        prn = iNo;
    }
    ~node()
    {
        iCnt--;
    }
}NODE, *PNODE;
int node::iCnt = 0;

void Presedent(PNODE &Head, string str, long long iNo)
{
    PNODE newn = new node(str, iNo);
    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
}

void Member(PNODE &Head, string str, long long iNo)
{
    PNODE newn = new node(str, iNo);
    if(Head == NULL || Head -> next == NULL)
    {
        cout<<"First add both the secretary and president"<<endl;
        return;
    }
    else
    {
        newn->next = Head->next;
        Head->next = newn;
    }
}

void secretery(PNODE &Head, string str, long long iNo)
{
    PNODE temp = Head;
    PNODE newn = new node(str, iNo);
    if(Head == NULL)
    {
        cout<<"Add presedent first"<<endl;
        return;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void Delete(PNODE &Head, long long iNo)
{
    PNODE temp = Head;

    if(temp->prn == iNo)
    {
        Head = Head -> next;
        delete temp;
    }
    while(temp->next->prn != iNo && temp!=NULL)
    {
        temp = temp->next;
    }
    if(temp == NULL)
    {
        cout<<"Member not found"<<endl;
        return;
    }
    PNODE del = temp->next;
    temp = temp->next->next;
    delete del;
}

void Count(PNODE Head)
{
    cout<<"Count is: "<<node::iCnt<<endl;
}

void Display(PNODE Head)
{
    while(Head != NULL)
    {
        cout<<"Name: "<<Head->name<<"\tPRN: "<<Head->prn<<endl;
        Head = Head -> next;
    }
}

int main()
{
    PNODE Head = NULL;
    Presedent(Head, "Aniruddha", 12345);
    secretery(Head, "Aniruddha", 12345);
    Member(Head, "Aniruddha", 12345);
    Member(Head, "Aniruddha", 12345);
    Display(Head);
    return 0;
}