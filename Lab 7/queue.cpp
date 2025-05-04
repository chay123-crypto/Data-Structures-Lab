/*Program to implement queue using array*/
#include<iostream>
using namespace std;

class Queue
{
    int arr[5];
    int size=5;
    int front;
    int rear;

    /*Constructor for thr class*/
    public:
    Queue()
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
    Queue q;
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
/*Member function definitions*/
void Queue::enqueue(int val)
{
    if(rear==size-1)
    {
        cout<<"Queue is full"<<endl;
        return;
    }
    if((front==-1 && rear==-1 )|| front>rear)
    {
        front=0;
    }
    rear++;
    arr[rear]=val;
    cout<<"The given input has successfully been enqueued"<<endl;
}
void Queue::dequeue()
{
    if(front==-1||front>rear)
    {
        cout<<"The Queue is empty"<<endl;
        return;
    }
    int value=arr[front];
    front++;
    cout<<"The element "<<value<<" queue has been dequeued"<<endl;
    
    if(front>rear)
    {
        front=rear=-1;
    }
}

int Queue::peek()
{
    if(front==-1||front>rear)
    {
        cout<<"The Queue is empty"<<endl;
        return -1;
    }
    int data=arr[front];
    return data;
}
