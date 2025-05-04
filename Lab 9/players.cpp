#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int k;
        int q;
        cin>>k>>q;
        vector<int>a;
        vector<int>n;
        for(int i=0;i<k;i++){
            int e;
            cin>>e;
            a.push_back(e);
        }

        for(int i = 0;i < q;i++){
            int e;
            cin >> e;
            n.push_back(e);
        }

        int min = a[0];
        
        for(int num:n)
        {
            vector<int>temp;
            for(int i=0;i<num;i++)
            {
                temp.push_back(i);
            }
            int count=0;
            for(int i=0;i<a[0] && i<=temp.size();i++)
            {
                count++;
            }
            cout<<count - 1<<" ";
        }
        cout<<endl;
    }
}
