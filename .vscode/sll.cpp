#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student{
    char usn[20];
    char name[30];
    char program[20];
    int sem;
    char phno[20];
    struct Student *next;
};

struct Student *head = NULL;

struct Student* createnode(){
    struct Student *newNode= (struct Student *)malloc(sizeof(struct Student));

    printf("USN: ");
    scanf("%s",newNode->usn);
    printf("name: ");
    scanf("%s",newNode->name);
    printf("Program: ");
    scanf("%s",newNode->program);
    printf("SEM: ");
    scanf("%s",newNode->sem);
    printf("PhoneNumber: ");
    scanf("%s",newNode->phno);

    newNode->next=NULL;
    return newNode; 
}

void createList(int n){
    for(int i=0;i<n;i++){
        struct Student *newNode=createnode();
        newNode->next=head;
        head= newNode;

    }
}

void displayList(){
    struct Student *temp=head;
    int count =0;

    if(temp==NULL){
        printf("List is empty.\n");
        return;
    }

    while(temp!=NULL){
        printf("USN:%s,Name:%s,program:%s,sem:%d,Phno:%s\n",temp->usn,temp->name,temp->program,temp->sem,temp->phno);
        temp=temp->next;
        count++;
    }
    printf("Total number of students:%d\n",count);
}
void insertEnd(){
    struct Student *newNode= createnode();
    if (head==NULL){
        head=newNode;
        return;
    }
    struct Student *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newNode;
}