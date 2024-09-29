#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *start = NULL, *end = NULL, *temp = NULL, *prev = NULL;

void create() {
    int data, a;
    printf("Enter your data: ");
    scanf("%d", &data);
    start = (struct node*)malloc(sizeof(struct node));
    start->data = data;
    start->next = NULL;
    start->prev = NULL;
    end = start;
    printf("If you want to continue insertion, enter 1 (or 0 to stop): ");
    scanf("%d", &a);
    while (a != 0) {
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter your data: ");
        scanf("%d", &data);
        temp->data = data;
        temp->next = start;
        temp->prev = NULL;
        start->prev = temp;
        start = temp;
        printf("If you want to continue insertion, enter 1 (or 0 to stop): ");
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
    temp->prev = NULL;
    if (start != NULL) {
        start->prev = temp;
    }
    start = temp;
    if (end == NULL) {
        end = start;
    }
}

void insert_at_last() {
    int data;
    printf("Enter your data: ");
    scanf("%d", &data);
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = end;
    if (end != NULL) {
        end->next = temp;
    }
    end = temp;
    if (start == NULL) {
        start = end;
    }
}

void insert_at_middle() {
    int data, a, i = 1;
    printf("Enter your data: ");
    scanf("%d", &data);
    printf("Enter the position where you want to insert the element: ");
    scanf("%d", &a);
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    end = start;
    while (i < a - 1 && end != NULL) {
        end = end->next;
        i++;
    }
    if (end != NULL) {
        temp->next = end->next;
        temp->prev = end;
        if (end->next != NULL) {
            end->next->prev = temp;
        }
        end->next = temp;
    } else {
        printf("Position out of range\n");
    }
}

void delete_at_first() {
    if (start == NULL) {
        printf("List not found\n");
    } else {
        temp = start;
        start = start->next;
        if (start != NULL) {
            start->prev = NULL;
        } else {
            end = NULL;
        }
        free(temp);
    }
}

void delete_at_last() {
    if (end == NULL) {
        printf("List not found\n");
    } else {
        temp = end;
        end = end->prev;
        if (end != NULL) {
            end->next = NULL;
        } else {
            start = NULL;
        }
        free(temp);
    }
}

void delete_at_middle() {
    int pos, i = 1;
    printf("Enter the position: ");
    scanf("%d", &pos);
    if (start == NULL) {
        printf("List not found\n");
    } else {
        end = start;
        while (i < pos && end != NULL) {
            prev = end;
            end = end->next;
            i++;
        }
        if (end != NULL) {
            prev->next = end->next;
            if (end->next != NULL) {
                end->next->prev = prev;
            }
            free(end);
        } else {
            printf("Position out of range\n");
        }
    }
}

void display() {
    end = start;
    if (start == NULL) {
        printf("List not found\n");
    } else {
        while (end != NULL) {
            printf("%d -> ", end->data);
            end = end->next;
        }
        printf("NULL\n");
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
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (a != 9);

    return 0;
}
