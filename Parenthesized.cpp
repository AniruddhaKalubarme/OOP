#include<iostream>
using namespace std;

typedef class node
{
    public:
    char data;
    node *next;
    node(int iNo)
    {
        data = iNo;
        next = NULL;
    }
}NODE , *PNODE;

void push(PNODE &Head, char ch)
{

    PNODE newn = new node(ch);
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

void pop(PNODE &Head)
{
    
    if(Head == NULL)
    {
        cout<<"Stack is empty cant pop"<<endl;
    }
    else
    {
        Head = Head -> next;
    }
}

char Top(PNODE Head)
{
    if(Head == NULL)
    {
        return 'z';
    }
    else
    {
        return Head->data;
    }
}

bool IsWellPare(PNODE &Head, string str)
{
    for(char i:str)
    {
        if(i == '(' || i == '{' || i == '[')
        {
            push(Head, i);
        }
        else if(i == ')' && Top(Head) == '(' || i == '}' && Top(Head) == '{'|| i == ']' && Top(Head) == '[')
        {
            pop(Head);
        }
        else if(i == ')' && Top(Head) != '(' || i == '}' && Top(Head) != '{'|| i == ']' && Top(Head) != '[')
        {
            return false;
        }
    }

    if(Head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    PNODE Head = NULL;
    string str = "Ani{rd(dfak)affda{}})";
    if(IsWellPare(Head, str))
    {
        cout<<"Well Parenthesized"<<endl;
    }
    else
    {
        cout<<"Not a valid expression"<<endl;
    }
    return 0;
}