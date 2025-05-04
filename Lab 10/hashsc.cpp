/*Implementing ah Hash using seperate chaining method*/
#include<iostream>
#include<list>
using namespace std;

class Hashtable
{
    /*Member values*/
    static const int size=10;
    list<int>table[size];

    public:
    /*Member functions*/
    void insertkey(int key);
    int hashing(int key);
    void searchkey(int key);
    void deletekey(int key);
    void display();
};
int main()
{
    Hashtable h;
    int choice;

    do
   {
    cout<<"//MENU//"<<endl;
    cout<<"1.Insert an element"<<endl;
    cout<<"2.Delete the element."<<endl;
    cout<<"3.search for an element"<<endl;
    cout<<"4.Display the hash table"<<endl;
    cout<<"5.Exit the program"<<endl;
    cout<<"Enter your choice:";
    cin>>choice;
   
   if(choice>5)
   {
    cout<<"Incorrect choice is entered"<<endl;
   }
   if(choice==1)
   {
    int val;
    cout<<"Enter the integer value to be inserted"<<endl;
    cin>>val;
    h.insertkey(val);
   }
   if(choice==5)
   {
    cout<<"Exiting the program..........."<<endl;
   }
   if(choice==2)
   {
    int val;
    cout<<"Enter the integer value to be deleted"<<endl;
    cin>>val;
    h.deletekey(val);
   }
   if(choice==3)
   {
    int val;
    cout<<"Enter the integer value to be searched"<<endl;
    cin>>val;
    h.searchkey(val);
   }
   if(choice==4)
   {
    h.display();
   }
  } while(choice!=5);
}
int Hashtable::hashing(int key)
{
   return key%size;
}
void Hashtable::insertkey(int key)
{
    int index=hashing(key);
    for(int val:table[index])
    {
        if(val==key)
        {
            return;
        }
    }
    table[index].push_back(key);
    cout<<"The integer "<<key<<" has been successfully inserted at index "<<index<<endl;
}
void Hashtable::display()
{
    for(int i=0;i<size;i++)
    {
        cout<<"Index"<<i<<":";
        for(int val:table[i])
        {
            cout<<val<<"->";
        }
        cout<<"NULL"<<endl;
    }
}
void Hashtable::searchkey(int key)
{
    int index=hashing(key);
    for(int val:table[index])
    {
        if(val==key)
        {
            cout<<"The element is found"<<endl;
            return;
        }
    }
    cout<<"The element is not found"<<endl;
}
void Hashtable::deletekey(int key)
{
    int index=hashing(key);
    table[index].remove(key);
    cout<<"The integer "<<key<<" has been successfully deleted at index "<<index<<endl;
}