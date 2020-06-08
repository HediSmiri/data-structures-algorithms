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
    int val ;
    struct node *suiv ;
}node ;

// Prototypes declarartions

node Creation(node **List);
node Creation_inconnue(node **List);
node insert_debut (node **List);
node insert_fin (node **List);
void afficher (node *List);
node * insert_middle (node ** List,int n);
node * delete_debut (node **List);
node* delete_fin (node ** List);
node * delete_middle(node **List);
node * delete (node **List);
node * reserve (node ** List);
int search (node * List,int data);
node * concatination(node *List1 ,node *List2, node**List3);
void Tri_bulle(node** head);
int count(node *list);
int change(node **list,int pos1 , int pos2 );

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
                printf("[3] - Delete From List\n");
                printf("[4] - Search In List\n");
                printf("[5] - reserve List\n");
                printf("[6] - Trie List\n");
                printf("[7] - Change Pos in  List\n");
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
                            Creation(&List);
                            goto singly ;
                        }    
                        else if (rep == 2){
                            Creation_inconnue(&List);
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
                            insert_debut(&List);
                        else if (rep == count(List)+1)
                            insert_fin(&List);
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
                    printf("\n[!] - {0} Delete ALL ");
                    printf("\n[+] - Pos of Delete Element : ");
                        scanf("%d",&rep);
                        if (rep == 0) 
                            delete(&List);
                        if (rep == 1){
                            delete_debut(&List);
                        }else if (rep == count(List)+1)
                            delete_fin(&List);
                        else if (rep>count(List)+1){
                            printf("\n[-] - Error Position ! \n\n");
                            goto del;
                        }
                        else
                            delete_middle(&List);
                        printf("\n[+] - successfully Inserted\n");
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
                    reserve(&List);
                    afficher(List);
                    goto singly;
                    break;
                case 6 :
                    printf("\nListe Before :");
                    afficher(List);
                    Tri_bulle(&List);
                    printf("Liste Now : ");
                    afficher(List);
                    goto singly;
                    break;
                case 7 :
                change1 :
                        afficher(List);
                        printf("[#] - Pos 1 : ");
                        scanf("%d",&rep);
                        x1 = search(List,rep);
                        printf("[#] - Pos 2 : ");
                        scanf("%d",&rep1);
                        x2 = search(List,rep1);
                        if ((x1 != 0)&&(x2 != 0 )){
                            if (rep == rep1){
                                printf("[-] Can not change the same Position ");
                            }else{
                                change(&List,rep,rep1);
                                printf("[+] - Successfuly ! ^_^");
                                afficher(List);
                                goto singly;
                            }
                        }else{
                            printf ("[-] - Position Error ");
                            goto change1;
                        }
                    break;
                case 8 :
                    afficher(List);
                    goto singly ;
                    break;
                case 0:
                    exit(0);
                    break;
                
                default:
                    printf("[-] Error Your Input Invalid -_- \n");
                    break;
                }
return 0 ;
}

node Creation(node **List){
    node * Tete, *p;
    int vall,n ;
    printf("\n[#] - Number Of Nodes : ");
    scanf("%d",&n);
    Tete = (node*)malloc(sizeof(node));
    printf("[#] - Node[1] : ");
    scanf("%d",&vall);
    Tete->val = vall;
    Tete->suiv = NULL;
    *List = Tete;
    for (int i = 1 ; i<n;i++){
        p = malloc(sizeof(node*));
        printf("[#] - Node[%d] : ",i+1);
        scanf("%d",&vall);
        p->val = vall;
        p->suiv = NULL;
        (*List)->suiv = p ;
        *List = p ;
    }
    *List = Tete;
    printf("\n[+] - successfully created\n");

}

node Creation_inconnue(node **List){
    node * Tete, *p;
    int vall,n ;
    Tete = NULL ;
    vall = 1;
    int i = 1;
    printf("\n[!] - Just insert 0 to Exit\n");
    while (vall != 0){
        p = malloc(sizeof(node*));
        printf("[#] - Node[%d] : ",i);
        scanf("%d",&vall);
        p->val = vall;
        p->suiv = Tete;
        Tete = p ;
        i++;
    }
    *List = Tete;
    printf("\n[+] - successfully created\n");
}

node insert_debut (node **List){
    node * Tete ;
    node * p = *List;
    int vall ;
    Tete = (node*)malloc(sizeof(node*));
    printf ("[#] - Input Value :  ");
    scanf("%d",&vall);
    Tete->val = vall ;
    Tete ->suiv =p ;
    p = Tete;
    *List = p ;
}

