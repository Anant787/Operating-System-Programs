#include<stdlib.h>
#include <stdio.h>
struct process
{
    int pid;
    int at;
    int bt;
};
int comparator(const void *p, const void *q) 
{
    int l = ((struct process *)p)->at;
    int r = ((struct process *)q)->at; 
    
    int c = ((struct process *)p)->pid;
    int d= ((struct process *)q)->pid;  
    if(l==r)
    return (c-d);
    return (l - r);
}
int main()
{
    int n;
    printf("Enter the number of process: ");
    scanf("%d",&n);
    struct process p[n];
    for(int i=0;i<n;i++)
    { 
        printf("Process %d\n",i+1);
        printf("Enter the id of process:" );
        scanf("%d",&(p[i].pid));
        printf("Enter the arrival time of process: ");
        scanf("%d",&(p[i].at));
        printf("Enter the Burst time of process: ");
        scanf("%d",&(p[i].bt));
    }
     qsort((void*)p, n, sizeof(p[0]), comparator);
     int temp=0;
     int ct[n],tat[n],wt[n],rt[n];
     for(int i=0;i<n;i++)
     { 
        if(p[i].at<=temp)
        {
            temp+=p[i].bt;
            ct[i]=temp;
            tat[i]=ct[i]-p[i].at;
            wt[i]=tat[i]-p[i].bt;
            rt[i]=wt[i];
        }
        else
        {     
            while(temp<p[i].at)
            {
                temp++;
                
            }
             temp+=p[i].bt;
            ct[i]=temp;
            tat[i]=ct[i]-p[i].at;
            wt[i]=tat[i]-p[i].bt;
            rt[i]=wt[i];
        }
     }
     printf("Pid       AT       BT      CT     TAT     WT     RT\n");
     for(int i=0;i<n;i++)
     {
         printf("P%d        %d       %d        %d       %d        %d        %d\n",p[i].pid,p[i].at,p[i].bt,ct[i],tat[i],wt[i],rt[i]);
     }
     float avgtat,avgwt,avgrt,sum1,sum2,sum3;
     for(int i=0;i<n;i++)
     {
        sum1+=tat[i];
        sum2+=wt[i];
        sum3+=rt[i];
     }
     avgtat=sum1/n;
     avgwt=sum2/n;
     avgrt=sum3/n;
     printf("Average Turn Around Time: %f\n",avgtat);
     printf("Average Waiting Time: %f\n",avgwt);
     printf("Average Response Time: %f\n",avgrt);
     return 0;
}
