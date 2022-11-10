#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{   
    int p=fork();
    if(p==0)
    {  
        sleep(10);
        printf("Child Process id: %d\n",getpid());
        printf("My parent id: %d\n",getppid());
    }
    else if(p>0)
    {
        printf("Parent Process id: %d\n",getpid());
        printf("My Child id: %d\n",p);
    }
    else
    {
        printf("Error in System call\n");
    }
    return 0;
}
