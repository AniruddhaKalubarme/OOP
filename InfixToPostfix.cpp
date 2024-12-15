#include<iostream>
#include<stack>
#include<cctype>
#include<math.h>

using namespace std;

int precednece(char op)
{
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

int applyoperator(int a,int b,char op)
{
    switch(op)
    {
        case '+': return a+b;
        case '*': return a*b;
        case '/': return a/b;
        case '-': return a-b;
        default:
        return 0;
    }
}

string infixtopostfix(string infix)
{
    stack<char>s;
    string postfix = "";

    for(char ch : infix)
    {
        if(isdigit(ch))
        {
            postfix = postfix+ch;
        }
        else if(ch == '(')
        {
            s.push(ch);
        }
        else if( ch == ')')
        {
            while(!s.empty() && s.top() != '(')
            {
                postfix = postfix+s.top();
                s.pop();
            }
            s.pop();
        }
        else if(ch =='+' || ch == '*' || ch == '/' || ch == '-')
        {
            while(!s.empty() && precednece(s.top())>=precednece(ch))
            {
                postfix = postfix+s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while(!s.empty())
    {
        postfix = postfix+s.top();
        s.pop();
    }

    return postfix;
}

int evalutaion(string postfix)
{
    stack<int>s;
    for(char ch : postfix)
    {
        if(isdigit(ch))
        {
            s.push(ch-'0');
        }
        else if(ch =='+' || ch == '*' || ch == '/' || ch == '-')
        {
            int op2 = s.top();s.pop();
            int op1 = s.top();s.pop();

            int result = applyoperator(op1,op2,ch);
            s.push(result);
        }
    }

    return s.top();
}

int main()
{
    string expression;
    cout<<"Enter the expression:-";
    cin>>expression;

    string postfix = infixtopostfix(expression);
    cout<<"The conversion of the string from infix to postfix is:-"<<postfix<<endl;

    int result = evalutaion(postfix);
    cout<<"The evaluation of the expression is:-"<<result<<endl;
}