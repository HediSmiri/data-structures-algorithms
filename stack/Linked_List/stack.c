#include <stdio.h>
#include <stdlib.h>

typedef struct stackk
{
	int data ;
	struct stackk * next ;
}stackk;

int size = 0 ;

void push (stackk **stack);
void pop (stackk **stack);
void display (stackk *stack);

int main(){

stackk * stack = NULL ;
int rep ;
    printf("\n==================={Stack}======================\n");
    menu :
    while (1){
        printf("\n[1] - Push ");
        printf("\n[2] - Pop ");
        printf("\n[3] - Size of Stack ");
        printf("\n[4] - Display ");
        printf("\n[5] - Exit ");
        printf("\n[#] - Answer : ");
        scanf("%d",&rep);
        switch(rep){
        case 1 :
            push(&stack);
            display(stack);
            goto menu ;
            break;
        case 2 :
            pop(&stack);
            display(stack);
            goto menu ;
            break;
        case 3 :
            printf("\nSize of Stack : %d\n",size);
            break;
        case 4 :
            display(stack);
            goto menu ;
        case 5 :
            exit(0);
        default:
            printf("[!] - Error ! ");
        }
	}
return 0;

}

void push (stackk **stack){
	int data ;
	stackk * head = (stackk*) malloc (sizeof(stackk));
	printf("Data [%d]\n",size);
	scanf("%d",&data);
	head->data = data ;
	head->next = *stack;
	*stack = head ;
	size++;
}
void pop (stackk **stack){
	if (size<=0){
		printf("Stack Is Empty ! ");
		return;
	}
	stackk * head = *stack ;
	*stack = (*stack)->next;
	free(head);
	size-- ;
}
void display (stackk *stack){
	stackk * head = stack ;
	printf("\n========{stack}========\n");
	while (head != NULL){
		printf("%d \n",head->data);
		head = head->next;
	}
	printf("\n========================\n");
}