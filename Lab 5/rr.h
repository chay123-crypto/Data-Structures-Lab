/*Implementing a round robin scheduling algorithm for CPU usage time slot - header file*/
#include<iostream>
using namespace std;

class Queue 
{
    struct node 
    {
        int time;
        node*next;
        /*Node constructor*/
        node(int t) 
        {
            time=t;
            next=nullptr;
        }
    };
    node*head;
    node*tail;
    int slicedtime;

    /*Constructor*/
    public:
    Queue(int s) {
        head=nullptr;
        tail=nullptr;
        slicedtime=s;
    }

    void insertProcess(int time) 
    {
        node*newnode=new node(time);
        if(head==nullptr) 
        {
            head=tail=newnode;
            tail->next=head;
        } 
        else 
        {
            tail->next=newnode;
            tail=newnode;
            tail->next=head;
        }
    }
    void execute() 
    {
        if(head==nullptr) 
        {
            cout<<"No processes in the queue"<<endl;
            return;
        }
        cout<<"Executing process with time:"<<head->time<<endl;
        head->time-=slicedtime;

        if(head->time<=0) 
        {
            cout<<"Process has been completed"<<endl;

            if(head==tail) 
            {
                delete head;
                head=tail=nullptr;
            } 
            else 
            {
                node*temp=head;
                tail->next=head->next;
                head=head->next;
                delete temp;
            }
        } 
        else 
        {
            cout<<"Process remaining time:"<<head->time<<endl;
            tail=head;
            head=head->next;
        }
    }
    void displayqueue() {
        if(head==nullptr) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        node*temp=head;
        cout<<"Process Queue:";
        do {
            cout<<temp->time<<"->";
            temp=temp->next;
        } while(temp!=head);
        cout<<"(Back to start)"<<endl;
    }
};
