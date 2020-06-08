/*
		@ Code Created by Hedi Smiri 
		Dont remove Copyright @ 2020
		Just Test Skiils in Linked List
		
*/

// Library used ;

#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Declaation Types 

typedef struct node {
    int data ;
    struct node * next ;
    struct node * prev ;
}node ;

// Prototypes declarartions

void Create (node **head , node **last ,int n);
int count (node *head);
void insert_first(node ** head);
void insert_end(node ** last);
void insert(node ** head,node ** last,int n);
void Delete_First (node ** head);
void Delete_end (node ** last);
void Delete(node **head , node ** last , int n );
void reverse(node **head, node **last);
void Display (node *head,node* last , int rep);


// main Function 

int main(){

// Clear Cmd

#ifdef _WIN32 // Includes both 32 bit and 64 bit
    system("cls");
#else
    system("clear");
#endif

int reponse ,n ,rep,rep1 ;
node *head = NULL ;  // Head of List
node *last = NULL ; // last of List
printf("####################{-Doubly Linked List-}#################### : \n");
loop:
do {
    printf("\n [1] - Create Linked_List  ");
    printf("\n [2] - Insert in List  ");
    printf("\n [3] - Delete From List  ");
    printf("\n [4] - Display Liste ");
    printf("\n [5] - Reverse Linked_List");
    printf("\n [6] - Exit()");
    printf("\n [+] - Your Answer : ");
    scanf("%d",&reponse);
    printf("\n");
}while((reponse <=0) || (reponse>6));
switch (reponse)
{
case 1:
    printf("\n [+] - Number of Nodes : ");
    scanf("%d",&n);
    Create(&head,&last,n); 
    printf("==================================================\n");
    printf("[<>] Liste Now : ");
    Display(head,last,1);
    printf("\n==================================================\n");
    goto loop;
    break;

case 2:
        printf("\n==================================================\n");
        printf(" [+] - Position  : ");
        scanf("%d",&n);
            if (count(head) >= n-1){
                insert(&head,&last,n);
                printf(" [+] - Successfuly ^_^");
            }
            else 
                printf (" [-] - Check Your Position ! \n");
        printf("\n==================================================\n");
        goto loop;
case 3 :
    printf("\n================================================== \n");
    printf(" [+] - Position of Delete Element : ");
    scanf("%d",&n);
    if (count(head) >= n-1){
        Delete(&head,&last,n);
    }else 
         printf (" [-] - Check Your Position ! \n");
    printf("\n==================================================\n");
    goto loop;
    break ;
case 4 :
    disp:
    printf("\n\n============Display Mode ========================\n");
    printf (" [1] - Display From beginning \n");
    printf (" [2] - Display From End  \n");
    printf (" [3] - Menu\n");
    printf (" [+] - Your Answer : ");
    scanf("%d",&rep ) ;
    printf("==================================================\n");
    if (rep == 3){
            printf("==================================================\n");
            goto loop ; 
        }
    else if ((rep == 1) || (rep == 2)){
            printf (" [<>] Liste : ");
            Display(head,last,rep);
    }     
    printf("\n==================================================\n");
    goto disp;
    break;
case 5 : 
    reverse(&head,&last);
    printf(" [+] - Successfuly reverse ! ");
    goto loop;
    break;
default:
    break;
}
printf("\n\n===============================================================\n");
return 0 ;
}

// functions : 

// Create Linked_List

void Create (node **head , node **last , int n) {
    int data ;
    *head = (node*)malloc(sizeof(node));
    if (*head == NULL ){
        printf("[-] Unable to allocate memory !");
        exit(0);
    }else {
        printf(" [#] - node [1] : ");
        scanf("%d",&data);
        (*head)->data = data ;
        (*head)->next = NULL ;
        (*head)->prev = NULL ;
        *last = *head;
        for (int i = 2 ; i<=n ; i++){
            node * p = (node*)malloc(sizeof(node));
            if (p == NULL){
                printf("[-] Unable to allocate memory ! ");
                break;
            }else{
                printf(" [#] - node [%d] : ",i);
                scanf("%d",&data);
                p->data = data ;
                p->prev = *last ;
                p ->next = NULL;
                (*last)->next = p ;
                *last = p ;
            }
        }
        printf("\n [+] Successfully Created \n\n");
    }
}
// count Number of Linked List

