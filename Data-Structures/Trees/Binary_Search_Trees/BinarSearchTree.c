#include <stdio.h>
#include <stdlib.h>
int flag=-1;
struct node
{
  int val;
  struct node* lt;
  struct node* rt;
}*root=NULL,*temp=NULL,*t2,*t1;

void create()
{
  int num;
  printf("enter the data for the node");
  scanf("%d",&num);
  temp=(struct node*)malloc(sizeof(struct node*));
  temp->val=num;
  temp->lt=NULL;
  temp->rt=NULL;
}

int smallst(struct node* t)
{
  t2=t;
  if(t->lt!=NULL)
  {
    t2=t;
    return(smallst(t->lt));
  }
  else
  return (t->val);
}

int largst(struct node* t)
{
  if(t->rt!=NULL)
  {
    t2=t;
    return(largst(t->rt));
  }
  else
  return (t->val);
}

void preordr(struct node* t)
{
  if(root==NULL)
  {printf("No element is found!!");
  return;
  }
  printf("%d->",t->val);
  if(t->lt!=NULL)
    preordr(t->lt);
  if(t->rt!=NULL)
    preordr(t->rt);
}

void search(struct node *t)
{
  if ((temp->val>t->val)&&(t->rt!=NULL))
    search(t->rt);
  else if((temp->val>t->val)&&(t->rt==NULL))
    t->rt=temp;
  else if ((temp->val<t->val)&&(t->lt!=NULL))
    search(t->lt);
  else if((temp->val<t->val)&&(t->lt==NULL))
    t->rt=temp;
}

void deletel(struct node* t);

void searchl(struct node* t,int num)
{
  if(num>t->val)
  {
    t1=t;
    searchl(t->rt,num);
  }
  else if(num<t->val)
  {
    t1=t;
    searchl(t->lt,num);
  }
  else if(num==t->val)
  {
    deletel(t);
  }
}

void deletel(struct node* t)
{
  int k;
  if ((t->lt==NULL)&&(t->rt==NULL))
  {
    if(t1->lt==t)
      t1->lt=NULL;
    else
      t1->rt=NULL;
    t=NULL;
    free(t);
    /* code */
  }
  else if ((t->rt==NULL))
  {
    if(t1==t)
    {
      root=t->lt;
      t1=root;
    }
    else if(t1->lt==t)
      t1->lt=t->lt;
    else
      t1->rt=t->lt;
    t=NULL;
    free(t);
    /* code */
  }
  else if ((t->lt==NULL))
  {
    if(t1==t)
    {
      root=t->rt;
      t1=root;
    }
    else if(t1->rt==t)
      t1->rt=t->rt;
    else
      t1->lt=t->rt;
    t=NULL;
    free(t);
    /* code */
  }
  else if ((t->lt!=NULL)&&(t->rt!=NULL))
  {
    t2=root;
    if(t->rt!=NULL)
    {
      k=smallst(t->rt);
      flag=1;
    }
    else
    {
      k=largst(t->lt);
      flag=2;
    }
    searchl(root,k);
    t->val=k;
    /* code */
  }
}

void insert()
{
  create();
  if(root==NULL)
  {
    root=temp;
  }
  else
    search(root);
}

void srchr(struct node* t,int num)
{
  if(root==NULL)
  {printf("No element is found!!");
  return;
  }
  if(t->val==num)
  {printf("the number is a part of the BST tree!!");
    return;
  }
  if(t->lt!=NULL)
    preordr(t->lt);
  if(t->rt!=NULL)
    preordr(t->rt);
}

void delete()
{
  int num;
  if(root==NULL)
  {printf("No element is found!!");
  return;
  }
  printf("enter the element to be deleted:\n");
  scanf("%d",&num);
  t1=root;
  t2=root;
  searchl(root,num);
}

int main()
{
  int num,ch;
  do
  {
    printf("###Array implementation of a binary TREE###\n1.insert an element into the TREE\n2.delete a node from the TREE\n3.dispaly the nodes in the TREE\n4.search the nodes in the TREE\n5.exit\nENTER A ValID CHOICE TO PROCEED");
    scanf("%d",&ch);
    switch (ch) {
      case 1:insert();
      break;
      case 2:delete();
      break;
      case 3:preordr(root);
      break;
      case 4:
        {
          printf("enter the data for the node");
          scanf("%d",&num);
          srchr(root,num);
        }
      break;
      case 5:
      {
        printf("\n\nAdios!\n\n");
        exit(0);
      }
      break;
    }
    /* code */
  } while(ch!=5);
}
