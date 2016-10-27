#include<iostream>
#include<stdlib.h>
 
using namespace std;


struct node
{
    struct node *prev;
    struct node *next;
    int n;
};

node *root = NULL;

struct node *initialise(struct node *root,int val)
{
    struct node *temp;
    temp=new struct node;
    temp->n=val;
    temp->prev=NULL;
    temp->next=NULL;
    root=temp;
    return root;
}
struct node *add_begin(struct node *root,int val)
{
    if(root==NULL)
    {
        cout<<"List is empty\n";
        return root;
    }
    
    struct node *temp;
    temp = new struct node;
    temp->n=val;
    temp->prev=NULL;
    temp->next=root;
    root->prev=temp;
    root=temp;
    return root;
}
 
struct node *add_end(struct node *root,int val)
{
    if(root==NULL)
    {
        cout<<"List is empty\n";
        return root;
    }
    
    struct node *temp,*p;
    temp=new struct node;
    temp->n=val;
    p=root;
    while(p->next!=NULL)
        p=p->next;
    p->next=temp;
    temp->next=NULL;
    temp->prev=p;
    return root;
}
struct node *post_element(struct node *root,int val,int item_pos)
{
    struct node *temp,*p;
    temp=new struct node;
    temp->n=val;
    p=root;
    while(p!=NULL)
    {
        if(p->n==item_pos)
        {
            temp->prev=p;
            temp->next=p->next;
            if(p->next!=NULL) 
                p->next->prev=temp;
            p->next=temp;
            return root;    
        }
        p=p->next;
    }
    cout<<item_pos<<" not present in the list\n\n";
    return root;
}
 
struct node *pre_element(struct node *root,int val,int item_pos)
{
    struct node *temp,*q;
    if(root==NULL )
    {
        cout<<"List is empty\n";
        return root;
    }
    if(root->n==item_pos)
    {
        temp = new struct node;
        temp->n=val;
        temp->prev=NULL;
        temp->next=root;
        root->prev=temp;
        root=temp;
        return root;
    }
    q=root;
    while(q!=NULL)
    {
        if(q->n==item_pos)
        {
            temp=new struct node;
            temp->n=val;
            temp->prev=q->prev;
            temp->next = q;
            q->prev->next=temp;
            q->prev=temp;
            return root;
        }    
        q=q->next;
    }
    cout<<item_pos<<" not present in the list\n";
    return root;
}    
 
struct node *create_list(node *root)
{
    int i,n,val;
    cout<<"Enter the number of nodes : ";
    cin>>n;
    root=NULL;
    if(n==0)
        return root;
    cout<<"Enter the element: ";
    cin>>val;
    root=initialise(root,val);
        
    for(i=2;i<=n;i++)
    {
        cout<<"Enter the element to be inserted : ";
        cin>>val;
        root=add_end(root,val);    
    }
    return root;
}
 
void display(struct node *root)
{
    struct node *p;
    if(root==NULL)
    {
        cout<<"List is empty\n";
        return;
    }
    p=root;
    cout<<"List is :\n";
    while(p!=NULL)
    {
        cout<<p->n<<" ";
        p=p->next;
    }
    cout<<"\n";
}

struct node *deletenode(struct node *root,int val)
{
    struct node *temp;
    if(root==NULL)
    {
        cout<<"Empty\n";
        return root;
    }
    if(root->next==NULL)    
        if(root->n==val) 
        {
            temp=root;
            root=NULL;
            delete(temp);
            return root;
        }
        else
        {
            cout<<"Element "<<val<<" not found\n";
            return root;
        }
    
    if(root->n==val)
    {
        temp=root;
        root=root->next;  
        root->prev=NULL;
        delete(temp);
        return root;
    }
 
    temp=root->next;
    while(temp->next!=NULL )
    {
        if(temp->n==val)     
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete(temp);
            return root;
        }
        temp=temp->next;
    }
 
    if(temp->n==val)
    {
        temp->prev->next=NULL;
        delete(temp);
        return root;
    }
    cout<<"Element "<<val<<" not found\n";
    return root;
}
 
struct node *reverselist(struct node *root)
{
    if(root==NULL)
    {
        cout<<"List is empty\n";
        return root;
    }
    
    struct node *p1,*p2;
    p1=root;
    p2=p1->next;
    p1->next=NULL;
    p1->prev=p2;
    while(p2!=NULL)
    {
        p2->prev=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p2->prev; 
    }
    root=p1;
    cout<<"List reverselistd\n";
    return root;
}

 
 
int main()
{
    int option,val,item_pos;

    while(1)
    {	
    	cout<<endl;
        cout<<"1.Create a new doubly linked list\n";
        cout<<"2.Display list\n";
        cout<<"3.Initialise list with a single element\n";
        cout<<"4.Add element in the begining\n";
        cout<<"5.Add element in the end\n";
        cout<<"6.Add element after a node\n";
        cout<<"7.Add element before a node\n";
        cout<<"8.Delete a node\n";
        cout<<"9.Reverse the list\n";
        cout<<"10.Exit\n";
        cout<<"Enter your option : ";
        cin>>option;
        
        switch(option)
        {
         case 1:
            root=create_list(root);
            break;
         case 2:
            display(root);
            break;
         case 3:
            cout<<"Enter the element:";
            cin>>val;
            root=initialise(root,val);
            break;
         case 4:
                cout<<"Enter the element:";
            cin>>val;
            root=add_begin(root,val);
            break;
         case 5: 
            cout<<"Enter the element:";
            cin>>val;
            root=add_end(root,val);
            break;
         case 6:
            cout<<"Enter the element:";
            cin>>val;
            cout<<"Enter the element after which to insert : ";
            cin>>item_pos;
            root=post_element(root,val,item_pos);
            break;
         case 7:
            cout<<"Enter the element: ";
            cin>>val;
            cout<<"Enter the element before which to insert : ";
            cin>>item_pos;
            root=pre_element(root,val,item_pos);
            break;
         case 8:
            cout<<"Enter the element to be Deleted : ";
            cin>>val;
            root=deletenode(root,val);
               break;
         case 9:
             root=reverselist(root);
            break;
         case 10:
            exit(1);
         default:
            cout<<"Wrong option\n";
    }
   }
   
   return 0;
}