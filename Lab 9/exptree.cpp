#include <iostream>
#include <stack>
using namespace std;

// Node structure for the Expression Tree
struct node 
{
    char value;
    node *left,*right;
    node(char val)
    {
       value=val;
       left=nullptr;
       right=nullptr;
    }
};
// Function to check if a character is an operator
bool isop(char c) 
{
    return (c=='+'||c=='-'||c=='*'||c=='/');
}

// Function to construct an expression tree from a postfix expression
node* construct(string postfix) 
{
    stack<node*>st;
    for (char c:postfix) 
    {
        if (!isop(c)) 
        {
            st.push(new node(c)); // Operand node
        } else 
        {
            node*Node=new node(c);
            Node->right=st.top(); 
            st.pop();
            Node->left=st.top(); 
            st.pop();
            st.push(Node);
        }
    }
    return st.top();
}

// Inorder traversal (to get infix expression)
void inorder(node*root) 
{
    if (root!=nullptr) 
    {
        inorder(root->left);
        cout<<root->value<<" ";
        inorder(root->right);
    }
}
void preorder(node*root) 
{
    if (root!=nullptr) 
    {
        cout<<root->value<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node*root) 
{
    if (root!=nullptr) 
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->value<<" ";
    }
}
// Function to evaluate the expression tree
int evaluate(node*root) 
{
    if (root==nullptr) 
    {
        return 0;
    }
    if (root->left==nullptr && root->right==nullptr) 
    {
        return root->value-'0';
    }
    int leftVal=evaluate(root->left);
    int rightVal=evaluate(root->right);
    switch(root->value) 
    {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
    }
    return 0;
}

int main() 
{
    int choice;
    string postfix;
    node*root;
    do 
    {
        cout<<"\nMenu:\n1.Input a postfix expression\n2.Construct Expression Tree\n3.Inorder Traversal\n4.Preorder Traversal\n5.Postorder Traversal\n6.Exit\nEnter your choice:";
        cin>>choice;

        if(choice>6) 
        {
            cout<<"Invalid choice"<<endl;
        }
        if(choice==1) 
        {
            cout<<"Enter a postfix expression"<<endl;
            cin>>postfix;
            cout<<"Successfully input received"<<endl;
        }
        if(choice==2) 
        {
            root=construct(postfix);
            cout<<"Successfully constructed"<<endl;
        }
        if(choice==3) 
        {
            inorder(root);
        }
        if(choice==4) 
        {
            preorder(root);
        }
        if(choice==5) 
        {
            postorder(root);
        }
        if(choice==6) 
        {
            cout<<"Exiting program...\n";
        }
    } while(choice!=6);
}

