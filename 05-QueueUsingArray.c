#include <stdio.h>

#define MAX_SIZE 3
int queue[MAX_SIZE], front = -1, rear = -1;

void enqueue()
{
    if (rear == (MAX_SIZE - 1))
    {
        printf("Queue Overflow!\n");
        return;
    }
    int data;
    printf("Enter data: ");
    if (scanf("%d", &data) != 1)
    {
        printf("Invalid input!\n");
        while (getchar() != '\n')
            ;
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = data;
    printf("Enqueued: %d\n", data);
}
void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow!\n");
        return;
    }
    printf("Dequeued element : %d\n", queue[front]);
    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void peek()
{
    if (front == -1)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Front element : %d\n", queue[front]);
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Queue elements : \n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d | ", queue[i]);
        }
        printf("\n");
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n\nQueue Operations Menu:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number between 1 to 5.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
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
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
