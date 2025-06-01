#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

// Function to add an element to the circular queue
void enqueue() {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data: ");
    if (scanf("%d", &newnode->data) != 1) {
        printf("Invalid input! \n");
        free(newnode);
        // Clear the input buffer
        while (getchar() != '\n');
        return;
    }
    newnode->next = NULL;

    if (rear == NULL) { // If queue is initially empty
        front = rear = newnode;
        rear->next = front; // Circular link
    } else {
        rear->next = newnode;
        rear = newnode;
        rear->next = front; // Maintain circular link
    }
    printf("Enqueued: %d\n", newnode->data);
}

// Function to remove an element from the circular queue
void dequeue() {
    struct node *temp;
    if (front == NULL) { // If queue is empty
        printf("Queue Underflow!\n");
        return;
    }

    temp = front;
    printf("Dequeued element : %d\n", front->data);

    if (front == rear) { // If queue has only one element
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front; // Maintain circular link
    }
    free(temp);
}

// Function to get the front element of the queue without removing it
void peek() {
    if (front == NULL) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element : %d\n", front->data);
    }
}

// Function to display the elements of the circular queue
void display() {
    struct node *temp;
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements : \n");
    temp = front;
    do {
        printf("%d | ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n\nCircular Queue (Linked List) Operations Menu:\n");
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
                // Free all nodes before exiting to prevent memory leaks
                if (front != NULL) {
                    struct node *current = front;
                    rear->next = NULL; // Break the circular link for easy traversal
                    while (current != NULL) {
                        struct node *nextNode = current->next;
                        free(current);
                        current = nextNode;
                    }
                    front = rear = NULL;
                }
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0; 
}