node insert_fin (node **List){
    node * Tete ;
    node * p = *List;
    int vall ;
    Tete = (node*)malloc(sizeof(node*));
    printf ("[#] - Input Value : ");
    scanf("%d",&vall);
    Tete->val = vall ;
    Tete ->suiv =NULL ;
    while (p->suiv != NULL){
        p = p->suiv;
    }
    p->suiv= Tete;
}

void afficher (node *List){
    node* p = List;
    printf("\n########################################\n");
    printf("[<>] - List [ ");
    while (p!=NULL){
        printf("%d | ",p->val);
        p = p->suiv;
    }
    printf("]\n########################################\n");
}

node * insert_middle (node ** List,int n){
    node * temp = *List ;
    node * newnode = (node*)malloc(sizeof(node));
    printf("[#] - Input Value :");
    scanf("%d",&newnode->val);
    for (int i = 1; i < n-1; i++)
    {
       temp = temp->suiv;
       if (temp==NULL){
           printf ("[-] - Error allocate ");
           break;
       }
    }
    if (temp !=NULL){
        newnode->suiv = temp->suiv;
        temp->suiv  = newnode ;
    }
}

node * delete_debut (node **List){
    if (List != NULL){
        node * head = *List ;
        *List = (*List)->suiv ;
        free(head);
        printf ("[-] - Successfully Delete \n");
    }
}

node* delete_fin (node ** List){
    if (*List != NULL){
        node * head = *List ;
        while (head->suiv->suiv != NULL){
            head = head->suiv;
        }
        free(head->suiv->suiv);
        head->suiv = NULL ;
    }
}

node * delete_middle(node **List){
    if (*List != NULL){
        node * head = *List;
        for (int i = 1 ; i<2-1;i++){
            head = head->suiv;
        }
        if (head != NULL){
            node * supp = head->suiv;
            head->suiv = head->suiv->suiv;
            free(supp);
        }
    }
}

node * delete (node **List){
    node * head = *List ;
    while (*List != NULL){
       *List = (*List)->suiv;
       free(head);
   }

}

node * reserve (node ** List){
    if (*List !=NULL){
        node * prev = *List ;
        *List = (*List)->suiv;
        node * cur = *List ;
        prev->suiv = NULL ;
        while (*List != NULL){
            *List = (*List)->suiv;
             cur->suiv = prev;
             prev = cur ;
             cur = *List;        
        }
        *List = prev ;
    }

}

int  search (node * List, int data){
    node * p = List ;
    while ((p != NULL) && (p->val != data))
        p = p->suiv;
    if (p == NULL)
        return 0 ;
    else 
        return 1 ;
}

node * concatination(node *List1 ,node *List2, node**List3){
    node *p = malloc(sizeof(node *));
    if ((List1 == NULL) && (List2 == NULL)){
        p = NULL ;
    }else if ((List1 !=NULL)&&(List2 == NULL)){
        p = List1 ;
    }else if ((List1 ==NULL)&&(List2 != NULL)){
        p = List2 ;
    }else{
        p = List1 ;
        while (p->suiv != NULL){
            p = p->suiv;
        }
        p->suiv = List2;
        p =List1 ;
        *List3 = p ; 
    }
}

void Tri_bulle(node** List) {           
    bool rep ;
    do {
        rep = false;
        node *p = *List;
        node*q = p->suiv;
        while (q!=NULL){
            if (p->val > q->val){
                int temp = p->val;
                p->val = q->val ;
                q->val = temp ;
                rep = true;
            }
            p = q ;
            q = q->suiv;
        }
    }while (rep ==true);
}

int count(node *list)
{
    int nodes = 0;

    while (list != NULL) 
    {
        nodes++;
        list = list->suiv;
    }

    return nodes;
}

int change(node **list,int pos1 , int pos2 )
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

        temp = temp->suiv;
        i++;
    }
        // Link previous of node1 with node2
        if (prev1 != NULL)
            prev1->suiv = node2;

        // Link previous of node2 with node1
        if (prev2 != NULL)
            prev2->suiv = node1;

        // Swap node1 and node2 by swapping their 
        // next node links
        temp        = node1->suiv;
        node1->suiv = node2->suiv;
        node2->suiv = temp;

        // Make sure to swap head node when swapping
        // first element.
        if (prev1 == NULL)
            *list = node2;
        else if (prev2 == NULL)
            *list = node1;

    return 1;
}

