/*
		@ Code Created by Hedi Smiri 
		Dont remove Copyright @ 2020
		Just Test Skiils in Linked List		
*/

// Library used ;


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Declaation Types 

typedef struct node {
    int data ;
    struct node *next ;
}node ;

// Prototypes declarartions

void create(node **List);
void create_unk(node **List);
void Insert_First (node **List);
void Insert_end (node **List);
void Display (node *List);
void insert_middle (node ** List,int n);
void Delete_first (node **List);
void Delete_end (node ** List);
void delete_middle(node **List);
void delete (node **List);
void reverse (node ** List);
int search (node * List,int data);
void concatenate(node *List1 ,node *List2, node**List3);
void sort_bulle(node** head);
int count(node *list);
int swap(node **list,int pos1 , int pos2 );

int main(){

// Variable Declartions :

node * List = NULL ;
int rep ,rep1;
int x1 ,x2 ;

//  Clear Cmd

#ifdef _WIN32 // Includes both 32 bit and 64 bit
    system("cls");
#else
    system("clear");
#endif
   singly:
        do {
                printf("\n####################{-Singly Linked List-}####################\n\n");
                printf("[1] - Create List\n");
                printf("[2] - Insert In List\n");
                printf("[3]   Delete From List\n");
                printf("[4] - Search In List\n");
                printf("[5] - reverse List\n");
                printf("[6] - Trie List\n");
                printf("[7] - swap Pos in  List\n");
                printf("[8] - Display List\n");
                printf("[0] - Exit\n");
                printf("[#] - Your Answer : ");
                scanf("%d",&rep);
        }while ((rep<0) || (rep>=11));
            switch (rep)
                {
                case 1:
                create:
                        printf("\n[1] - Knowen The Number of List \n");
                        printf("[2] - unknowen The Nb of List  \n");
                        printf("[3] - Menu  \n");
                        printf("[#] - Your Answer : ");
                        scanf("%d",&rep);
                        if (rep == 1){
                            create(&List);
                            goto singly ;
                        }    
                        else if (rep == 2){
                            create_unk(&List);
                            goto singly ;
                        }                   
                        else if (rep == 3) 
                            goto singly ;
                        else {
                            printf("[-] Error Try again ! \n");
                            goto create;
                        }
                        break;
                case 2 :
                pos:
                        printf("[+] - Pos : ");
                        scanf("%d",&rep);
                        if (rep == 1)
                            Insert_First(&List);
                        else if (rep == count(List)+1)
                            Insert_end(&List);
                        else if (rep>count(List)+1){
                            printf("\n[-] - Error Position ! \n\n");
                            goto pos;
                        }else
                    insert_middle(&List,rep);
                        printf("\n[+] - successfully Inserted\n");
                        goto singly;
                        break;
                case 3 :
                del :
                    printf("\n[!] - {0 Delete ALL ");
                    printf("\n[+] - Pos of Delete Element : ");
                        scanf("%d",&rep);
                        if (rep == 0) 
                            delete(&List);
                        if (rep == 1){
                             Delete_first(&List);
                        }else if (rep == count(List)+1)
                             Delete_end(&List);
                        else if (rep>count(List)+1){
                            printf("\n[-] - Error Position ! \n\n");
                            goto del;
                        }
                        else
                            delete_middle(&List);
                        goto singly;
                    break;
                case 4 :
                        search:
                            printf("\n[#] - Data You Search : ");
                            scanf("%d",&rep);
                            x1 = search(List,rep);
                                if (x1 == 0)
                                    printf ("[-] - Element not found\n");
                                else 
                                    printf("[+] - done.\n");
                            printf("[+] - DO You Like Athor search [1-yes][0-no] : ");
                            scanf("%d",&rep);
                            if (rep == 0)
                                goto singly;
                            else
                                goto search;
                    break;
                case 5 :
                    reverse(&List);
                    Display(List);
                    goto singly;
                    break;
                case 6 :
                    printf("\nListe Before :");
                    Display(List);
                    sort_bulle
                (&List);
                    printf("Liste Now : ");
                    Display(List);
                    goto singly;
                    break;
                case 7 :
                swap1 :
                        Display(List);
                        printf("[#] - Number 1 : ");
                        scanf("%d",&rep);
                        x1 = search(List,rep);
                        printf("[#] - Number 2 : ");
                        scanf("%d",&rep1);
                        x2 = search(List,rep1);
                        if ((x1 != 0)&&(x2 != 0 )){
                            if (rep == rep1){
                                printf("[-] Can not swap the same Position ");
                            }else{
                                swap(&List,rep,rep1);
                                printf("[+] - Successfuly ! ^_^");
                                Display(List);
                                goto singly;
                            }
                        }else{
                            printf ("[-] - Position Error ");
                            goto swap1;
                        }
                    break;
                case 8 :
                    Display(List);
                    goto singly ;
                    break;
                case 0:
                    exit(0);
                    break;
                
                default:
                    printf("[-] Error Your Input Indataid -_- \n");
                    break;
                }
return 0 ;
}

