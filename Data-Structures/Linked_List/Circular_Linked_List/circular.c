
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insert_beg_of_list(Node *current, int data);
void delete(Node *current, int data);
void print_list(Node *current);
int find_in_a_list(Node *current, int data);

void insert_beg_of_list(Node *current, int data) {
    //keep track of first node
    Node *head = current;

    while(current->next != head) {
        current = current->next;
    }
    current->next = (Node*)malloc(sizeof(Node));
    current = current->next;
    current->data = data;
    current->next = head;

}

void delete_from_list(Node *current, int data) {

    Node *head = current;
    while(current->next != head && (current->next)->data != data) {
        current = current->next;
    }
    if(current->next == head) {
        printf("%d element is not found\n\n", data);
        return;
    }
    Node *tmp;
    tmp = current->next;
    current->next = tmp->next;
    free(tmp);  
    return;
}

void print_list(Node *current) {

    Node *head = current;
    current = current->next;
    while(current != head){
        printf(" %d ", current->data);
        current = current->next;
    }

}

int find_in_a_list(Node *current, int data) {

    Node *head = current;
    current = current->next;
    while(current != head) {
        if(current->data == data) {
            // Key found
            return 1;
        }
        current = current->next;
    }
    // Key is not found
    return 0;
}

int main() {

    Node *head = (Node *)malloc(sizeof(Node));
    head->next = head;  

    int data = 0;
    int usr_input = 0;

    while(1){
        printf("0. Exit\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print\n");
        printf("4. Find\n");


        scanf("%d", &usr_input);

        // can also use a switch instead
        if( usr_input == 0) {
            exit(0);

        } else if(usr_input == 1) {
            printf("\nEnter an element you want to insert: ");
            scanf("%d", &data);
            insert_beg_of_list(head, data);

        } else if(usr_input == 2) {
            printf("\nEnter an element you want to delete: ");
            scanf("%d", &data);
            delete_from_list(head, data);

        } else if( usr_input == 3) {
            printf("The list is ");
            print_list(head);
            printf("\n\n");

        } else if( usr_input == 4) {
            printf("\nEnter an element you want to find: ");
            scanf("%d", &data);
            int is_found = find_in_a_list(head, data);
            if (is_found) {
                printf("\nElement is found\n\n");
            } else {
                printf("\nElement is NOT found\n\n");
            }
        }
    }
    return 0;
}
