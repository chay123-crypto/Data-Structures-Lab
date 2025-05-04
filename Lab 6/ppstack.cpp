#include<iostream>
#include<cctype>
#include"Stack.h"
using namespace std;

string infix;
string postfix;

void getInfix()
{
    cout<<"Enter a valid infix expression: ";
    cin>>infix;
}

int precedence(char op)
{
    if(op=='+'||op=='-') 
    {
        return 1;
    }
    if(op=='*'||op=='/') 
    {
        return 2;
    }
    return 0;
}

void convert()
{
    stack s;
    postfix="";
    
    for(char ch:infix)
    {
        if(isdigit(ch)||isalpha(ch))
        {
            postfix+=ch;
        }
        else if(ch=='(')
        {
            s.push(ch);
        }
        else if(ch==')')
        {
            while(!s.isempty()&&s.peek()!='(')
            {
                postfix+=s.pop();
            }
            s.pop();
        }
        else
        {
            while(!s.isempty()&&precedence(s.peek())>=precedence(ch))
            {
                postfix+=s.pop();
            }
            s.push(ch);
        }
    }

    while(!s.isempty())
    {
        postfix+=s.pop();
    }

    cout<<"Postfix Expression: "<<postfix<<endl;
}

int evaluatePostfix()
{
    stack s;
    
    for(char ch:postfix)
    {
        if(isdigit(ch))
        {
            s.push(ch-'0');
        }
        else
        {
            int num2=s.pop();
            int num1=s.pop();
            
            if(ch=='+') s.push(num1+num2);
            else if(ch=='-') s.push(num1-num2);
            else if(ch=='*') s.push(num1*num2);
            else if(ch=='/')
            {
                if(num2==0)
                {
                    cout<<"Error: Division by zero!"<<endl;
                    return 0;
                }
                s.push(num1/num2);
            }
        }
    }
    
    return s.pop();
}

int main()
{
    int choice;
    do
    {
        cout<<"\nMenu:\n1. Get Infix\n2. Convert Infix\n3. Evaluate Postfix\n4. Exit\nEnter your choice: ";
        cin>>choice;

        if(choice==1)
        {
            getInfix();
            cout<<"Successfully entered"<<endl;
        }
        else if(choice==2)
        {
            if(infix.empty())
            {
                cout<<"No infix expression entered!"<<endl;
            }
            else
            {
                convert();
            }
        }
        else if(choice==3)
        {
            if(postfix.empty())
            {
                cout<<"No postfix expression to evaluate!"<<endl;
            }
            else
            {
                cout<<"Postfix Evaluation Result: "<<evaluatePostfix()<<endl;
            }
        }
        else if(choice==4)
        {
            cout<<"Exiting program..."<<endl;
        }
        else
        {
            cout<<"Invalid choice!"<<endl;
        }
    }while(choice!=4);
}