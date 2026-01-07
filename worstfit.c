#include <stdio.h>

#define MAX_BLOCKS 100
#define MAX_PROCESS 50

int blocks[MAX_BLOCKS], process[MAX_PROCESS];
int m, n;

void worstFit()
{
    int allocation[MAX_PROCESS], i, j;

    for (i = 0; i < n; i++)
    {
        int worstIdx = -1;

        for (j = 0; j < m; j++)
        {
            if (blocks[j] >= process[i])
            {
                if (worstIdx == -1 || blocks[j] > blocks[worstIdx])
                    worstIdx = j;
            }
        }

        if (worstIdx != -1)
        {
            allocation[i] = worstIdx;
            blocks[worstIdx] -= process[i];
        }
        else
        {
            allocation[i] = -1;
        }
    }

    printf("\nWorst Fit Memory Allocation:\n");
    printf("Process No.\tProcess Size\tBlock No.\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, process[i]);

        if (allocation[i] != -1)
        {
            printf("%d\n", allocation[i] + 1);
        }
        else
        {
            printf("Not Allocated\n");
        }
    }
}

int main()
{
    int i;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter the memory blocks:\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &blocks[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the process sizes:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &process[i]);
    }

    worstFit();

    return 0;
}