void create(node **List){
    node * Tete, *p;
    int data,n ;
    printf("\n[#] - Number Of Nodes : ");
    scanf("%d",&n);
    Tete = (node*)malloc(sizeof(node));
    printf("[#] - Node[1] : ");
    scanf("%d",&data);
    Tete->data = data;
    Tete->next = NULL;
    *List = Tete;
    for (int i = 1 ; i<n;i++){
        p = malloc(sizeof(node*));
        printf("[#] - Node[%d] : ",i+1);
        scanf("%d",&data);
        p->data = data;
        p->next = NULL;
        (*List)->next = p ;
        *List = p ;
    }
    *List = Tete;
    printf("\n[+] - successfully created\n");

}

void create_unk(node **List){
    node * Tete, *p;
    int data;
	printf("\n[!] - Just insert 0 to Exit\n");
    Tete = (node*)malloc(sizeof(node));
	printf("[#] - Node [1] :");
	scanf("%d",&data);
	Tete->data = data ;
	Tete->next = NULL ;
	*List = Tete ;
	int i = 2 ;
    while (1){
        p = (node*)malloc(sizeof(node));
        printf("[#] - Node[%d] : ",i);
        scanf("%d",&data);
		if (data == 0)
			break;
        p->data = data;
        p->next = NULL;
		(*List)->next = p ;
		*List = p ;
        i++;
    }
    *List = Tete;
    printf("\n[+] - successfully created\n");
}


void Insert_First (node **List){
    node * Tete ;
    node * p = *List;
    int data ;
    Tete = (node*)malloc(sizeof(node*));
    printf ("[#] - Input data :  ");
    scanf("%d",&data);
    Tete->data = data ;
    Tete->next =p ;
    p = Tete;
    *List = p ;
}

void Insert_end (node **List){
    node * Tete ;
    node * p = *List;
    int data ;
    Tete = (node*)malloc(sizeof(node*));
    printf ("[#] - Input dataue : ");
    scanf("%d",&data);
    Tete->data = data ;
    Tete ->next =NULL ;
    while (p->next != NULL){
        p = p->next;
    }
    p->next= Tete;
}

void Display (node *List){
    node* p = List;
    printf("\n########################################\n");
    printf("[<>] - List [ ");
    while (p!=NULL){
        printf("%d | ",p->data);
        p = p->next;
    }
    printf("]\n########################################\n");
}

void insert_middle (node ** List,int n){
    node * temp = *List ;
    node * newnode = (node*)malloc(sizeof(node));
    printf("[#] - Input dataue :");
    scanf("%d",&newnode->data);
    for (int i = 1; i < n-1; i++)
    {
       temp = temp->next;
       if (temp==NULL){
           printf ("[-] - Error allocate ");
           break;
       }
    }
    if (temp !=NULL){
        newnode->next = temp->next;
        temp->next  = newnode ;
    }
}

