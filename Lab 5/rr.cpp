/*Implementing a round robin scheduling algorithm for CPU usage time slot - main program*/
#include<iostream>
#include"rr.h"
using namespace std;

int main() 
{
    int timeslice;
    cout<<"Enter fixed time slice:";
    cin>>timeslice;

    Queue q(timeslice);
    int choice,time;

    do 
    {
        cout<<"\nMenu:\n1. Insert Process\n2. Execute\n3. Display Queue\n4. Exit\nEnter your choice: ";
        cin>>choice;
        
        if(choice>9)
        {
            cout<<"Invalid choice"<<endl;
        }
        if(choice==1)
        {
            cout<<"Enter process execution time:";
            cin>>time;
            q.insertProcess(time);
        }
        if(choice==2)
        {
            q.execute();
        }
        if(choice==3)
        {
            q.displayqueue();
        }
        if(choice==4)
        {
            cout<<"Exiting program...\n";
        }
    }while(choice!=4);
}
