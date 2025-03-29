#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5
int stack[MAX_SIZE], top = -1;

void push()
{
    if (top == (MAX_SIZE - 1))
    {
        printf("Stack Overflow! \n");
        return;
    }

    printf("Enter data: ");
    if (scanf("%d", &stack[++top]) != 1) // '!= 1' Check if scanf has failed to read integer
    {
        printf("Invalid input! \n");
        top--;
        while (getchar() != '\n')
            return;
    }
    printf("Pushed %d onto the stack.\n", stack[top]);
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! \n");
    }
    else
    {
        printf("Popped element: %d \n", stack[top]);
        top--;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty! \n");
    }
    else
    {
        printf("Top element: %d \n", stack[top]);
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty! \n");
    }
    else
    {
        printf("Stack elements (Top to Bottom):\n");
        for (int i = top; i >= 0; i--)
        {
            printf("  %d\n", stack[i]);
        }
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n\nStack Operations Menu:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! \n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice! \n");
        }
    }
}
