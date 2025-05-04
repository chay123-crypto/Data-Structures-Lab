/*Implementation of a stack using an array*/
#include<iostream>
using namespace std;

class stack
{
    int arr[5];/*Array size is 5 - given*/
    int top;
    int size=5;

    public:
    /*Constructor*/
    stack()
    {
        top=-1;
    }
    /*Methods*/
    void push(int num);
    void pop();
    void peek();
};

int main()
{
    stack s;
    int choice;
    do 
    {
        cout<<"\nMenu:\n1.Push an element \n2.Pop an element\n3.Peek the stack\n4.Exit\nEnter your choice: ";
        cin>>choice;
        
        if(choice>4)
        {
            cout<<"Invalid choice"<<endl;
        }
        if(choice==1)
        {
            int num;
            cout<<"Enter number to push:";
            cin>>num;
            s.push(num);
        }
        if(choice==2)
        {
            s.pop();
        }
        if(choice==3)
        {
            s.peek();
        }
        if(choice==4)
        {
            cout<<"Exiting program...\n";
        }
    }while(choice!=4);
}
void stack::push(int num)
{
    if(top==size-1)
    {
        cout<<"Stack Underflow"<<endl;
    }
    if(top==4)
    {
        cout<<"Stack Overflow"<<endl;
    }
    top++;
    arr[top]=num;
    cout<<num<<"pushed into the stack"<<endl;
}
void stack::pop() 
{
    if (top == -1) 
    {
        cout << "Stack Underflow"<<endl;
    } 
    cout<<arr[top]<<"popped from the stack."<<endl;;
     top--;
}
void stack::peek()
{
    if (top == -1) 
    {
        cout <<"Stack is empty. Nothing to peek"<<endl;
    } 
    cout<<"Top element:"<< arr[top] << "\n";
}