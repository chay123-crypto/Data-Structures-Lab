/*A menu driven program to search an element from the given array using different algorithms*/
#include <cstdio>
#include "start.h"

int main()
{
  int choice;
  
  int size;
  printf("Enter the size of the array:");
  scanf("%d",&size);

  int arr[size];

  int key;

do
  {
    printf("\n//MENU//\n");
    printf("1.Enter an array\n");
    printf("2.Search an array using linear search algorithm\n");
    printf("3.Search an array using binary search algorithm\n");
    printf("4.Exit\n");
    
    printf("Enter your choice:");
    scanf("%d",&choice);

    if(choice==1)
      {  
        printf("Enter array elements:");
        inputarr(arr,size);
      } 
      
    if(choice==2)
      {  
        printf("Enter the element to be found:\n");
        scanf("%d",&key);
        lsearch(arr,size,key);
      } 
    if(choice==3)
      {
        printf("Enter the element to be found:");
        scanf("%d",&key);
        bubble(arr,size);
        bsearch(arr,size,key);
      }
    if(choice==4)
      {
       printf("Exiting the program.....");
      }
      if(choice>4)
      {
        printf("Incorrect choice!!!!");
      }
  }while(choice!=4);
}
