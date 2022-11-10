#include <stdio.h>
#include <stdlib.h>
# define SIZE 100
struct process
{   
    int pid;
    int at;
    int bt;
};
void enqueue(int);
int dequeue();
int arr[SIZE];
int Rear = - 1;
int Front = - 1;

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
   
    int n,timequanta;
    printf("Enter the number of process: ");
    scanf("%d",&n);
    struct process p[n];
    for(int i=0;i<n;i++)
    { 
        printf("process number:%d\n",i+1);
        printf("Enter the id of process:" );
        scanf("%d",&(p[i].pid));
        printf("Enter the arrival time of process: ");
        scanf("%d",&(p[i].at));
        printf("Enter the Burst time of process: ");
        scanf("%d",&(p[i].bt));
    }
    printf("Enter the timequanta:");
    scanf("%d",&timequanta);
    int bt[n];
     
    qsort((void*)p, n, sizeof(p[0]), comparator);
    int temp=0,count=0,comp[n];
    for(int i=0;i<n;i++)
    {
        comp[i]=0;
        bt[i]=p[i].bt;
    }
    int ct[n],tat[n],wt[n],rt[n],i=0;
    while(count<n)
    {
    
       if(Front==-1)
       {   
           
          if(p[i].at<=temp)
           {
            if(p[i].bt==bt[i])
            {
               if(temp!=0)
               rt[i]=temp-p[i].at;
               else
               rt[i]=temp;
            }
           if(p[i].bt>=timequanta)
            {
               temp+=timequanta;
               p[i].bt-=timequanta;
            }
           else
            {
               temp+=p[i].bt;
               p[i].bt=0;
            }
           if(p[i].bt==0)
            {   
               ct[i]=temp;
               tat[i]=ct[i]-p[i].at;
               wt[i]=tat[i]-bt[i];
               comp[i]=1;
               count++;
            }
            int c=i;
           for(int j=i+1;j<n;j++)
           {
               if(p[j].at<=temp)
               {
                   enqueue(j);
                   i++;
               }
               else break;
           }
           
           if(p[c].bt!=0)
           {
               enqueue(c);
           }
           
          }
         else
         {   int t=i;
            
                while(temp<p[t].at)
                {
                    temp+=1;
                }
                break;
            
         }
       }

       else
       {   int k;
           while((k=dequeue())!=-1)
           { 
              
    
           if(p[k].bt==bt[k])
           {
               if(temp!=0)
               rt[k]=temp-p[k].at;
               else
               rt[k]=temp;
           }
           if(p[k].bt>=timequanta)
           {
               temp+=timequanta;
               p[k].bt-=timequanta;
           }
           else
           {
               temp+=p[k].bt;
               p[k].bt=0;
           }
           if(p[k].bt==0)
           {   
               ct[k]=temp;
               tat[k]=ct[k]-p[k].at;
               wt[k]=tat[k]-bt[k];
               comp[k]=1;
               count++;
           }
           
            int c=k;
           
           for(int j=i+1;j<n;j++)
           {
               if(p[j].at<=temp)
               {
                   enqueue(j);
                   i++;
               }
               else 
               break;
           }
           if(p[c].bt!=0)
           {
               enqueue(c);
           }
           }
        }
      
    }
    printf("Pid       AT       BT      CT     TAT     WT     RT\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d        %d       %d        %d       %d       %d        %d\n",p[i].pid,p[i].at,bt[i],ct[i],tat[i],wt[i],rt[i]);
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

void enqueue(int insert_item)
{
    if (Rear == SIZE - 1)
       printf("Overflow \n");
    else
    {
        if (Front == - 1)
        Front = 0;
        Rear = Rear + 1;
        arr[Rear] = insert_item;
    }
} 

int dequeue()
{
    if (Front == - 1 || Front > Rear)
    {
        printf("Underflow \n");
        return -1;
    }
    else
    {
        int temp=arr[Front];
        Front = Front + 1;
        return temp;
    }
  
}
