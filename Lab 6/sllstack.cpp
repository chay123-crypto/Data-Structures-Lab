/*Implementation of a stack using a singly linked list*/
#include<iostream>
using namespace std;

class stack
{
    struct node
    {
        int data;
        node *next;

        /*constructor for node*/
        node(int s)
        {
            data = s;
            next = nullptr;
        };
    }*head;
    
    public:
    /*constructor*/
    stack()
    {
        head=nullptr;
    }
    /*Methods*/
    void push(int val);
    void peek();
    void pop();
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
   node*newnode=new node(num);
   newnode->data=num;
   newnode->next=head;
   head=newnode;
   cout<<num<<" is pushed to stack"<<endl;
}
void stack::pop() 
{
    if(head==nullptr)
    {
        cout<<"No elements in the stack"<<endl;
        return;
    }
    cout<<head->data<<" is removed"<<endl;
    node*temp=head;
    head=head->next;
    delete temp;
}
void stack::peek()
{
    if(head==nullptr)
    {
        cout<<"No elements in the stack"<<endl;
        return;
    }
    cout<<head->data<<" is the top element"<<endl;
}
