/*Implementation of doubly linked list*/
#include<iostream>
using namespace std;

class DLL
{
    struct node
    {
        int data;
        node*next;
        node*prev;

        /*constructor for node*/
        node(int s)
        {
            data=s;
            next=nullptr;
            prev=nullptr;
        }
    }*head,*tail;

    public:
    /*Constructor*/
    DLL()
    { 
        head=nullptr;
        tail=nullptr;
    }
    /*Methods*/
    void insertbeg(int val);
    void insertend(int val);
    void insertpos(int val,int pos);
    void delbeg();
    void delend();
    void delpos(int pos);
    void search(int key);
    void display();
    void reverse();
};
int main()
{
    DLL arr;
    int choice;

    do
   {
    cout<<"//MENU//"<<endl;
    cout<<"1.Insert an element at the beginning"<<endl;
    cout<<"2.Insert the element at the end."<<endl;
    cout<<"3.Insert an element at a given position"<<endl;
    cout<<"4.Delete an element at the beginning"<<endl;
    cout<<"5.Delete the element at the end."<<endl;
    cout<<"6.Delete an element at a given position"<<endl;
    cout<<"7.Search for an element in the array"<<endl;
    cout<<"8.Display the array."<<endl;
    cout<<"9.Exit the program"<<endl;
    cout<<"Enter your choice:";
    cin>>choice;

    if(choice>9)
    {
        cout<<"Enter a valid choice"<<endl;
    }
    if(choice==1)
    {
        int val;
        cout<<"Enter an element to be added:"<<endl;
        cin>>val;
        arr.insertbeg(val);
        cout<<"Operation done successfully"<<endl;
    }
    if(choice==2)
    {
        int val;
        cout<<"Enter an element to be added:"<<endl;
        cin>>val;
        arr.insertend(val);
        cout<<"Operation done successfully"<<endl;
    }
    if(choice==3)
    {
        int pos,val;
        cout<<"Enter an element to be added:"<<endl;
        cin>>val;
        cout<<"Enter the position where the element should be added:"<<endl;
        cin>>pos;
        arr.insertpos(pos,val);
        cout<<"Operation done successfully"<<endl;
    }
    if(choice==4)
    {
        arr.delbeg();
        cout<<"Operation done successfully"<<endl;
    }
    if(choice==5)
    {
       arr.delend();
       cout<<"Operation done successfully"<<endl;
    }
    if(choice==6)
    {
       int pos;
       cout<<"Enter the position of the element to be deleted:"<<endl;
       cin>>pos;
       arr.delpos(pos);
       cout<<"Operation done successfully"<<endl;
    }
    if(choice==7)
    {
        int val;
        cout<<"Enter the element to be searched:"<<endl;
        cin>>val;
        arr.search(val);
        cout<<"Operation done successfully"<<endl;
    }
    if(choice==8)
    {
       arr.display();
       cout<<"Operation done successfully"<<endl;
    }
    if(choice==9)
    {
        cout<<"Exiting the program........"<<endl;
    }
   }while(choice!=9);
}
void DLL::insertbeg(int val)
{
    node*newnode=new node(val);
    if(head==nullptr)
    {
        head=tail=newnode;
    }
    else
    {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}
void DLL::insertend(int val)
{
    node*newnode=new node(val);
    if (tail==nullptr)
    {
        head=tail=newnode;
    }
    else
    {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}
void DLL::insertpos(int val, int pos)
{
    if(pos<1)
    {
        cout<<"Invalid position"<<endl;
        return;
    }
    if(pos==1)
    {
        insertbeg(val);
        return;
    }
    node*newnode=new node(val);
    node*temp=head;
    for (int i=1;i<pos-1 && temp!=nullptr;i++)
    {
        temp=temp->next;
    }
    if (temp == nullptr)
    {
        cout << "Position out of range" << endl;
        return;
    }
    newnode->next = temp->next;
    if(temp->next!=nullptr)
    {
        temp->next->prev=newnode;
    }
    temp->next=newnode;
    newnode->prev=temp;
    if(newnode->next==nullptr)
    {
        tail=newnode;
    }
}
void DLL::delbeg()
{
    if(head==nullptr)
    {
        cout<<"Nothing to delete"<< endl;
        return;
    }
    node*temp=head;
    head=head->next;
    if (head!=nullptr)
        head->prev=nullptr;
    else
        tail=nullptr;
    delete temp;
}
void DLL::delend()
{
    if(tail==nullptr)
    {
        cout<<"Nothing to delete"<<endl;
        return;
    }
    node*temp=tail;
    tail=tail->prev;
    if (tail!=nullptr)
    {
        tail->next=nullptr;
    }
    else
    {
        head=nullptr;
    }
    delete temp;
}
void DLL::delpos(int pos)
{
    if(head==nullptr || pos<1)
    {
        cout<<"Invalid position or empty list"<<endl;
        return;
    }
    if(pos==1)
    {
        delbeg();
        return;
    }
    node*temp=head;
    for(int i=1;i<pos && temp!=nullptr;i++)
    {
        temp=temp->next;
    }
    if(temp==nullptr)
    {
        cout<<"Position out of range"<<endl;
        return;
    }
    if(temp->next!=nullptr)
    {
        temp->next->prev = temp->prev;
    }
    if(temp->prev!=nullptr)
    {
        temp->prev->next=temp->next;
    }
    if(temp==tail)
    {
        tail=temp->prev;
    }
    delete temp;
}
void DLL::display()
{
    if(head==nullptr)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    node*temp=head;
    cout<<"NULL<->";
    while (temp!=nullptr)
    {
        cout<<temp->data<<"<->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void DLL::search(int key)
{
    node*temp=head;
    int pos=1;
    while (temp!=nullptr)
    {
        if (temp->data==key)
        {
            cout<<"Element found at position"<<pos<<endl;
            return;
        }
        temp=temp->next;
        pos++;
    }
    cout <<"Element not found"<< endl;
}
