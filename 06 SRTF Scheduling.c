#include<stdlib.h>
#include <stdio.h>
struct process
{
    int i;
    int pid;
    int at;
    int bt;

};
int comparator(const void *p, const void *q) 
{
  int l = ((struct process *)p)->bt;
    int r = ((struct process *)q)->bt; 
    
    int a = ((struct process *)p)->at;
     int b = ((struct process *)q)->at; 
    
    int c = ((struct process *)p)->pid;
    int d= ((struct process *)q)->pid;  
    if(l==r)
    { 
         if(a==b)
        return c-d;
       return a-b;
    }
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
        printf("Enter the process number:");
        scanf("%d",&p[i].i);
        printf("Enter the id of process:" );
        scanf("%d",&(p[i].pid));
        printf("Enter the arrival time of process: ");
        scanf("%d",&(p[i].at));
        printf("Enter the Burst time of process: ");
        scanf("%d",&(p[i].bt));
    }
    int at[n],bt[n],pid[n];
     for(int i=0;i<n;i++)
     {
        bt[i]=p[i].bt;
        at[i]=p[i].at;
        pid[i]=p[i].pid;
     }
     qsort((void*)p, n, sizeof(p[0]), comparator);
     int temp=0;
     int ct[n],tat[n],wt[n],rt[n];
     int comp[n];
     for(int i=0;i<n;i++)
     comp[i]=0;
     int count=0;
     
 
     while(count!=n)
     {
     for(int i=0;i<n;i++)
     {   
        if(comp[p[i].i-1]==1)
        continue;
        else if(p[i].at<=temp)
        {   
            if(p[i].bt==bt[p[i].i-1])
            {   if(temp>0)
                rt[p[i].i-1]=temp-at[p[i].i-1];
                else 
                rt[p[i].i-1]=temp;
            }
            temp+=1;
            p[i].bt-=1;
            if(p[i].bt==0)
            {
            ct[p[i].i-1]=temp;
            tat[p[i].i-1]=ct[p[i].i-1]-at[p[i].i-1];
            wt[p[i].i-1]=tat[p[i].i-1]-bt[p[i].i-1];
            comp[p[i].i-1]=1;
            count++;
            }
             break;
        }
        else
        {     
            int t=i,tim,c=0;
             for(int j=i+1;j<n;j++)
            {
                 if(comp[p[j].i-1]==0&&p[j].at<=temp)
                {
                    t=j;
                    c=1;
                    break;
                }
            }
            if(c!=1)
            { 
                tim=p[0].at;
                t=0;
            for(int j=1;j<n;j++)
            {
                 if(comp[p[j].i-1]==0&&p[j].at<tim)
                {
                    t=j;
                    tim=p[j].at;
                }
            }
                
            while(temp<p[t].at)
            {
                temp++;
            }
            }
            if(p[t].bt==bt[p[t].i-1])
            {   if(temp>0)
                rt[p[t].i-1]=temp-at[p[t].i-1];
                else 
                rt[p[t].i-1]=temp;
            }
             temp+=1;
             p[t].bt-=1;
             if(p[t].bt==0)
             {
            ct[p[t].i-1]=temp;
            tat[p[t].i-1]=ct[p[t].i-1]-at[p[t].i-1];
            wt[p[t].i-1]=tat[p[t].i-1]-bt[p[t].i-1];
            count++;
            comp[p[t].i-1]=1;
             }
             break;
        }
     }
     qsort((void*)p, n, sizeof(p[0]), comparator);
     } 
     printf("Pid       AT       BT      CT     TAT     WT     RT\n");
     for(int i=0;i<n;i++)
     {
         printf("P%d        %d       %d        %d       %d       %d        %d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
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
