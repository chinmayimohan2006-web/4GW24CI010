#include<stdio.h>
#define MAXPROCESS 10
#define MAXRESOURCE 10

int np,nr;
int process[MAXPROCESS],resource[MAXRESOURCE];
int work[MAXRESOURCE];
int max[MAXPROCESS][MAXRESOURCE];
int alloted[MAXPROCESS][MAXRESOURCE];
int need[MAXPROCESS][MAXRESOURCE];

void safecheck()
{
    int finish[MAXPROCESS] = {0};
    int safeSeq[MAXPROCESS];
    
    for(int i = 0; i < nr; i++)
        work[i] = resource[i];

    int count = 0;

    while(count < np)
    {
        int found = 0;

        for(int i = 0; i < np; i++)
        {
            if(finish[i] == 0)
            {
                int j;
                for(j = 0; j < nr; j++)
                {
                    if(need[i][j] > work[j])
                        break;
                }

                
                if(j == nr)
                {
                    for(int k = 0; k < nr; k++)
                        work[k] = work[k] + alloted[i][k];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

       
        if(found == 0)
        {
            printf("\nSystem is NOT in safe state\n");
            return;
        }
    }

   
    printf("\nSystem is in SAFE state\nSafe sequence: ");
    for(int i = 0; i < np; i++)
        printf("P%d ", safeSeq[i]);
}



int main()
{
    printf("enter the number of process:");
    scanf("%d",&np);
    printf("enter the number of reosurces:");
    scanf("%d",&nr);
    printf("enter the available resouce:");
    for(int i=0;i<nr;i++)
    {
        printf("available resource%d:",(i+1));
        scanf("%d",&resource[i]);
    }
    printf("enter the maximum resource of each process:\n");
    for(int i=0;i<np;i++)
    {
        printf("process%d\n",(i+1));
        for(int j=0;j<nr;j++)
        {
            
            printf("resource%d : ",(j+1));
            scanf("%d",&max[i][j]);
        }
    }

    printf("enter the allocated  resources:");
    for(int i=0;i<np;i++)
    {
        printf("process%d\n",(i+1));
        for(int j=0;j<nr;j++)
        {
            printf("resource%d : ",(j+1));
            scanf("%d",&alloted[i][j]);
           
        }
    }

    printf("processes:");
    for(int i=0;i<np;i++)
    {
        printf("%d ",(i+1));
    }
    printf("\n");
    printf("allocated:");
        for(int i=0;i<np;i++)
        {
            for(int j=0;j<nr;j++)
            {
            printf("%d ",alloted[i][j]);
            }
            printf("\n");
        }
        printf("\n");
     printf("Max:");
        for(int i=0;i<np;i++)
        {
            for(int j=0;j<nr;j++)
            {
            printf("%d ",max[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    
    
    printf("available:");
    for(int i=0;i<nr;i++)
    {
        printf("%d\t",resource[i]);
    }
    printf("\n");
    for(int i=0;i<np;i++)
    {
        for(int j=0;j<nr;j++)
        {
            need[i][j]=max[i][j]-alloted[i][j];
        }
    }
    printf("Need:");
    for(int i=0;i<np;i++)
    {
        for(int j=0;j<nr;j++)
        {
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
    safecheck();



}