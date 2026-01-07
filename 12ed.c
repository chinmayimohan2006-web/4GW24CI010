#include <stdio.h>

#define MAXP 10
#define MAXR 10

int np, nr;
int available[MAXR];
int max[MAXP][MAXR];
int alloc[MAXP][MAXR];
int need[MAXP][MAXR];

void bankersAlgorithm()
{
    int work[MAXR];
    int finish[MAXP] = {0};
    int safeSeq[MAXP];
    int count = 0;

    // Step 1: Initialize work = available
    for (int i = 0; i < nr; i++)
        work[i] = available[i];

    // Step 2: Find safe sequence
    while (count < np)
    {
        int found = 0;

        for (int i = 0; i < np; i++)
        {
            if (finish[i] == 0)
            {
                int j;
                for (j = 0; j < nr; j++)
                {
                    if (need[i][j] > work[j])
                        break;
                }

                // If all resources can be allocated
                if (j == nr)
                {
                    for (int k = 0; k < nr; k++)
                        work[k] += alloc[i][k];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        // If no process can be allocated
        if (!found)
        {
            printf("\n❌ System is NOT in Safe State\n");
            return;
        }
    }

    // Step 3: Print Safe Sequence
    printf("\n✅ System is in SAFE State\n");
    printf("Safe Sequence: ");
    for (int i = 0; i < np; i++)
        printf("P%d ", safeSeq[i]);
}

int main()
{
    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter number of resources: ");
    scanf("%d", &nr);

    printf("\nEnter Available Resources:\n");
    for (int i = 0; i < nr; i++)
        scanf("%d", &available[i]);

    printf("\nEnter Maximum Requirement Matrix:\n");
    for (int i = 0; i < np; i++)
    {
        printf("Process P%d: ", i);
        for (int j = 0; j < nr; j++)
            scanf("%d", &max[i][j]);
    }

    printf("\nEnter Allocation Matrix:\n");
    for (int i = 0; i < np; i++)
    {
        printf("Process P%d: ", i);
        for (int j = 0; j < nr; j++)
            scanf("%d", &alloc[i][j]);
    }

    // Calculate Need = Max - Allocation
    for (int i = 0; i < np; i++)
        for (int j = 0; j < nr; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    printf("\nNeed Matrix:\n");
    for (int i = 0; i < np; i++)
    {
        for (int j = 0; j < nr; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    bankersAlgorithm();
    return 0;
}
