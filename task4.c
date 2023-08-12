#include <stdio.h>
#include "STD_TYPES.h"
#include <stdlib.h>

typedef struct node
{
	u32 Value;
	struct node* next;
}node_t;

void AddNodeToEnd (node_t* Head,u32 Data);

void AddNodeToMiddle (node_t* Head,u32 Data,u32 index);

void printList(node_t* Head);

int main()
{
	u32 input, index, first=0;
	u32 value;
	node_t* Head = (node_t*) malloc(sizeof(node_t));
	Head->next=NULL;
	while(1){
	printf("To add node to end press 0:\n To add node to middle press 1:\n To print press2:\n");
	scanf("%d",&input);
	switch(input)
	{
		case 0:
		printf("please enter the value: ");
		scanf("%d",&value);
		if(first==0)
		{
			Head->Value=value;
			first=1;
		}
		else{
		AddNodeToEnd(Head,value);
		
		}
		printf("thank you, node added\n");
		break;
		case 1:
		printf("pleae enter the index and the valuerespectively: ");
		scanf("%d \n %d",&index,value);
		AddNodeToMiddle(Head,value,index);
		printf("thank you, node added\n");
		break;
		case 2:
		printList(Head);break;
	}
	}
}

void printList(node_t* Head)
{
	node_t* ptr=Head;
	while(ptr!=NULL){
		printf("%d\n",ptr->Value);
		ptr=ptr->next;
	}
}

void AddNodeToMiddle (node_t* Head,u32 Data,u32 index)
{
	u8 i;
	node_t* ptr=Head;
	node_t* New = (node_t*) malloc(sizeof(node_t));
	New->Value=Data;
	for(i=0;i<index;i++)
	{
		ptr=ptr->next;
	}
	
	New->next=ptr->next;
	ptr->next=New;
	
	}

void AddNodeToEnd (node_t* Head,u32 Data)
{
	node_t* ptr=Head;
	node_t* new = (node_t*) malloc(sizeof(node_t));
	
	
	new->Value=Data;
	new->next=NULL;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=new;
}
