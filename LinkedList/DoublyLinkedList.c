#include <stdio.h>
#include<stdlib.h>
typedef struct Doubly
{
        int val;
        struct Doubly *next;
        struct Doubly *prev;
}db;

void create(db**,db**);
db *insert_at_beg(db *,int );
db *insert_at_end(db *,int );
db *insert_after(db *,int ,int);
db *insert_before(db *,int ,int);
db *delete_at_beg(db **);
db *delete_at_end(db **);
db *delete_intermediate(db **,int );
void fwddisp(db*);
void bckdisp(db*);

int main()
{
       db *h;
        int v,choice,p;
        db *head=NULL,*tail=NULL;
        while(1)
        {
            printf("\n 1. Create a doubly linked list\n 2. Insert at beginning\n 3. Insert at end\n 4. Insert after a certain node\n 5. Insert before a certain node\n 6. To delete from beginning\n 7. To delete from end\n 8. To delete intermediate node\n 9. Forward display starting from head\n 10. Backward display starting from tail\n 11. Exit");
    		printf("\n Enter your choice : ");
    		scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                   create(&head,&tail);
                    break;
                case 2:
                    printf("\n Enter the value u want to insert : ");
                    scanf("%d",&v);
                    head=insert_at_beg(head,v);
                    break;
                case 3:
                    printf("\n Enter the value u want to insert : ");
                    scanf("%d",&v);
                    insert_at_end(tail,v);
                    break;
                case 4:
                    printf("\n Enter the value u want to insert : ");
                    scanf("%d",&v);
                    printf("\n Enter the no. after which u want to insert the value : ");
                    scanf("%d",&p);
                    insert_after(head,v,p);
                    break;
                case 5:
                    printf("\n Enter the value u want to insert : ");
                    scanf("%d",&v);
                     printf("\n Enter the no. before which u want to insert the value : ");
                    scanf("%d",&p);
                    insert_before(head,v,p);
                    break;
                case 6:
                    
                    delete_at_beg(&head);
                    break;
                case 7:
                    
                    delete_at_end(&tail);
                    break;
                case 8:
                     printf("\n Enter the no which you want to delete : ");
                    scanf("%d",&p);
                    delete_intermediate(&head,p);
                    break;
                case 9:
                
                    fwddisp(head);
                    break;
                case 10:
                    bckdisp(tail);
                    break;
                case 11:
                    exit(0);
                default:
                    printf("\n Wrong choice");
            }
        }
}
void create(db **head,db **tail)
{
	db *temp;
	int g;
	char ch;
	while(1)
	{
    	printf("\nEnter the value for the node : ");
    	scanf("%d",&g);
    	temp=(db*)malloc(sizeof(db));
    	temp->val=g;
    	temp->prev=temp->next=NULL;
    	if(*head==NULL)
    	*head=*tail=temp;
    	else
    	{
    	    (*tail)->next=temp;
    	    temp->prev=*tail;
    	    *tail=temp;
	    }
    	printf("Do u want more node (y/n) : ");
    	scanf(" %c",&ch);
    	if(ch=='n' || ch=='N')
    	break;
    }
}
    
db *insert_at_beg(db *head,int g)
{
    db *temp;
    temp=(db*)malloc(sizeof(db));
    temp->val=g;
    temp->prev=temp->next=NULL;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}

db *insert_at_end(db *tail,int g)
{
    db *temp;
    temp=(db*)malloc(sizeof(db));
    temp->val=g;
    temp->prev=temp->next=NULL;
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    return tail;
}

db *insert_after(db *head,int nv,int target)
{
    db *temp,*ptr;
    temp=(db*)malloc(sizeof(db));
    temp->val=nv;
    temp->prev=temp->next=NULL;
    ptr=head;
    while(ptr->val!=target && ptr!=NULL)
    {
        ptr=ptr->next;
    }
    if(ptr!=NULL)
    {
        temp->next=ptr->next;
        temp->next->prev=temp;
        ptr->next=temp;
        temp->prev=ptr;
    }
    else
        printf("\n Value not found");
}

db *insert_before(db *head,int nv,int target)
{
    db *temp,*ptr,*pre;
    temp=(db*)malloc(sizeof(db));
    temp->val=nv;
    temp->prev=temp->next=NULL;
    ptr=head;
    while(ptr->val!=target && ptr!=NULL)
    {
        pre=ptr;
        ptr=ptr->next;
    }
    if(ptr!=NULL)
    {
        temp->next=pre->next;
        temp->next->prev=temp;
        pre->next=temp;
        temp->prev=pre;
    }
    else
        printf("\n Value not found");
}

db *delete_at_end(db **tail)
{
    db* temp;
    temp=(*tail);
    (*tail)=(*tail)->prev;
    (*tail)->next=NULL;
}

db *delete_at_beg(db **head)
{
    db* temp;
    temp=(*head);
    (*head)=(*head)->next;
    (*head)->prev=NULL;
}

db *delete_intermediate(db **head,int g  )
{
    db* temp,*pre,*ptr;
    ptr=*head;
    while(ptr->val!=g && ptr!=NULL)
    {
        pre=ptr;
        ptr=ptr->next;
    }
    pre->next=ptr->next;
    ptr->next->prev=pre;
}

void fwddisp(db *head)
{
    while(head!=NULL)
       {
	   printf("%d ",head->val);
	   head=head->next;
        }
}

void bckdisp(db *tail)
{
    while(tail!=NULL)
       {
	   printf("%d ",tail->val);
	   tail=tail->prev;
        }
}