#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main()
{   
    int p=fork();
    if(p==0)
    {
        printf("In Child Process\n");
        printf("Child Process id: %d\n",getpid());
        exit(0);
    }
    else if(p>0)
    {
        printf("Parent Process id: %d\n",getpid());
        sleep(80);
        printf("In Parent Process\n");
    }
    else
    {
        printf("Error in System call\n");
    }
    return 0;
}
