/*
		@ Code Created by Hedi Smiri 
		Dont remove Copyright @ 2020
		Just Test Skiils in Linked List
		
*/

// Library

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data ;
	struct node * next ;
}node ;

// Capacity max of Queue

#define capacity 1000

// Size of Queue

unsigned int size = 0 ;

void Enqueue(node **rear,node ** front,int data);
void Dequeue();
void display(node * rear);

int main(){

int data , rep ,x;
node * front= NULL ;
node * rear = NULL ;
menu :

	while (1){
		printf("\n[1] - Enqueue");
		printf("\n[2] - Dequeue");
		printf("\n[3] - rear Value");
		printf("\n[4] - front Value");
		printf("\n[5] - Exit");
		printf("\n[+] - Answer :");
		scanf("%d",&rep);
		switch (rep)
		{
		case 1:
			printf("data : ");
			scanf("%d",&data);
			Enqueue(&rear,&front,data);	
			display(front);	
			break;
		case 2 :
			Dequeue(&front,&x);
			printf("\nEXtracted : %d\n",x);
			display(front);
			goto menu;
			break;
		case 3 :
			printf("\n Rear Value : %d",rear->data);
			break;
		case 4 :
			printf("\n front Value : %d",front->data);
			break;
		case 5 :
			exit(0);
		default:
			break;
		}

	}

return 0 ;
}

void Enqueue(node **rear,node ** front , int data)
{
	if (size>capacity)
		{
			printf("[-] - Queue over Flow");
			return ;
		}
	node *p = (node*)malloc(sizeof(node));
	p->data = data ;
	p->next = NULL ;
	if (*rear != NULL )
		(*rear)->next = p ;
	else 
		*front = p ;
	*rear = p ;
	size++;
}

void Dequeue(node ** front ,int * x){
	node * p = *front; ;
	if (*front == NULL){
		printf("List is Empty ! ");
		return ;
	}
	*x = (*front)->data;
	*front = (*front)->next ;
	free(p);
	printf("\n[+] - Successfuly");
}

void display(node * List){
	node * p = List;
	while (p!=NULL){
		printf("%d | ",p->data);
		p = p ->next;
	}
}
