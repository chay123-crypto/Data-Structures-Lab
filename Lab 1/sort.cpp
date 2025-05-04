/*A menu driven program to sort an array using different algorithms*/
#include <cstdio>
#include "start.h"

int main()
{
    int choice;

    int size;
    printf("Enter size of the array:");
    scanf("%d",&size);
    
    int arr[size];
  do
    {
    printf("\n//MENU//\n");
    printf("1.Enter an array\n");
    printf("2.Sort an array using bubble sort\n");
    printf("3.Sort an array using selection sort\n");
    printf("4.Sort an array using insertion sort\n");
    printf("5.Exit\n");

    printf("Enter your choice:");
    scanf("%d",&choice);


    if(choice==1)
      {  
        printf("Enter the array elements:");
        inputarr(arr,size);
      } 
    if(choice==2)
      {  
        bubble(arr,size);
        printarr(arr,size);
      } 
    if(choice==3)
      {
        selection(arr,size);
        printarr(arr,size);
      }
    if(choice==4)
      {  
        insertion(arr,size);
        printarr(arr,size);
      }
    if(choice==5)
      {
       printf("Exiting the program.......");
      }
      if(choice>5)
      {
        printf("Incorrect choice!!!!\n");
      }
    }while(choice!=5);
}