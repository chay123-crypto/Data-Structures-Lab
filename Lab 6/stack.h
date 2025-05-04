#include<iostream>
using namespace std;
class stack
{
    struct node
    {
        char data;
        node* next;
        node(char s)
        {
            data=s;
            next=nullptr;
        }
    }*head;
public:
    stack()
    {
        head=nullptr;
    }
    ~stack()
    {
        while(!isempty())
        {
            pop();
        }
    }
    void push(char val);
    char pop();
    char peek();
    bool isempty();
};
void stack::push(char val)
{
    node* newnode=new node(val);
    newnode->next=head;
    head=newnode;
}
char stack::pop()
{
    if(head==nullptr)
    {
        cout<<"No elements in the stack"<<endl;
        return '\0';
    }
    char popped=head->data;
    node* temp=head;
    head=head->next;
    delete temp;
    return popped;
}
char stack::peek()
{
    if(head==nullptr)
    {
        cout<<"No elements in the stack"<<endl;
        return '\0';
    }
    return head->data;
}
bool stack::isempty()
{
    return head==nullptr;
}
