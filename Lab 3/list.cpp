/*Implementation of lists using arrays*/
#include<iostream>
using namespace std;

class list
{
    private:
    /*attributes*/
    int arr[5];
    int count;
    int size=5;

    public:
    /*constructor*/
    list(int s=5)
    {
        size=s;
        count=0;
    }
    /*Methods*/
    void insertbeg(int val)
    {
        if(count>=size)
        {
            cout<<"The array is full!"<<endl;
            return;
        }
        for(int i=count;i>0;i--)
        {
            arr[i]=arr[i-1];
   
        }
        arr[0]=val;
        count++;
        cout << "Operation done successfully" << endl;
    }
    void insertend(int val)
    {
        if(count>=size)
        {
            cout<<"The array is full"<<endl;
            return;
        }
        arr[count]=val;
        count++;
        cout << "Operation done successfully" << endl;
    }
    void insertpos(int val,int pos)
    {
        if(count>=size)
        {
            cout<<"The array is full"<<endl;
            return;
        }
        if (pos<1||pos>count+1)
        {
            cout<<"Invalid position"<<endl;
            return;
        }
        for(int i=count;i>pos-1;i--)
        {
            arr[i]=arr[i-1];
        }
        arr[pos-1]=val;
        count++;
        cout << "Operation done successfully" << endl;
    }
    void deletebeg()
    {
        if(count<1)
        {
            cout<<"The array is empty"<<endl;
            return;
        }
        for(int i=0;i<count-1;i++)
        {
            arr[i]=arr[i+1];
        }
        count--;
        cout << "Operation done successfully" << endl;
    }
    void deleteend()
    {
        if(count<1)
        {
            cout<<"The array is empty"<<endl;
            return;
        }
        count--;
        cout << "Operation done successfully" << endl;
    }
    void deletepos(int pos)
    {
        if(count<1)
        {
            cout<<"The array is empty"<<endl;
            return;
        }
        if(pos<1||pos>count+1)
        {
            cout<<"Invalid position"<<endl;
            return;
        }
        for(int i=pos;i<count-1;i++)
        {
            arr[i]=arr[i+1];
        }
        count--;
        cout << "Operation done successfully" << endl;
    }
    void search(int key)
    {
        bool found=false;
        for(int i=0;i<=count-1;i++)
        {
            if(arr[i]==key)
            {
                cout<<"The element is found at position "<<i+1<<endl;
                found=true;
            }       
        }
        if(!found)
        {
            cout<<"The element is not found"<<endl;
        }
    }
    void display()
    {
        for(int i=0;i<count;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void rotate(int k)
    {
        if (count < 1)
        {
            cout << "The array is empty!" << endl;
            return;
        }
        k = k % count;
        int temp[5];   

        for (int i = 0; i < count; i++)
        {
            temp[(i + k) % count] = arr[i];
        }

        for (int i = 0; i < count; i++)
        {
            arr[i] = temp[i];
        }

        cout << "Array rotated by " << k << " positions." << endl;
    }
};
int main()
{
    list arr;
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
    cout<<"9.Rotate the elements of the array by k positions."<<endl;
    cout<<"10.Exit the program"<<endl;
    cout<<"Enter your choice:";
    cin>>choice;

    if(choice>10)
    {
        cout<<"Enter a valid choice"<<endl;
    }
    if(choice==1)
    {
        int val;
        cout<<"Enter an element to be added:"<<endl;
        cin>>val;
        arr.insertbeg(val);
    }
    if(choice==2)
    {
        int val;
        cout<<"Enter an element to be added:"<<endl;
        cin>>val;
        arr.insertend(val);
    }
    if(choice==3)
    {
        int val,pos;
        cout<<"Enter an element to be added:"<<endl;
        cin>>val;
        cout<<"Enter the position where the element should be added:"<<endl;
        cin>>pos;
        arr.insertpos(val,pos);
    }
    if(choice==4)
    {
        arr.deletebeg();
    }
    if(choice==5)
    {
       arr.deleteend();
    }
    if(choice==6)
    {
       int pos;
       cout<<"Enter the position of the element to be deleted:"<<endl;
       cin>>pos;
       arr.deletepos(pos);
    }
    if(choice==7)
    {
        int val;
        cout<<"Enter the element to be searched:"<<endl;
        cin>>val;
        arr.search(val);
    }
    if(choice==8)
    {
       arr.display();
    }
    if(choice==9)
    {
        int k;
        cout<<"Enter the value of k:"<<endl;
        cin>>k;
        arr.rotate(k);
    }
    if(choice==10)
    {
        cout<<"Exiting the program........"<<endl;
    }
   }while(choice!=10);
   
}