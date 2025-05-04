/*Singly linked list implementation using classes*/
#include<iostream>
using namespace std;

class SLL
{
    struct node
    {
        int data;
        node *next;

        /*constructor*/
        node(int s)
        {
            data = s;
            next = NULL;
        };
    }*head;
    public:
    /*constructor*/
    SLL()
    {
        head=NULL;
    }
    /*Methods*/
    void insertbeg(int val);
    void insertend(int val);
    void insertpos(int pos, int val);
    void delbeg();
    void delend();
    void delpos(int pos);
    void display();
    void search(int key);
    void reverse();
    void reverselink();
};
int main()
{
    SLL arr;
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
    cout<<"9.Reverse the linked list values."<<endl;
    cout<<"10.Reverse the linked list links."<<endl;
    cout<<"11.Exit the program"<<endl;
    cout<<"Enter your choice:";
    cin>>choice;

    if(choice>11)
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
        arr.reverse();
        cout<<"Operation done successfully"<<endl;
    }
    if(choice==10)
    {
        arr.reverselink();
        cout<<"Operation done successfully"<<endl;
    }
    if(choice==11)
    {
        cout<<"Exiting the program........"<<endl;
    }
   }while(choice!=11);
   
}

void SLL::insertbeg(int val)
{
   node*newnode=new node(val);
   newnode->data=val;
   newnode->next=NULL;
   
   newnode->next=head;
   head=newnode;
}
void SLL::display()
{
    node*curr=head;

    while(curr!=NULL)
    {
        cout<<curr->data<<"->";
        curr=curr->next;
    }
    cout<<"NULL"<<endl;
}
void SLL::insertend(int val)
{
   node*newnode=new node(val);
   newnode->data=val;
   newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;

}
void SLL::insertpos(int pos,int val)
{
   node*newnode=new node(val);
   newnode->data=val;
   newnode->next=NULL;
   if(pos<1)
    {
        cout<<"Invalid position"<<endl;
    }
    if(pos==1)
    {
        insertbeg(val);
    }
    node*temp=head;
    for(int i=0;temp->next!=NULL && i<pos-2;i++)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void SLL::delbeg()
{
    if(head==NULL)
    {
        cout<<"No elements in the list"<<endl;
        return;
    }
    node*temp=head;
    head=head->next;
    delete temp;
}
void SLL::delend()
{
    if(head==NULL)
    {
        cout<<"No elements in the list"<<endl;
        return;
    }
    node*temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    
}
void SLL::delpos(int pos)
{
    if(head==NULL)
    {
        cout<<"No elements in the list"<<endl;
        return;
    }
    if(pos<1)
    {
        cout<<"Invalid position"<<endl;
        return;
    }
    if(pos==1)
    {
        delbeg();
    }
    node*temp=head;
    for(int i=0;temp->next->next!=NULL && i<pos-2;i++)
    {
        temp=temp->next;
    }
    node*del=temp->next;
    temp->next=del->next;
    delete del;
}
void SLL::search(int key)
{
    node *temp = head;
    int flag = 0;
    for (int i = 0; temp != NULL; i++)
    {
        if (temp->data == key)
        {
            flag = 1;
            cout<<"The element is found at position"<<i+1;
            cout<<endl;
            break;
        }
        temp=temp->next;
    }
    if(flag==0)
    {
        cout<<"The element is not found anywhere in the list"<<endl;
    }
}
void SLL::reverse()
{
    int arr[100];
    node*temp=head;
    int count=0;
    while(temp!=NULL)
    {
        arr[count]=temp->data;
        count++;
        temp=temp->next;
    }
    temp=head;
    for(int i=count-1;i>=0;i--)
    {
        temp->data=arr[i];
        temp=temp->next;
    }
}
void SLL::reverselink()
{
    node*prev=NULL;
    node*curr=head;
    node*after=NULL;

    while(curr!=NULL)
    {
        after=curr->next;
        curr->next=prev;
        prev=curr;
        curr=after;
    }
    head=prev;
}
