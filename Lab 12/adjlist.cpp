/*Implementation of a graph ADT using adjacency list*/
#include<iostream>
using namespace std;

class GraphL
{
    
    private:
    struct node
    {
        int vertex;
        node*next;
    };
    static const int size=10;
    int vertices;
    node*adjlist[size];

    public:
    GraphL(int v)
    {
        vertices=v;
        for(int i=0;i<vertices;i++)
        {
            adjlist[i]=nullptr;
        }
    }
    /*Member functions*/
    void insertgraph(int src,int dest);
    void deletegraph(int src,int dest);
    void search(int src,int dest);
    void display();
};
int main()
{
    GraphL a(10);
    int choice;

    do
   {
    cout<<"//MENU//"<<endl;
    cout<<"1.Insert an element"<<endl;
    cout<<"2.Delete the element."<<endl;
    cout<<"3.search for an element"<<endl;
    cout<<"4.Display theadjacency list"<<endl;
    cout<<"5.Exit the program"<<endl;
    cout<<"Enter your choice:";
    cin>>choice;
   
   if(choice>5 || choice<1)
   {
    cout<<"Incorrect choice is entered"<<endl;
   }
   if(choice==1)
   {
    int src;
    cout<<"Enter the source position"<<endl;
    cin>>src;
    int des;
    cout<<"Enter the destination position"<<endl;
    cin>>des;
    a.insertgraph(src,des);
   }
   if(choice==5)
   {
    cout<<"Exiting the program..........."<<endl;
   }
   if(choice==2)
   {
    int src;
    cout<<"Enter the source position"<<endl;
    cin>>src;
    int des;
    cout<<"Enter the destination position"<<endl;
    cin>>des;
    a.deletegraph(src,des);
   }
   if(choice==3)
   {
    int src;
    cout<<"Enter the source position"<<endl;
    cin>>src;
    int des;
    cout<<"Enter the destination position"<<endl;
    cin>>des;
    a.search(src,des);
   }
   if(choice==4)
   {
    a.display();
   }
  } while(choice!=5);
}
void GraphL::insertgraph(int src,int des)
{   
    if(src>size || des>size)
    {
        cout<<"Invalid vertex"<<endl;
        return;
    }
    node*newnode=new node;
    newnode->vertex=des;
    newnode->next=adjlist[src];
    adjlist[src]=newnode;

    cout<<"Successfully added a new edge"<<endl;
}
void GraphL::display()
{
    cout<<"------ADJACENCY LIST------"<<endl;
    for(int i=0;i<vertices;i++)
    {
        cout<<"Adjlist["<<i<<"]->";
        node*temp=adjlist[i];
        while(temp!=nullptr)
        {
            cout<<temp->vertex<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
}
void GraphL::deletegraph(int src,int dest)
{
    if (adjlist[src]==nullptr)
    {
        cout<<"Edge not found!"<<endl;
        return;
    }

    if (adjlist[src]->vertex==dest)
    {
        node* temp=adjlist[src];
        adjlist[src]=adjlist[src]->next;
        delete temp;
        cout<<"Successfully deleted the edge"<<endl;
        return;
    }

    node* temp=adjlist[src];
    while (temp->next!=nullptr && temp->next->vertex!=dest)
    {
        temp=temp->next;
    }

    if (temp->next==nullptr)
    {
        cout<<"Edge not found!"<<endl;
        return;
    }

    node*deleting=temp->next;
    temp->next=temp->next->next;
    delete deleting;

    cout<<"Successfully deleted the edge"<<endl;
}
void GraphL::search(int src,int dest)
{
    if (adjlist[src]==nullptr)
    {
        cout<<"Edge not found!"<<endl;
        return;
    }
    int flag=0;
    node*temp=adjlist[src];
    while(temp!=nullptr)
    {
        if(temp->vertex==dest)
        {
            flag=1;
        }
        temp=temp->next;
    }
    if(flag==1)
    {
        cout<<"An edge is present at the given vertices"<<endl;
    }
    else
    {
        cout<<"An edge is not present"<<endl;
    }
}

