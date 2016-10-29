#include<stdio.h>

struct node
{
    int data;
    struct node *next;
};
struct node *h= NULL;

void insert(int d)
{
    struct node *ptr;
    ptr = malloc(sizeof(struct node));
    if(h == NULL)
    {

        ptr->data = d;
        h = ptr;
        ptr->next = h;

    }
    else
    {
        struct node *t=h;
        ptr->data = d;
        ptr->next = h;

        while(t->next != h)
            t= t->next;
        t->next = ptr;
    }
}

void delete(int d)
{
    struct node *t = h,*t1;
    int f=0;

    if(h->data == d)
    {
        if(h -> next == h)
            h = NULL;
        else
        {
            t1=h;
            while (t1->next != h)
                t1 = t1->next;
            h = h->next;
            t1->next = h;
        }
        free (t);
        return;
    }
    t1=t;
    t = t->next;
    while(t != h)
    {
        if(t->data == d)
        {
            f=1;
            break;
        }
        t1 = t;
        t = t->next;
    }
    if(f==0)
        printf("no such element present\n" );
    else
    {
        t1 -> next = t->next;
        free(t);
    }
}
void display()
{
    struct node *t = h;
    if(h == NULL)
    {
        printf("empty list\n");
        return;
    }

    printf(" element is  %d ",t->data);
    t = t->next;

    while(t != h)
    {
        printf(" %d  ",t->data);
        t = t->next;
    }
}
void main()
{
    int c,da;
    do{
        printf("\n1 insert element\n2 delete element\n3 display \n4 exit" );
        scanf("%d",&c);
        switch (c)
        {
            case 1:printf("enter the value\n");
                        scanf("%d",&da);
                        insert(da);
                        break;
            case 2:printf("enter the element\n");
                        scanf("%d",&da);
                        delete(da);
                        break;
            case 3:display();
        }
    }while (c<4);
}
