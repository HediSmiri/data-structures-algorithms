#include <stdio.h>
#include <stdlib.h>
#define size 5

int top = -1 ;

int push(int stack[]);
int pop(int stack[]);
int display(int stack[]);

int main(){
    int stack[5];
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
            push(stack);
            display(stack);
            goto menu ;
            break;
        case 2 :
            pop(stack);
            display(stack);
            goto menu ;
            break;
        case 3 :
            printf("\nSize of Stack : %d\n",top+1);
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

int push(int stack[]){
	int data ;
	if (top>size){
		printf("\n[-] - Stack OverFlow !");
	}else {
		top++;
		printf("[#] - Data [%d]: ",top);
		scanf("%d",&data);
		stack[top] = data;
	}
}

int pop(int stack[]){
    if (top<0){
        printf("\n[-] - Pile Empty .. !");
    }else{
        return(stack[--top]);
    }
}

int display(int stack[]){
    printf("\n======Stack======\n");
	for (int i = top ;i>=0;i--)
		printf("%d\n",stack[i]);
	printf("=================\n");
}

