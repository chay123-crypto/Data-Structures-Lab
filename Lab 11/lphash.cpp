/*Implement a hash adt using linear probing*/
#include<iostream>
using namespace std;

class Hash
{
    int size=10;
    int arr[10];
    bool occupied[10];

    public:
    Hash(int s=10)
    {
        size=s;
        for(int i=0;i<size;i++)
        {
            arr[i]=-1;
            occupied[i]=false;
        }
    }
    int hash(int key);
    void insert(int key);
    void search(int key);
    void del(int key);
    void display();
};
int main()
{
    Hash h;
    int choice;
    do 
    {
        cout<<"\nMenu:\n1.Insert an element \n2.Search for an element\n3.delete an element from the hash table\n4.Display\n5.Exit\nEnter your choice: ";
        cin>>choice;
        
        if(choice>4)
        {
            cout<<"Invalid choice"<<endl;
        }
        if(choice==1)
        {
            int num;
            cout<<"Enter number to insert:";
            cin>>num;
            h.insert(num);
        }
        if(choice==2)
        {
            int num;
            cout<<"Enter number to search:";
            cin>>num;
            h.search(num);
        }
        if(choice==3)
        {
            int num;
            cout<<"Enter number to delete:";
            cin>>num;
            h.del(num);
        }
        if(choice==4)
        {
            h.display();
        }
        if(choice==5)
        {
            cout<<"Exiting program...\n";
        }
    }while(choice!=5);

}
int Hash::hash(int key)
{
    return key%size;
}
void Hash::insert(int key)
{
   int k=hash(key);
   int i=0;
   while(arr[(k+i)%size]!=-1)
   {
    i++;
     if(i==size)
     {
       cout<<"Hash table is full"<<endl;
       return;
     }
   }
   int index=(k+i)%size;
   arr[index]=key;
   occupied[index]=true;
   cout<<"Successfully inserted "<<key<<" into the hash table"<<endl;
}
void Hash::search(int key)
{
    int k=hash(key);
    int flag=0;
    int i=0;
    while(arr[(k+i)%size]!=-1)
    {
        if(arr[(k+i)%size]==key)
        {
            flag=1;
        }
        if(i==size)
        {
            break;
        }
        i++;
    }
    if(flag==1)
    {
        cout<<"The element is found in the array"<<endl;
    }
    else
    {
        cout<<"The element is not found in the array"<<endl;
    }
}
void Hash::del(int key)
{
    int k=hash(key);
    int i=0;
    while(occupied[(k+i)%size]==true)
    {
        if(arr[(k+i)%size]==key)
        {
            arr[(k+i)%size]=-1;
            occupied[(k+i)%size]=true;
            cout<<"Successfully deleted "<<key<<" from the array"<<endl;
            return;
        }  
        if(i==size)
        {
            break;  
        }
        i++;
    }
    cout<<"Successfully not deleted "<<key<<" from the array"<<endl;
}
void Hash::display()
{
    for(int i=0;i<size;i++)
    {
        if(occupied[i] && arr[i]!=-1)
        {
            cout<<arr[i]<<" ";
        }
        else
        {
            cout<<"Empty"<<" ";
        }
    }
}