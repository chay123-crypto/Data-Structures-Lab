#include<iostream>
using namespace std;


class BST
{
    struct node
        {
            int data;
            node* left;
            node* right;
        }*root = nullptr;

        node* insert(node* newroot, int value);
        node* createnewnode(int val);
        void preorder(node* current);
        void inorder(node* current);
        void postorder(node* current);
        
    public:
        BST()
        {
            root = nullptr;
        }
        void inserthelper(int val);
        void preorderhelper();
        void inorderhelper();
        void postorderhelper();
        void search(int value);


};
int main()
{
    BST b;
    int choice;
    do
    {
        cout << "\n<MENU" << endl;
        cout << "1.Insert an element" << endl;
        cout << "2.Search for an element" << endl;
        cout << "3.Inorder traversal" << endl;
        cout << "4.Preorder traversal" << endl;
        cout << "5.Postorder traversal" << endl;
        cout << "6.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice>6) 
        {
            cout<<"Invalid choice"<<endl;
        }
        if(choice==1) 
        {
            int num;
            cout<<"Enter number to insert:";
            cin>>num;
            b.inserthelper(num);
        }
        if(choice==2) 
        {
            int key;
            cout<<"Enter number to search:";
            cin>>key;
            b.search(key);
        }
        if(choice==3) {
            b.inorderhelper();
        }
        if(choice==4) 
        {
            b.preorderhelper();
        }
        if(choice==5) 
        {
            b.postorderhelper();
        }
        if(choice==6) 
        {
            cout<<"Exiting program...\n";
        }
    }while (choice!=6);
}
BST::node*BST::insert(node* newroot, int value)
{
    if(newroot==nullptr)
    {
        newroot=createnewnode(value);
        return newroot;
    }


    if(value<newroot->data)
    {
        newroot->left=insert(newroot->left,value);
    }
    else
    {
        newroot->right=insert(newroot->right,value);
    }

    return newroot;
}

void BST::inserthelper(int val)
{
    root=insert(root,val);
}


BST::node*BST::createnewnode(int val)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->left=newnode->right=nullptr;
    return newnode;
}


void BST::preorder(node* current)
{
    if(current!=nullptr)
    {
        cout<<current->data<<" ";
        preorder(current->left);
        preorder(current->right);
    }
}

void BST::preorderhelper()
{
    cout<<"Preorder Traversal:";
    preorder(root);
    cout<<endl;
}

void BST::inorder(node* current)
{
    if(current!=nullptr)
    {
        inorder(current->left);
        cout<<current->data<<" ";
        inorder(current->right);
    }
}

void BST::inorderhelper()
{
    cout<<"Inorder Traversal:";
    inorder(root);
    cout<<endl;
}


void BST::postorder(node* current)
{
    if(current != nullptr)
    {
        postorder(current->left);
        postorder(current->right);
        cout<<current->data<<" ";
    }
}
void BST::postorderhelper()
{
    cout<<"Postorder Traversal:";
    postorder(root);
    cout<<endl;
}
void BST::search(int value)
{
    struct node*temp=root;
    int flag=0;
    while(temp!=nullptr)
    {
        if(value==temp->data)
        {
            flag=1;
            break;
        }
        else
        {
            if(value<temp->data)
            {
                temp=temp->left;
            }
            else if(value>temp->data)
            {
                temp=temp->right;
            }
        }
    }
    if(flag)
    {
        cout<<"The element is found in the tree"<<endl;
    }
    else
    {
        cout<<"The element is not found in the tree"<<endl;
    }

}