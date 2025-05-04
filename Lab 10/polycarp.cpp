#include <iostream>
#include <cstring>
#define MAX_VAL 1000
using namespace std;

int procedure()
{
    int len;
    cin >> len;

    int arr[len];
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    int pref = len;
    int freq[MAX_VAL + 1];
    memset(freq, 0, sizeof(freq)); 

    for (int i = len - 1; i >= 0; i--)
    {
        if (freq[arr[i]] > 0)
        {
            break;
        }
        freq[arr[i]]++;
        pref--;
    }

    return pref;
}

int main()
{
    cout<<("Enter number of test cases: ");
    int n;
    cin>>n;

    while (n--)
    {
        cout<<"The number of steps required are %d\n"<<procedure()<<endl;
    }

    return 0;
}