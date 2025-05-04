/*Implement a graph ADT using adjacency matrix*/
#include<iostream>
using namespace std;

class Graph
{
    int adjmatrix[10][10];
    int vertices;

    public:
    Graph(int v)
    {
        vertices=v;
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                adjmatrix[i][j]=0;
            }
        }
    }
    /*Member functions*/
    void insertnode(int s,int d);
    void deletenode(int s,int d);
    void searchnode(int s,int d);
    void displaynodes();
};
int main()
{
    int nodes;
    cout<<"Enter the number of nodes"<<endl;
    cin>>nodes;
    Graph g(nodes);
    int choice;

    do
   {
    cout<<"//MENU//"<<endl;
    cout<<"1.Insert an element"<<endl;
    cout<<"2.Delete the element."<<endl;
    cout<<"3.search for an element"<<endl;
    cout<<"4.Display the adjacency matrix"<<endl;
    cout<<"5.Exit the program"<<endl;
    cout<<"Enter your choice:";
    cin>>choice;
   
   if(choice>5)
   {
    cout<<"Incorrect choice is entered"<<endl;
   }
   if(choice==1)
   {
    int src,dest;
    cout<<"Enter source"<<endl;
    cin>>src;
    cout<<"Enter destination"<<endl;
    cin>>dest;
    g.insertnode(src,dest);
   }
   if(choice==5)
   {
    cout<<"Exiting the program..........."<<endl;
   }
   if(choice==2)
   {
    int src,dest;
    cout<<"Enter source"<<endl;
    cin>>src;
    cout<<"Enter destination"<<endl;
    cin>>dest;
    g.deletenode(src,dest);
   }
   if(choice==3)
   {
    int src,dest;
    cout<<"Enter source"<<endl;
    cin>>src;
    cout<<"Enter destination"<<endl;
    cin>>dest;
    g.searchnode(src,dest);
   }
   if(choice==4)
   {
    g.displaynodes();
   }
  } while(choice!=5);
}
void Graph::insertnode(int s,int d)
{
    adjmatrix[s][d]=1;
    adjmatrix[d][s]=1;
    cout<<"An edge is added"<<endl;
}
void Graph::deletenode(int s,int d)
{
    adjmatrix[s][d]=0;
    adjmatrix[d][s]=0;
    cout<<"An edge is deleted"<<endl;
}
void Graph::displaynodes()
{
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
            cout<<adjmatrix[i][j]<<" ";

        }
        cout<<endl;
    }
}
void Graph::searchnode(int s,int d)
{
    if(adjmatrix[s][d]==1)
    {
        cout<<"An edge is present"<<endl;
    }
    else
    {
        cout<<"An edge is not present"<<endl;
    }
}