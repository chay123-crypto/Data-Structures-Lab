/*Program to check if a given number is a palindrome,armstrong or a perfect number*/
#include <iostream>
#include<cstdlib>
using namespace std;

void palindrome(int *num);
void perfect(int*num);
void armstrong(int*num);
double power(int *base,int *exp);

int main()
{
   int*choice=new int;
   int*num=new int;

   cout<<"Enter the number to be checked:";
   cin>>*num;

   do
   {
    cout<<"//MENU//"<<endl;
    cout<<"1.Check if the given number is a palindrome."<<endl;
    cout<<"2.Check if the given number is a perfect number."<<endl;
    cout<<"3.Check if the given number is an armstrong number."<<endl;
    cout<<"4.Exit the program"<<endl;
    cout<<"Enter your choice:";
    cin>>*choice;

    if(*choice==1)/*If choice is to check palindrome*/
    {
        palindrome(num);
    }

    if(*choice==2)/*If choice is to check for perfect number*/
    {
        perfect(num);
    }

    if(*choice==3)/*If choice is to check for armstrong number*/
    {
        armstrong(num);
    }
    if(*choice==4)/*If choice is to exit the program*/
    {
        cout<<"Exiting the program..."<<endl;
    }

    if(*choice>4)
    {
        cout<<"Incorrect choice!!!Enter the right choice!"<<endl;
    }
    
   }while(*choice!=4);

   return 0;
}

void palindrome(int* num)
{
    int *original=new int;
    *original=*num;
    int *rev=new int;
    *rev=0;
    int*digits=new int;

    while(*original!=0)
    {
        (*digits)=(*original)%10;
        (*rev)=(*rev)*10+(*digits);
        (*original)=(*original)/10;
    }
    if((*num)==(*rev))
    {
        cout<<"The number is a palindrome"<<endl;
    }
    else
    {
        cout<<"The number is not a palindrome"<<endl;
    }
    delete original;
    delete digits;
    delete rev;
}
void perfect(int*num)
{
    int *original=new int;
    *original=*num;
    int*count=new int;
    int*sum=new int;
    (*sum)=0;
    int *i=new int;
    *i=0;
    for(*i=1;*i<=(*original)/2;(*i)++)
    {
      if (*original%(*i)==0)
        {
           *sum+=(*i);
        }
    }
    if((*original)==(*sum))
    {
        cout<<"The number is a perfect number"<<endl;
    }
    else
    {
        cout<<"The number is not a perfect number"<<endl;
    }
    delete sum;
    delete original;
    delete count;
    delete i;
}
void armstrong(int*num)
{
    int *original=new int;
    *original=*num;
    int*count=new int;
    *count=0;
    int*sum=new int;
    *sum=0;
    int*digits=new int;

    while (*original!=0)
    {
        *original=*original/10;
        *count+=1;
    }
   *original=*num;
    while(*original!=0)
    {
        *digits=*original%10;
        *sum=*sum+power(digits,count);
        *original=*original/10;
    }
    if((*sum)==(*num))
    {
        cout<<"The number is an armstrong number"<<endl;
    }
    else
    {
        cout<<"The number is not an armstrong number"<<endl;
    }
    delete sum;
    delete original;
    delete digits;
    delete count;
}
double power(int *base,int *exp)
{
    int*i=new int;
    int*result=new int;
    *result=1;
    for(*i=0;*i<*exp;(*i)++)
    {
      (*result)*=(*base);
    }
    return *result;
    delete result;
    delete i;
}