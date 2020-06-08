/*
		@ Code Created by Hedi Smiri 
		Dont remove Copyright @ 2020
		Just Test Skiils in Linked List
		
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Declaritions Types !!

typedef struct node {
    int data ;
    struct node * next ;
    
}node ;

// Prototypes !

void Create (node **head , int n);
void Insert_beginning(node **head);
void Insert(node **head,int n);
void Delete (node ** head ,int n);
int count (node *head);
int search (node * head);
void reservelist (node ** head);
void Display (node * head);

int main(){
    // Clear Cmd ;

	#ifdef _WIN32 // Includes both 32 bit and 64 bit
        system("cls");
	#else
	    system("clear");
	#endif

// Variable Declaration ;

node * last = NULL ;
node *head =NULL ;
int n ;
int rep ;
printf("####################{-Circulaire Linked List-}#################### : \n");
loop:
do {
    printf("\n [1] - Create Linked_List  ");
    printf("\n [2] - Insert in List  ");
    printf("\n [3] - Delete From List  ");
    printf("\n [4] - Search in List ");
    printf("\n [5] - Display Liste ");
    printf("\n [6] - Reverse Linked_List");
    printf("\n [7] - Exit()");
    printf("\n [+] - Your Answer : ");
    scanf("%d",&rep);
}while((rep <= 0) || (rep>7));
switch (rep)
{
case 1:
    printf("\n [#] - NB Of Nodes : ");
    scanf("%d",&n);
    Create(&head,n);
    goto loop;
    break;
case 2 : 
    Insert(&head,n);
    goto loop;
    break;
case 3 : 
    Delete(&head,n);
    goto loop;
    break;
case 4 : 
    search(head);
    goto loop;
    break;
case 5:
    Display(head);
    goto loop;
    break;
case 6 :
    reservelist(&head);
    goto loop;
    break;
case 7 : 
    exit(0);
    break;
default:
    break;
}
return 0 ;
}

void Create (node **head , int n){
    node *p ;
    node *last;
    int data ;
    *head = (node*)malloc(sizeof(node));
    printf("\n [#] - Node[1] = ");
    scanf("%d",&data);
    (*head)->data = data ;
    (*head)->next = NULL ;
    last = *head ;
    for (int i = 2; i <= n; i++)
    {
        p = (node*)malloc(sizeof(node));
        printf(" [#] - Node[%d] = ",i);
        scanf("%d",&data);
        p->data = data ;
        p->next = NULL ;
        last->next = p ;
        last = p ;
    }
    last->next = *head ;
    
}

void Insert_beginning(node **head){
    node *p , *temp;
    int data;
    p = (node *)malloc(sizeof(node));
    printf("\n [#] - Input dataue : ");
    scanf("%d",&data);
    p->data = data ;
    p->next = *head;
    temp = *head ;
    while(temp->next != *head){
        temp=temp->next;
    } 
    temp->next = p ;
    *head = p ;
    printf("\n [+] - Successfuly Inserted \n");
}

void Insert(node **head,int n){
    int n1 ;
    node * p ;
    int data ;
    printf("\n [#] - Position of Inserted Element:");
    scanf("%d",&n1);
    if (n1 == 1)
        Insert_beginning(&(*head));
    else if (n+1>=n1){
        p = (node*)malloc(sizeof (node));
        printf(" [#] - Input data :");
        scanf("%d",&data);
        p->data = data;
        node * temp = *head;
        for (int i=1;i<n1-1;i++){
            temp=temp->next;
        }
        p->next=temp->next;
        temp->next = p ;
        printf("\n [+] - Successfuly Inserted\n");
    }else
         printf("\n [-] - Check Your Position ! \n");
         
    

}

void Delete (node ** head ,int n){
    int i ;
    node * aux = *head ;
    node * temp = aux ;
    int n1; 
    printf("\n [#] - Position of data a Deleted : ");
    scanf("%d",&n1);
        if (n1 ==1){
            if (temp->next == temp) { 
                free(temp);
                return; 
            } 
            while (temp->next != *head) { 
                temp = temp->next; 
            } 
            temp->next = aux->next; 
            *head = temp->next; 
            free(aux); 

        }else if (n1<=count(*head)){
            for (int i =1 ; i<n1-1;i++){
                temp = temp->next;
            }
            aux = temp->next;
            temp->next=temp->next->next; 
            free(aux);
        } else {
            printf(" [+] - Error Position .. \n");
            return;
        }     
        printf("\n [+] - Successfuly Deleted ^^ \n");
}
 
int count (node *head){
    node * p = head ;
    int i = 0 ;
    do {
        p = p->next ;
        i++;
    }while(p != head);
    return i;
}

int search (node * head){
    node * p = head ;
    int data; 
    printf("\n [#] - Input Search dataue  : ");
    scanf("%d",&data);
    int k = 0  ;
    do {
        if (p->data == data){
            k = 1;
        }
        p = p->next ;
    }while (p != head);
    k==1?printf("\n [+] - Found !\n"):printf("\n [+] - Not Found !\n");
} 

void reservelist (node ** head){
    node * prev ,*cur,*last; 
    if (*head == NULL){
        printf(" [-] - Liste is Empty ..");
        return ;
    }
    last = *head ;
    prev = *head;
    cur = (*head)->next ;
    *head = (*head)->next ;
    while (*head != last){
        *head = (*head)->next ;
        cur->next = prev ;

        prev =cur ;
        cur = *head ;
    }
    cur->next = prev ;
    *head = prev ;
    printf("\n [+] - Reservelist done .\n");
}

void Display (node * head){
    node * q = head ;
    if (head == NULL){
        printf(" [-] - LIste is Empty");
        return;
    }
    printf("\n=============================================\n");
    printf(" [<>] - Liste = [");
    do{
        printf("| %d  ",q->data);
        q= q->next;
    }while (q != head);
    printf("|]");
    printf("\n=============================================\n");
}