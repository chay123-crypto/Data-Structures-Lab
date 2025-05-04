/* Checking if a string has balanced brackets */
#include <iostream>
#include "stack.h"  // Assume this implements a basic stack with push, pop, top, and isempty
using namespace std;

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}
int main()
{
    string input_text;
    cout<<"Enter a valid expression with brackets"<<endl;
    cin>>input_text;

    stack s;
    bool balanced=true;

    for(char ch:input_text)
    {
        if (ch=='('||ch=='['||ch=='{')
        {
            s.push(ch);
        }
        else if(ch==')'||ch==']'||ch=='}')
        {
            if (s.isempty())
            {
                balanced=false;
                break;
            }

            char top=s.peek();
            if (!isMatchingPair(top, ch))
            {
                balanced = false;
                break;
            }
            s.pop();
        }
    }
    if (!s.isempty())
    {
        balanced=false;
    }

    if (balanced)
    {
        cout<<"The string is balanced"<<endl;
    }
    else
    {
        cout<<"The string is not balanced"<<endl;
    }
}
