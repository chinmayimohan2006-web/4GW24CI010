#include<stdio.h>

int process[50];
    int n;
    int bt[50];
void RR(int process[], int n, int bt[],int quantum)
{
    int wt[n];
    int tat[n];
    int rem_bt[n];
    for(int i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;
        rem_bt[i]=bt[i];
    }
    int t=0;
    
    while(1)
    {
        int completed=1;
        for(int i=0;i<n;i++)
        {
            if(rem_bt[i]>0)
            {
                completed=0;
            }
            if(rem_bt[i]<=quantum)
            {
                t=t+rem_bt[i];
                wt[i]=t-bt[i];
                rem_bt[i]=0;
            }
            else
            {
                t=t+quantum;
                rem_bt[i]=rem_bt[i]-quantum;
            }
        }
    
    if(completed==1)
    break;
    }
    for(int i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
    }
    printf("-------------Round Robin Algorithm------------\n");
    printf("waiting time:");
    for(int i=0;i<n;i++)
    {
        printf("%d ",wt[i]);
    }
    printf("\n");
    printf("Turn around time:");
    for(int i=0;i<n;i++)
    {
        printf("%d ",tat[i]);
    }
    printf("\n");
    int avgWT=0;
    int avgTAT=0;
    for(int i=0;i<n;i++)
    {
        avgWT=avgWT+wt[i];
        avgTAT=avgTAT+tat[i];
    }
    printf("--------------------------------\n");
    printf("Averge Waiting Time:%.2f\n",((float)avgWT/(float)n));
    printf("Averge Turn Around  Time:%.2f\n",((float)avgTAT/(float)n));
}
int main()
{
    
    printf("Enter the number of processes: "); 
    scanf("%d",&n);
    
    
    for(int i=0;i<n;i++)
    {
       
       printf("Enter the Process ID for process %d: ", i + 1); 
        scanf("%d", &process[i]);
    }

    
    printf("Enter the burst times:\n"); 
    for(int i=0;i<n;i++)
    {
        printf("Burst Time for P%d: ", process[i]);
        scanf("%d", &bt[i]);
    }
    
  
    printf("\n--- Entered Data ---\n");
    printf("Processes IDs: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",process[i]);
    }
    
    
    printf("\nBurst Times: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",bt[i]);
    }
    printf("\n");
    int quantum;
   printf("enter quantum :");
   scanf("%d",&quantum);
   RR(process,  n,  bt,quantum);

    return 0;
}
    