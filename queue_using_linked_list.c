#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* ptr;
};

struct node* rear = NULL;
struct node* front = NULL;
struct node* new1;
struct node* temp;

void insert() {
    int n;
    printf("Enter your element: ");
    scanf("%d", &n);
    new1 = (struct node*)malloc(sizeof(struct node));
    new1->data = n;
    new1->ptr = NULL;
    if (rear == NULL && front == NULL) {
        rear = front = new1;
    } else {
        rear->ptr = new1;
        rear = new1;
    }
}

void display() {
    temp = front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->ptr;
    }
    printf("NULL\n");
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        temp = front;
        front = front->ptr;
        free(temp);
        if (front == NULL) {
            rear = NULL;
        }
    }
}

int main() {
    int a;
    do {
        printf("....Enter your operation...\n");
        printf("Insert an element at rear end, press 1\n");
        printf("Delete an element from front end, press 2\n");
        printf("Display the queue, press 3\n");
        scanf("%d", &a);
        switch (a) {
            case 1:
                insert();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            default:
                printf(".....Exits....\n");
                break;
        }
    } while (a > 0 && a < 4);
    return 0;
}
