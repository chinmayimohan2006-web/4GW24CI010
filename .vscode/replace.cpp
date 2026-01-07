#include<stdio.h>
#include<stdlib.h>

struct Day{
    char *dayName;
    int date;
    char *activity;
};

void create(struct Day *day)
{
    day->dayName=(char*)malloc(sizeof(char*)*20);
    day->activity=(char*)malloc(sizeof(char*)*100);
    printf("enter the day name: \n");
    scanf("%s",day->dayName);
    printf("Enter the date: \n");
    scanf("%d",&day->date);
    printf("Enter the activity: \n");
    scanf("%s",day->activity);
}

void read(struct Day *calander,int size){
    for(int i=0;i<size;i++){
        printf("Enter the details of %d\n",i+1);
        create(&calander[i]);
        }

}

void display(struct Day *calander,int size){
    printf("Weeks activity details: \n");
    for(int i=0;i<size;i++){
        printf("Day:%d\n",i+1);
        printf("dayname=%s \n",calander[i].dayName);
        printf("date=%d \n",calander[i].date);
        printf("ativity=%s \n",calander[i].activity);
        printf("\n");

    }
}
void free_memory(struct Day *calander,int size){
    for(int i=0;i<size;i++){
        free(calander[i].activity);
        free(calander[i].dayName);
        
    }

}
int main()
{
    int size;
    printf("Enter the number of days: ");
    scanf("%d",&size);
    struct Day *calander=(struct Day*)malloc(sizeof(struct Day)*size);
    
    if(calander==NULL)
    {
        printf("memory failed");
        return 1;
    }
    read(calander,size);
    display(calander,size);
    free_memory(calander,size);
    free(calander);
    return 0;
    
}