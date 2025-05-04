#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        int t;
        cin>>t;

        int arr[t];
        int max1=-1,max2=-1;

        for(int i=0;i<t;i++)
        {
            cin>>arr[i];
        }
        for(int i=0;i<t;i++)
        {
            if(arr[i]>max1)
            {
                max2=max1;
                max1=arr[i];
            }
            else if(arr[i]>max2)
            {
                max2=arr[i];
            }
        }
        for(int i=0;i<t;i++)
        {
            if(arr[i]==max1)
            {
                cout<<arr[i]-max2<<" ";
            }
            else
            {
                cout<<arr[i]-max1<<" ";
            }
        }
        cout<<endl;
    }
}

