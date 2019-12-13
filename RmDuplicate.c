#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *head=NULL;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Name		: InsertNode
//Input		: int
//Output	: void
//Desc		: Insert the node in linklist
//Author	: Akshay Kamble
//Date		: 13/12/2019
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertNode(int data)
{
	struct node* newnode=NULL;
	struct node* temp=NULL;

	newnode=(struct node*)malloc(sizeof(struct node));

	newnode->data=data;

	if(head==NULL)
	{
		head=newnode;
		newnode->next=NULL;
	}
	else
	{
		temp=head;

	while(temp->next!=NULL)
	{
		temp=temp->next;
	}

	temp->next=newnode;
	newnode->next=NULL;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Name		: display
//Input		: struct node*
//Output	: void
//Desc		: Dsiplay linklist
//Author	: Akshay Kamble
//Date		: 13/12/2019
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void display(struct node* head)
{
	while(head!=NULL)
	{
		printf("%d\n",head->data);
		head=head->next;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Name		: RmDup
//Input		: 
//Output	: void
//Desc		: Remove the duplicate nodes from linklist
//Author	: Akshay Kamble
//Date		: 13/12/2019
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void RmDup()
{
	struct node* temp=head;

	while(temp->next!=NULL)
	{
		if(temp->data==(temp->next)->data)
		{
			free(temp->next);
			temp->next=(temp->next)->next;
		}

		else{
			temp=temp->next;
		}
	}
}

int main()
{
	
	int size=0,data=0;

	printf("enter the size of linked list\n");

	scanf("%d",&size);

	printf("enter data");
	while(size>0)
	{
		scanf("%d",&data);
		InsertNode(data);
		size--;
	}


//	display(head);
	RmDup();
	printf("After removing duplicate elements in list\n");
	display(head);

	return 0;
}
	

