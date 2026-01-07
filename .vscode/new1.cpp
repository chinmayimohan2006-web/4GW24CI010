#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Day {
    char *dayName;
    int date;
    char *activity;
};

void create(struct Day *day)
{
    day->dayName = (char *)malloc(20 * sizeof(char));
    day->activity = (char *)malloc(100 * sizeof(char));

    if (day->dayName == NULL || day->activity == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter the day name: ");
    scanf("%s", day->dayName);

    printf("Enter the date: ");
    scanf("%d", &day->date);

    getchar();  // clear newline left by scanf

    printf("Enter the activity: ");
    fgets(day->activity, 100, stdin);

    // remove trailing newline from fgets
    day->activity[strcspn(day->activity, "\n")] = '\0';
}

void read(struct Day *calendar, int size)
{
    for (int i = 0; i < size; i++) {
        printf("\nEnter details of Day %d\n", i + 1);
        create(&calendar[i]);
    }
}

void display(struct Day *calendar, int size)
{
    printf("\nWeekly Activity Details:\n");
    for (int i = 0; i < size; i++) {
        printf("\nDay %d", i + 1);
        printf("\nDay Name : %s", calendar[i].dayName);
        printf("\nDate     : %d", calendar[i].date);
        printf("\nActivity : %s\n", calendar[i].activity);
    }
}

void free_memory(struct Day *calendar, int size)
{
    for (int i = 0; i < size; i++) {
        free(calendar[i].dayName);
        free(calendar[i].activity);
    }
}

int main()
{
    int size;

    printf("Enter the number of days: ");
    scanf("%d", &size);

    struct Day *calendar = (struct Day *)malloc(size * sizeof(struct Day));
    if (calendar == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    read(calendar, size);
    display(calendar, size);

    free_memory(calendar, size);
    free(calendar);

    return 0;
}
