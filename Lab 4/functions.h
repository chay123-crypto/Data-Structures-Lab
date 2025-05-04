/*header file to implement ascending insert and merging of list ADTS with Singly linked lists*/
#include <iostream>
using namespace std;

class linkedl 
{
    struct node 
    {
        int data;
        node* next;
        /*Constructor*/
        node(int d)
        {
            data=d;
            next=nullptr;
        }
    };
    
    node* head;

public:
    /*constructor for the class*/
    linkedl() 
    {
        head=nullptr;
    }
    /*given gethead function*/
    node*gethead() 
    { 
        return head; 
    }

    void ascendinginsert(int val) 
    {
        node* newnode = new node(val);
        if (head==nullptr || val < head->data) {
            newnode->next = head;
            head = newnode;
            return;
        }
        node* current = head;
        while (current->next && current->next->data < val) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }

    void create(int size)
    {
        cout << "Enter the elements: ";
        for (int i = 0; i < size; i++) 
        {
            int val;
            cin >> val;
            ascendinginsert(val);
        }
    }

    void merge(linkedl &otherlist) 
    {
        node* current=otherlist.gethead();
        while (current!=nullptr) 
        {
            ascendinginsert(current->data);
            current = current->next;
        }
    }

    void display() 
    {
        node*temp=head;
        while (temp) 
        {
            cout<<temp->data <<"->";
            temp=temp->next;
        }
        cout << "NULL" << endl;
    }
};