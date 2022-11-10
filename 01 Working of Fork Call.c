#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()

{  
    int p=fork();
    if(p==0)

    {    
        printf("In child Process\n");
        printf("Child Process id: %d\n",getpid());
    }
    else if(p>0)
    {    
        printf("In Parent Process\n");
        printf("Parent Process id: %d\n",getpid());
    }
    else
    {
     printf("Error in System call\n");
    }

    printf("Hello world\n");

    return 0;

}
