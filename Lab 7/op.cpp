#include <iostream>
#include "stackarr.h"  /*including header file*/
using namespace std;

int main() 
{
    string input;
    cout<<"Enter the string:";
    cin>>input;

    Stack s; 

    for (char ch:input) {
        if(ch=='+') 
        {
            if (!s.isempty()) 
            {
                s.pop(); 
            }
        } 
        else 
        {
            s.push(ch);
        }
    }
    string result;
    while (!s.isempty()) 
    {
        result=s.peek()+result;  
        s.pop();
    }

    cout<<"Output string is:"<<result<<endl;

    return 0;
}
