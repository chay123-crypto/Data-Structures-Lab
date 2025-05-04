/*Implementation of Single Circular linked list*/
#include<iostream>
using namespace std;

class CSLL
{
    struct node
    {
        int data;
        node *next;

        /*constructor for node*/
        node(int s)
        {
            data = s;
            next = NULL;
        };
    }*head;
    
    public:
    /*constructor*/
    CSLL()
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
    CSLL arr;
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
        int val,pos;
        cout<<"Enter an element to be added:"<<endl;
        cin>>val;
        cout<<"Enter the position where the element should be added:"<<endl;
        cin>>pos;
        arr.insertpos(val,pos);
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

void CSLL::insertbeg(int val)
{
   node*newnode=new node(val);
   newnode->data=val;
   newnode->next = nullptr;

   if (head==nullptr)
   {                            
       newnode->next = newnode; 
       head = newnode;
       return;
   }
    node*temp=head;
    while (temp->next!=head)
    {
        temp=temp->next;
    }

    newnode->next=head; 
    temp->next=newnode; 
    head=newnode;    
}
void CSLL::display()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    node*curr=head;
    cout<<curr->data<<"->";
    curr=curr->next;
    while(curr!=head)
    {
        cout<<curr->data<<"->";
        curr=curr->next;
    }
    cout<<"(back to head)"<<endl;
}
void CSLL::insertend(int val)
{
    node*newnode=new node(val);
    newnode->data=val;
    newnode->next=nullptr;
 
    if (head==nullptr)
    {                            
        newnode->next = newnode; 
        head = newnode;
        return;
    }
    node*temp=head;
    while (temp->next!=head)
    {
        temp=temp->next;
    }

    newnode->next=head; 
    temp->next=newnode;    
}
void CSLL::insertpos(int val,int pos)
{
   node*newnode=new node(val);
   newnode->data=val;
   newnode->next=nullptr;
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
    node*temp=head;
    int count=1;
    while(count<pos-1 && temp->next!=head)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void CSLL::delbeg()
{
    if(head==nullptr) 
    { 
        cout << "List is empty, nothing to delete!" << endl;
        return;
    }
    if(head->next==head) 
    {
        delete head;
        head=nullptr;
        return;
    } 
    node*del = head;   
    node*temp=head;
    while(temp->next != head) 
    {
        temp=temp->next;
    }
    head=head->next;
    temp->next = head;
    delete del;
}
void CSLL::delend()
{
    if(head==nullptr)
    {
        cout<<"No elements in the list"<<endl;
        return;
    }
    if (head->next == head) 
    {  
        delete head;
        head = nullptr;
        return;
    }
    node*temp=head;
    while(temp->next->next!=head)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=head;
    
}
void CSLL::delpos(int pos)
{
    if(head==nullptr)
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
        return;
    }
    node*temp=head;
    int count=1;
    while(temp->next!=head && count<pos-1)
    {
        count++;
        temp=temp->next;
    }
    node*del=temp->next;
    temp->next=del->next;
    delete del;
}
void CSLL::search(int key)
{
    node *temp = head;
    int flag = 0;
    int count=1;
    do {
        if (temp->data == key) {
            flag=1;
            cout << "The element is found at position " <<count<< endl;
            return; 
        }
        temp = temp->next;
        count++;
    } while (temp != head); 
    if(flag==0)
    {
        cout<<"The element is not found anywhere in the list"<<endl;
    }
}
