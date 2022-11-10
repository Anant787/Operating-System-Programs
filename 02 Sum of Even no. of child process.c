#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{   
    int n,sumodd=0,sumeven=0;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array: ");
    for(int i=0;i<n;i++)
    {
      scanf("%d",&arr[i]);
    }
    int p=fork();
    if(p==0)
    {
        printf("In Child Process\n");
        for(int i=0;i<n;i++)
        {
            if(arr[i]%2!=0)
            sumodd+=arr[i];
}
           printf("Sum of odd Numbers of array:  %d\n",sumodd);
    }
    else if(p>0)
    {   
        sleep(2);
        printf("In Parent Process\n");
        for(int i=0;i<n;i++)
        {
            if(arr[i]%2==0)
            sumeven+=arr[i];
        }
         printf("Sum of even Numbers of array:  %d\n",sumeven);
    }
    else
    {
        printf("Error in System call\n");
    }

    return 0;
}
