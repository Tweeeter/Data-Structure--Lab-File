#include <stdio.h>

#define MAX_SIZE 5 // Defines the maximum size of the circular queue
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Function to add an element to the circular queue
void enqueue() {
    int data;
    // Check if the queue is full
    if ((rear + 1) % MAX_SIZE == front) {
        printf("Queue Overflow!\n");
        return;
    }
    printf("Enter data: ");
    if (scanf("%d", &data) != 1) {
        printf("Invalid input!\n");
        // Clear the input buffer
        while (getchar() != '\n');
        return;
    }
    if (front == -1) { // If queue is initially empty
        front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = data;
    printf("Enqueued: %d\n", data);
}

// Function to remove an element from the circular queue
void dequeue() {
    // Check if the queue is empty
    if (front == -1) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("Dequeued element : %d\n", queue[front]);
    if (front == rear) { // If queue has only one element, reset to empty
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
}

// Function to get the front element of the queue without removing it
void peek() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element : %d\n", queue[front]);
    }
}

// Function to display the elements of the circular queue
void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements : \n");
    int i = front;
    while (1) {
        printf("%d | ", queue[i]);
        if (i == rear) { // Last element reached
            break;
        }
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n\nCircular Queue Operations Menu:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 to 5.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
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
    return 0; // Technically unreachable due to while(1) and exit in case 5
}

