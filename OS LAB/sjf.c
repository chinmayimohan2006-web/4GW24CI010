#include<stdio.h>

int process[50];
    int n;
    int bt[50];

void calcWT_TAT(int wt[n],int tat[n],int bt[n])
{
    wt[0]=0;
    for(int i=1;i<n;i++)
    {
       wt[i]=wt[i-1]+bt[i-1];
    }
    for(int i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
    }
}
void SJF(int process[], int n, int bt[])
{
    int wt[n],tat[n];
    int temp_bt[n],temp_process[n];
    for(int i=0;i<n;i++)
    {
        temp_bt[i]=bt[i];
        temp_process[i]=process[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(temp_bt[i]>temp_bt[j])
            {
                int temp=temp_bt[i];
                temp_bt[i]=temp_bt[j];
                temp_bt[j]=temp;
                temp=temp_process[i];
                temp_process[i]=temp_process[j];
                temp_process[j]=temp;
            }
        }
    }
    calcWT_TAT (wt,tat,temp_bt);
    printf("-------------SJF Algorithm------------\n");
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
    
    printf("--------------------------------");



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
   SJF(process,  n,  bt);
}