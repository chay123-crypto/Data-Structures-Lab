#include<iostream>
using namespace std;

class Hash
{
    static const int size=10;
    bool occupied[size];
    int hashtable[size];
    int hashing(int key)
    {
        return key%size;
    }

    public:
    Hash()
    {
        for(int i=0;i<size;i++)
        {
            hashtable[i]=-1;
            occupied[i]=false;
        }
    }
    void insertk(int key);
    void searchk(int key);
    void deletek(int key);
    void displayk();
};
int main()
{
    Hash hs;
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
    hs.insertk(val);
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
    hs.deletek(val);
   }
   if(choice==3)
   {
    int val;
    cout<<"Enter the integer value to be searched"<<endl;
    cin>>val;
    hs.searchk(val);
   }
   if(choice==4)
   {
    hs.displayk();
   }
  } while(choice!=5);
}
void Hash::insertk(int key)
{
    int index=hashing(key);
    int i=0;
    while(i<size)
    {
        int newindex=(index+(i*i))%size;
        if(!occupied[newindex])
        {
            hashtable[newindex]=key;
            occupied[newindex]=true;
            cout<<"The element is inserted at "<<newindex<<endl;
            return;
        }
        i++;
    }
    cout<<"The element has not been inserted!!!"<<endl;
}
void Hash::deletek(int key)
{
    int index=hashing(key);
    int i=0;
    while(i<size)
    {
        int newindex=(index+(i*i))%size;

        if(occupied[newindex])
        {
            if(hashtable[newindex]==key)
            {
                hashtable[newindex]=-1;
                occupied[newindex]=false;
                cout<<"The element has been deleted"<<endl;
                return;
            }
        }
        i++;
    }
    cout<<"The element has not been deleted"<<endl;
}
void Hash::displayk()
{
    for(int i=0;i<size;i++)
    {
        if(occupied[i])
        {
            cout<<hashtable[i]<<" ";
        }
        else
        {
            cout<<"Empty"<<" ";
        }
    }

}
void Hash::searchk(int key)
{
    int index=hashing(key);
    int i=0;
    int flag=0;
    while(i<size)
    {
        int newindex=(index+(i*i))%size;
        if(!occupied)
        {
            flag=0;
        }
        if(occupied[newindex])
        {
            if(hashtable[newindex]==key)
            {
                flag=1;
            }
        }
        i++;
    }
    if(flag==1)
    {
        cout<<"The element is found"<<endl;
    }
    else
    {
        cout<<"The element has not been found!!!"<<endl;
    }
}

