#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};



void Insert(struct node** head_ref,int data,int position)
{
	int k=1;
	struct node *p,*q,*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(!newnode)
	{
		printf("memory error");
		return;
	}

	newnode->data=data;
	p=*head_ref;

	if(position=1)
	{
		newnode->next=p;
		*head_ref=newnode;

	}


	else
	{	

		while((p->next!=NULL))
		{
			p=p->next;
		
		}
		p->next=newnode;
		newnode->next=NULL;
	}
}


void delete(struct node **head_ref,int position)
{
	int k=1;
	struct node *p,*q;

	p=*head_ref;

	if(position==1)
	{
		*head_ref=(*head_ref)->next;
		free(p);
		return;
	}

	else
	{
		while((p!=NULL)&&(k<position))
		{
			k++;
			q=p;
			p=p->next;
		}

		if(p==NULL)
		{
			printf("position does not exist");
		}

		else
		{
			q->next=p->next;
			free(p);
		
		}
	}
}





void display(struct node *head)
{
	

	while(head!=NULL)
{
	printf("%d\n",head->data);
	head=head->next;
}

}


int main()
{
	struct node* head=NULL;
	int n=0,i=0,data=0;
printf("enter the no of elements");
scanf("%d",&n);


for(i=1;i<=n;i++)
{
	printf("enter %d no element",i);
	scanf("%d",&data);

	Insert(&head,data,i);
}

display(head);

 printf("enter pos to delete");
        scanf("%d",&data);

delete(&head,data);
display(head);

return 0;
}




