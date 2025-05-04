/*Program to implement queue using a singly linket list*/
#include<iostream>
using namespace std;

class Queuesll
{
    struct node
    {
        int data;
        node*next;

        /*Constructor for node*/
        node(int s)
        {
            data=s;
            next=nullptr;
        }

    }*front,*rear;
    public:
    Queuesll()
    {
        rear=front=nullptr;
    }
    /*Methods*/
    void enqueue(int val);
    void dequeue();
    int peek();
};
int main()
{
    Queuesll q;
    int choice;

    do
   {
    cout<<"//MENU//"<<endl;
    cout<<"1.Enqueue an element"<<endl;
    cout<<"2.Dequeue the queue."<<endl;
    cout<<"3.Peek out the queue"<<endl;
    cout<<"4.Exit the program"<<endl;
    cout<<"Enter your choice:";
    cin>>choice;
   
   if(choice>4)
   {
    cout<<"Incorrect choice is entered"<<endl;
   }
   if(choice==1)
   {
    int val;
    cout<<"Enter the integer value to be enqueued"<<endl;
    cin>>val;
    q.enqueue(val);
   }
   if(choice==4)
   {
    cout<<"Exiting the program..."<<endl;
   }
   if(choice==2)
   {
    q.dequeue();
   }
   if(choice==3)
   {
    int peeked=q.peek();
    cout<<"The peeked value is "<<peeked<<endl;
   }
  } while(choice!=4);
}
/*Member function definitions*/
void Queuesll::enqueue(int val)
{
    node*newnode= new node(val);
    newnode->next=nullptr;

    if(front==nullptr && rear==nullptr)
    {
        front=rear=newnode;
    }
    rear->next=newnode;
    rear=newnode;

    cout<<"The element is enqueued successfully"<<endl;
}
int Queuesll::peek()
{
    if(front==nullptr && rear==nullptr)
    {
        cout<<"No element in queue"<<endl;
        return -1;
    }
    int value=front->data;
    return value;
}
void Queuesll::dequeue()
{
    if(front==nullptr && rear==nullptr)
    {
        cout<<"No element in queue"<<endl;
        return;
    }
    int val=front->data;
    node*temp=front;
    front=front->next;
    delete temp;
    
    cout<<"The element "<<val<<" is dequeued from the queue successfully"<<endl;
}

