#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
};

struct node *header, *ptr, *temp; 

int insert_pos(int data,int position, node **head) {
    assert(position >= 1);
    node* new_node=(node*)malloc(sizeof(node));
    new_node->data=data;
    new_node->link=NULL;
    if(position==1) {
        new_node->link=*head;
        *head=new_node;
        return 0;
    }

    node *p = *head, *k;
    int i;
    for(i = 1 ; i < position && p!=NULL ; i++){
        k = p;
        p = p->link;
    }

    if(i >= position) {
        k->link=new_node;
        return 0;
    }
    return 1;
}
 
int delete_pos(int position, node **head) {
    assert(head && position>=1);
    node *q;
    if(position==1) {
        q=*head;
        *head=(*head)->link;
        free(q);
        return 0;
    }
    
    node*p=*head,*k;int i;
    
    for(i = 1 ; i < position && p!=NULL ; i++) {
        k = p;
        p = p->link;
    }
    if(i >= position && k->link != NULL) {
        q=k->link;
        k->link=k->link->link;

        free(q);
        return 0;
    }
    return 1;
}

void display() {
    printf("\nContents of the linked list are: \n");
    ptr = header;
    while(ptr->link != NULL) {
        ptr = ptr->link;
        printf("%d ", ptr->data);
    }
}

void main() {
    int choice;
    int cont = 1;

    header = (struct node *) malloc(sizeof(struct node));

    header->data = NULL;
    header->link = NULL;

    display();
}