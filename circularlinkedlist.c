#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL, *end = NULL, *temp, *prev, *post;

void create() {
    int data, a;
    printf("Enter your data: ");
    scanf("%d", &data);
    start = (struct node*)malloc(sizeof(struct node));
    start->data = data;
    start->next = start; // Initialize the first node to point to itself
    end = start; // End points to the first node initially
    printf("If you want to continue insertion, press 1 (or 0 to stop): ");
    scanf("%d", &a);
    while (a != 0) {
        printf("Enter your data: ");
        scanf("%d", &data);
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = data;
        temp->next = start;
        end->next = temp;
        end = temp;
        printf("If you want to continue insertion, press 1 (or 0 to stop): ");
        scanf("%d", &a);
    }
}

void insert_at_first() {
    int data;
    printf("Enter your data: ");
    scanf("%d", &data);
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = start;
    start = temp;
    end->next = start;
}

void insert_at_last() {
    int data;
    printf("Enter your data: ");
    scanf("%d", &data);
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = start;
    end->next = temp;
    end = temp;
}

void insert_at_middle() {
    int data, a, i = 1;
    printf("Enter your data: ");
    scanf("%d", &data);
    printf("Enter the position where you want to insert the element: ");
    scanf("%d", &a);
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    prev = start;
    while (i < a - 1 && prev->next != start) {
        prev = prev->next;
        i++;
    }
    temp->next = prev->next;
    prev->next = temp;
}

void delete_at_first() {
    if (start == NULL) {
        printf("List not found\n");
    } else {
        temp = start;
        start = start->next;
        end->next = start;
        free(temp);
    }
}

void delete_at_last() {
    if (start == NULL) {
        printf("List not found\n");
    } else {
        temp = start;
        while (temp->next != end) {
            temp = temp->next;
        }
        temp->next = start;
        free(end);
        end = temp;
    }
}

void delete_at_middle() {
    if (start == NULL) {
        printf("List not found\n");
    } else {
        int pos, i = 1;
        printf("Enter the position: ");
        scanf("%d", &pos);
        temp = start;
        while (i < pos - 1 && temp->next != start) {
            temp = temp->next;
            i++;
        }
        post = temp->next;
        temp->next = post->next;
        free(post);
    }
}

void display() {
    if (start == NULL) {
        printf("List not found\n");
    } else {
        temp = start;
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != start);
        printf("%d (start)\n", start->data); // To show the circular nature
    }
}

int main() {
    int a;
    do {
        printf("1. Create a node\n");
        printf("2. Insert an element at the first position\n");
        printf("3. Insert an element at the last position\n");
        printf("4. Insert an element at the middle position\n");
        printf("5. Delete an element at the first position\n");
        printf("6. Delete an element at the last position\n");
        printf("7. Delete an element at the middle position\n");
        printf("8. Display the linked list\n");
        printf("9. Exit the menu\n");
        printf("Enter your choice: ");
        scanf("%d", &a);
        switch (a) {
            case 1:
                create();
                break;
            case 2:
                insert_at_first();
                break;
            case 3:
                insert_at_last();
                break;
            case 4:
                insert_at_middle();
                break;
            case 5:
                delete_at_first();
                break;
            case 6:
                delete_at_last();
                break;
            case 7:
                delete_at_middle();
                break;
            case 8:
                display();
                break;
            default:
                printf("Exiting...\n");
                break;
        }
    } while (a > 0 && a < 9);

    return 0;
}
