#include<iostream>
using namespace std;

class circqueue
{
    int arr[5];
    int size=5;
    int front;
    int rear;

    /*Constructor for thr class*/
    public:
    circqueue()
    {
        front=rear=-1;
    }
    /*Methods of the class*/
    void enqueue(int val);
    void dequeue();
    int peek();
};
int main()
{
    circqueue q;
    int choice;

    do
   {
    cout<<"//MENU//"<<endl;
    cout<<"1.Enqueue an element"<<endl;
    cout<<"2.Deuqueue the queue."<<endl;
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
    cout<<"Exiting the program..........."<<endl;
   }
   if(choice==2)
   {
    q.dequeue();
   }
   if(choice==3)
   {
    int peeked=q.peek();
    cout<<"The peeked value is"<<peeked<<endl;
   }
  } while(choice!=4);
}
void circqueue::enqueue(int val)
{
    if((rear+1)%size==front)
    {
        cout<<"Queue is full"<<endl;
        return;
    }
    if((front==-1 && rear==-1 ))
    {
        front=0;
    }
    rear=(rear+1)%size;
    arr[rear]=val;
    cout<<"The given element is succesfully enqueued"<<endl;
}
void circqueue::dequeue()
{
    if(front==-1)
    {
        cout<<"The Queue is empty"<<endl;
        return;
    }
    int value=arr[front];
    front++;
    cout<<"The element "<<value<<" queue has been dequeued"<<endl;
    
    if(front==rear)
    {
        front=rear=-1;
    }
}

int circqueue::peek()
{
    if(front==-1)
    {
        cout<<"The Queue is empty"<<endl;
        return -1;
    }
    return arr[front];
}
    