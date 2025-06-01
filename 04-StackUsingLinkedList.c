#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data : ");
    if (scanf("%d", &newnode->data) != 1)
    {
        printf("Invalid input! \n");
        free(newnode);
        while (getchar() != '\n');

        return;
    }
    newnode->next = top;
    top = newnode;
    printf("%d pushed to stack\n", newnode->data);
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow!\n");
        return;
    }
    else
    {
        struct node *temp;
        temp = top;
        printf("popped element : %d\n", temp->data);
        top = top->next;
        free(temp);
    }
}

void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Top element : %d\n", top->data);
    }
}
void display()
{
    if (top == NULL)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack elements (Top to Bottom):\n");

        // Create a temporary pointer to traverse the list
        for (struct node *temp = top; temp != NULL; temp = temp->next)
        {
            printf("  %d\n", temp->data);
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
            while (getchar() != '\n');
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
            printf("Invalid input!\n");
        }
    }
}