void Delete_first (node **List){
    if (List != NULL){
        node * head = *List ;
        *List = (*List)->next ;
        free(head);
        printf ("[+] - Successfulle Delete \n");
    }
}

void Delete_end (node ** List){
    if (*List != NULL){
        node * head = *List ;
        while (head->next->next != NULL){
            head = head->next;
        }
        free(head->next->next);
        head->next = NULL ;
    }
	printf ("[+] - Successfulle Delete \n");
}

void delete_middle(node **List){
    if (*List != NULL){
        node * head = *List;
        for (int i = 1 ; i<2-1;i++){
            head = head->next;
        }
        if (head != NULL){
            node * supp = head->next;
            head->next = head->next->next;
            free(supp);
        }
    }
	printf ("[+] - Successfulle Delete \n");
}

void delete (node **List){
    node * head = *List ;
    while (*List != NULL){
       *List = (*List)->next;
       free(head);
   }
   printf ("[+] - Successfulle Delete \n");

}

void reverse (node ** List){
    if (*List !=NULL){
        node * prev = *List ;
        *List = (*List)->next;
        node * cur = *List ;
        prev->next = NULL ;
        while (*List != NULL){
            *List = (*List)->next;
             cur->next = prev;
             prev = cur ;
             cur = *List;        
        }
        *List = prev ;
    }

}

int  search (node * List, int data){
    node * p = List ;
    while ((p != NULL) && (p->data != data))
        p = p->next;
    if (p == NULL)
        return 0 ;
    else 
        return 1 ;
}

void concatenate(node *List1 ,node *List2, node**List3){
    node *p = malloc(sizeof(node *));
    if ((List1 == NULL) && (List2 == NULL)){
        p = NULL ;
    }else if ((List1 !=NULL)&&(List2 == NULL)){
        p = List1 ;
    }else if ((List1 ==NULL)&&(List2 != NULL)){
        p = List2 ;
    }else{
        p = List1 ;
        while (p->next != NULL){
            p = p->next;
        }
        p->next = List2;
        p =List1 ;
        *List3 = p ; 
    }
}

void sort_bulle(node** List) {           
    bool rep ;
    do {
        rep = false;
        node *p = *List;
        node*q = p->next;
        while (q!=NULL){
            if (p->data > q->data){
                int temp = p->data;
                p->data = q->data ;
                q->data = temp ;
                rep = true;
            }
            p = q ;
            q = q->next;
        }
    }while (rep ==true);
}

int count(node *list)
{
    int nodes = 1;

    while (list != NULL) 
    {
        nodes++;
        list = list->next;
    }

    return nodes;
}

int swap(node **list,int pos1 , int pos2 )
{
    struct node *node1, *node2, *prev1, *prev2, *temp;
    int i;

    const int maxPos = (pos1 > pos2) ? pos1 : pos2;
    
    const int totalNodes = count(*list);

    if ((pos1 <= 0 || pos1 > totalNodes) || (pos2 <= 0 || pos2 > totalNodes)) return -1;
    
    if (pos1 == pos2) return 1;

    i = 1;
    temp  = *list;
    prev1 = NULL;
    prev2 = NULL;

    while (temp != NULL && (i <= maxPos))
    {
        if (i == pos1 - 1)
            prev1 = temp;
        if (i == pos1)
            node1 = temp;

        if (i == pos2 - 1)
            prev2 = temp;
        if (i == pos2)
            node2 = temp;

        temp = temp->next;
        i++;
    }
        // Link previous of node1 with node2
        if (prev1 != NULL)
            prev1->next = node2;

        // Link previous of node2 with node1
        if (prev2 != NULL)
            prev2->next = node1;

        // Swap node1 and node2 by swapping their 
        // next node links
        temp        = node1->next;
        node1->next = node2->next;
        node2->next = temp;

        // Make sure to swap head node when swapping
        // first element.
        if (prev1 == NULL)
            *list = node2;
        else if (prev2 == NULL)
            *list = node1;

    return 1;
}
