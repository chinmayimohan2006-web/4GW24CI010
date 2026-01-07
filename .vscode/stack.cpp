#include <stdio.h>
#include <string.h>

#define MAX 5

int stack[MAX];
int top = -1;

/* Function declarations */
void push(int);
int pop();
void display();
void checkPalindrome();
void isOverflow();
void isUnderflow();

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n---- STACK MENU ----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Palindrome\n");
        printf("4. Overflow / Underflow\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                value = pop();
                if (value != -1)
                    printf("Value popped: %d\n", value);
                break;

            case 3:
                checkPalindrome();
                break;

            case 4:
                isOverflow();
                isUnderflow();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

/* Push operation */
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow! Cannot push.\n");
        return;
    }
    stack[++top] = value;
    printf("%d pushed\n", value);
}

/* Pop operation */
int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! Stack is empty.\n");
        return -1;
    }
    return stack[top--];
}

/* Display stack */
void display()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements are:\n");
    for (int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}

/* Palindrome check using stack */
void checkPalindrome()
{
    char str[50], rev[50], tempStack[50];
    int i, len, tempTop = -1;

    printf("Enter the string: ");
    scanf("%s", str);

    len = strlen(str);

    /* Push characters onto temporary stack */
    for (i = 0; i < len; i++)
        tempStack[++tempTop] = str[i];

    /* Pop characters to form reverse string */
    for (i = 0; i < len; i++)
        rev[i] = tempStack[tempTop--];

    rev[i] = '\0';

    if (strcmp(str, rev) == 0)
        printf("It is a palindrome.\n");
    else
        printf("It is not a palindrome.\n");
}

/* Overflow check */
void isOverflow()
{
    if (top == MAX - 1)
        printf("Overflow occurs! Stack is full.\n");
    else
        printf("No overflow. Stack is not full.\n");
}

/* Underflow check */
void isUnderflow()
{
    if (top == -1)
        printf("Underflow occurs! Stack is empty.\n");
    else
        printf("No underflow. Stack is not empty.\n");
}
