#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/*
    PREORDER -> 1. ROOT
                2. PRE(LEFT)
                3. PRE(RIGHT)

    INORDER -> 1. IN(LEFT) ///ORDINE CRESCATOARE
               2. ROOT
               3. IN(RIGHT)

    POSTORDER -> 1. POST(LEFT)
                 2. POST(RIGHT)
                 3. ROOT
*/

int main() {
    struct tree_node *root;
    root=NULL;
    int choice;
    int data;
    int aux;
    int afisare[105]={0};
    int elem=0;
    while( 1 > 0 )
    {
        printf("\nPress 1 for inserting a node in BST fashion: ");
        printf("\nPress 2 for traversing the tree in preorder fashion :");
        printf("\nPress 3 for traversing the tree in postorder fashion :");
        printf("\nPress 4 for traversing the tree in inorder fashion :");
        printf("\nPress 5 for searching:");
        printf("\nPress 6 for poping and element:");
        printf("\nPress 7 for printing the number of leaves:");
        printf("\nPress 8 for printing the biggest number in the BST:");
        printf("\nPress 9 for printing the smallest number in the BST:");
        printf("\nPress 10 for printing the leashes of the BST:");
        printf("\nPress 11 to exit :");


        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter the value to be inserted:");
                scanf("%d",&data);
                insert_node(&root, data);
                break;

            case 2: preorder(root);
                break;

            case 3:postorder(root);
                break;

            case 4: inorder(root);
                break;

            case 5:
                printf("\nEnter the value to be searched:");
                scanf("%d",&data);
                aux = search_node(root, data);
                (aux == 1) ? printf("Element found") : printf("Element not found");
                break;
            case 6:
                printf("\nEnter the value to be poped:");
                scanf("%d",&data);
                pop_node(root,data);
                break;
            case 7:
                 printf("\nThe number of leaves is equal to ");
                 printf("%d",number_of_leaves(root));
                 break;
            case 8:
                    printf("\nThe biggest number in the BST is equal to ");
                    printf("%d",Max_in_BST(root));
                    break;
            case 9:
                    printf("\nThe smallest number in the BST is equal to ");
                    printf("%d",Min_in_BST(root));
                    break;
            case 10:
                    printf("\nThe leashes in the BST are: ");
                    show_leaves(root);
                    break;
            case 11: exit(0);
                break;
            default: printf("\nYou have entered an invalid choice. Please try again");
        }
    }
    free(root);
    return 0;
}