int count (node *head){
    node * p = head;
    int i = 0 ;
    while (p!=NULL){
        p = p->next;
        i++;
    }
    return i ;
}

// You can insert data From begining of List

void insert_first(node ** head){

    int data ;
    node * p = (node*)malloc(sizeof(node));
    printf(" [#] - Input Value : ");
    scanf("%d",&p->data);
    p->prev = NULL ;
    p->next = *head ;
    (*head)->prev = p ;
    *head = p ;

}

// You can insert data From last of List

void insert_end(node ** last){
    int data ;
    node * p = (node*)malloc(sizeof(node));
    printf(" [#] - Input dataue : ");
    scanf("%d",&p->data);
    p->next = NULL ;
    p->prev = *last ;
    (*last)->next = p ;
    *last = p ;
}

/*
    Here i used last two Procedure i created and some of code to Delete from anywhere i need :P
*/
void insert(node ** head,node ** last,int n){
    if(*head == NULL)
    {
        printf("[-] Error, List is Empty ! \n");
    }
    node * temp = * head ;

    int data;
    int i=1;
    while(i<n-1 && temp!=NULL)
    {
        temp = temp->next;
        i++;
    }
    if (n == 1){
        insert_first
    (&(*head));
    }else if (temp == *last){
        insert_end(&(*last));
    }else if (temp !=NULL){
        node * newnode = (node*)malloc(sizeof(node));
        printf(" [#] - Input Value : ");
        scanf("%d",&data);
        newnode->data = data ;
        newnode->next = temp->next;
        newnode->prev = temp ;
        if (temp->next != NULL)
            temp->next->prev = newnode ;
        temp->next = newnode ;
        printf (" [+] - Successfuly Inserted ..\n");
    }
    
}

// Delete Funcctions :

// Delete From Beginning 

void Delete_First (node ** head){
    if (*head == NULL){
        printf("Le list est Vide \n");
    }else {
        node * temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL ;
        free(temp);
    }
    printf(" [+] - Successfuly Delete ! .");
}

// Delete From Last 

void Delete_end (node ** last){
    if (*last == NULL){
        printf("Le list est Vide \n");
    }else {
        node * temp = *last;
        *last = (*last)->prev;
        (*last)->next = NULL ;
        free(temp);
    }
    printf(" [+] - Successfuly Delete ! .");
}

// Like Insert i add some peaces of code to Delete from anywhere i needeed :P 
// Bad english -_- i know but i Try to be better 

void Delete(node **head , node ** last , int n ){
    node * temp = *head;
    for (int i = 1 ; i< n && temp != NULL ; i++){
        temp = temp->next;
    }
    if (n == 1){
        Delete_First(&(*head));
    }else if (temp == *last){
        Delete_end(&(*last));
    }else if (temp != NULL){
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        printf(" [+] - Successfuly Delete ! .");
    }else
    {
        printf(" [+] - Position Error ! !\n");
    }
}

// Reverse List if list = 1 2 3 4 well its 4 3 2 1 good ? like a magic :P

void reverse(node **head, node **last)
{
    node *temp, *aux;
    temp = *head;
    while(temp != NULL)
    {
        aux = temp->next;
        temp->next = temp->prev;
        temp->prev = aux;
        temp = aux;
    }
    
    aux = *head;
    *head = *last;
    *last = aux;

    printf(" [+] - Reverse Linked List done .  .\n");
}


/*
    Display Mod here you can Diplay Your List From beginning or last 
            if your answer 1 diplay from beginning 
            if 2 display from last 
*/

void Display (node *head,node* last , int rep){
    if (rep == 1){
        node * temp = head ;
        while (temp != NULL ){
            printf ("| %d  " ,temp->data);
            temp = temp->next ;
        }
        printf("|");
    }else if(rep == 2){
        node * temp = last ;
        while (temp != NULL ){
            printf ("| %d  " ,temp->data);
            temp = temp->prev ;
        }
        printf("|");
    }else  {
        printf(" [-] Votre repense hors sujet :P \n");
        exit(0);
    }
}

// Thanks For Watching :P ; ^_^