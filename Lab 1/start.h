#include <cstdio>

void bubble(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void lsearch(int arr[],int size,int key)
{
    int flag=0;
    int pos=-1;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==key)
        {
            flag=1;
            pos=i;
            break;
        }
    }
    if(flag==1)
    {
        printf("The element is found in position %d",pos+1);
    }
    else
    {
        printf("The element is not found!");
    }
}

void bsearch(int arr[],int size,int key)
{
    int high=size-1;
    int low=0;

    while(low<=high)
    {
        int mid= low+(high - low)/2;
        if(arr[mid]==key)
        {
            printf("The element is found at position %d",mid+1);
            return;
        }
        else if(key<arr[mid])
        {
            high=mid-1;
        }
        else
        {
           low=mid+1;
        }
    }
     printf("The element is not found!\n"); 
}

void selection(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        int min_idx=i;
    for (int j = i + 1; j < size; j++) 
        {
            if (arr[j] < arr[min_idx]) 
            {  
                min_idx = j;
            }
        }
           int temp=arr[i];
           arr[i]=arr[min_idx];
           arr[min_idx]=temp;
    }
}

void insertion(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printarr(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d\n",arr[i]);
    }
}

void inputarr(int arr[],int size)
{
      for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
}