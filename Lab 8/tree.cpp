#include<iostream>
using namespace std;

class tree 
{
    struct node 
    {
        int data;
        node *right,*left;
        node(int s) 
        {
            right=left=nullptr;
            data=s;
        }
    }*root;

    public:
    tree() 
    { 
        root=nullptr; 
    }
    void insert(int num);
    void search(int key);
    void inorder();
    void preorder();
    void postorder();
    
    private:/*The functions are called again for recursion*/
    node* insert(node* root,int num);
    bool search(node* root,int key);
    void inorder(node* root);
    void preorder(node* root);
    void postorder(node* root);
};

int main() 
{
    tree t;
    int choice;
    do {
        cout<<"\nMenu:\n1.Insert element\n2.Search element\n3.Inorder Traversal\n4.Preorder Traversal\n5.Postorder Traversal\n6.Exit\nEnter your choice:";
        cin>>choice;

        if(choice>6) {
            cout<<"Invalid choice"<<endl;
        }
        if(choice==1) {
            int num;
            cout<<"Enter number to insert:";
            cin>>num;
            t.insert(num);
        }
        if(choice==2) {
            int key;
            cout<<"Enter number to search:";
            cin>>key;
            t.search(key);
        }
        if(choice==3) {
            t.inorder();
        }
        if(choice==4) {
            t.preorder();
        }
        if(choice==5) {
            t.postorder();
        }
        if(choice==6) {
            cout<<"Exiting program...\n";
        }
    } while(choice!=6);
}

void tree::insert(int num) 
{
    root=insert(root,num);
    cout<<"The given number is inserted"<<endl;
}

tree::node* tree::insert(node* root,int num) 
{
    if(!root) 
    {
      return new node(num);
    }
    if(num<root->data) root->left=insert(root->left,num);
    else root->right=insert(root->right,num);
    return root;
}

void tree::search(int key) 
{
    if(search(root,key)) 
    {
        cout<<"The given element is in the tree"<<endl;
    }
    else 
    {
        cout<<"The given element is in the tree"<<endl;
    }
}

bool tree::search(node* root,int key) 
{
    if(!root) 
    {
        return false;
    }
    if(root->data==key) 
    {
        return true;
    }
    return key<root->data ? search(root->left,key) : search(root->right,key);
}

void tree::inorder() 
{
    if(root==nullptr) 
    {
        cout<<"No elements in tree"<<endl;
        return;
    }
    inorder(root);
    cout<<endl;
}

void tree::inorder(node* root) 
{
    if(!root) 
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void tree::preorder() 
{
    if(root==nullptr) 
    {
        cout<<"No elements in tree"<<endl;
        return;
    }
    preorder(root);
    cout<<endl;
}

void tree::preorder(node* root) 
{
    if(!root) 
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void tree::postorder() 
{
    if(root==nullptr) 
    {
        cout<<"No elements in tree"<<endl;
        return;
    }
    postorder(root);
    cout<<endl;
}

void tree::postorder(node* root)
 {
    if(!root) 
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
