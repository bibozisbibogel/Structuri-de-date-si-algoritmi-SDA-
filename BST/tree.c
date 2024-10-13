#include <stdio.h>
#include <malloc.h>
#include "tree.h"
/*
    Exemplu:
      9
     / \
    7  14
   / \ / \
  5  8 11 16

   Output Postorder: 5 8 7 11 16 14 9
*/
void insert_node(struct tree_node **root, int new_element_value) {

    while(*root != NULL){
        if (new_element_value < (*root)->info){
            root = &(*root)->left_child;
        }else{
            root = &(*root)->right_child;
        }
    }
    *root = malloc (sizeof **root);
    (*root)->info = new_element_value;
    (*root)->left_child = NULL;
    (*root)->right_child = NULL;
}


void preorder(struct tree_node *root) {
    if(root == NULL)
    {
        printf("\nThe BST is empty");
        return;
    }

    printf("%d,", root->info);
    if (root->left_child) preorder(root->left_child);
    if (root->right_child) preorder(root->right_child);
}
void postorder(struct tree_node *root) {
    if(root!=NULL)
    {
        postorder(root->left_child);
        postorder(root->right_child);
        printf("%d, ",root->info);
    }
}
void inorder(struct tree_node *root) {
    if(root==NULL)
    {
        printf("\nThe BST is empty");
        return;
    }
    if(root->left_child)
        inorder(root->left_child);
    printf("%d",root->info);
    printf(", ");
    if(root->right_child)
        inorder(root->right_child);
}

int search_node(struct tree_node *root, int searched_value){
    int found = 0;
    struct tree_node *current;

    current = root;
    while ( (current != NULL) && (found == 0) ){
        if (current->info == searched_value){
            found = 1;
        }else if ( searched_value > current->info){
            current = current->right_child;
        }else if ( searched_value < current->info  ){
            current = current->left_child;
        }
    }

    return found;
}
struct tree_node* pop_node(struct tree_node *root, int searched_value){
    int CR7=search_node(root,searched_value);
    if(CR7==1){
        if(root==NULL)
            return root;
        if(root->info > searched_value)
        {
            root->left_child=pop_node(root->left_child,searched_value);
            return root;
        }
        else if(root->info<searched_value)
        {
            root->right_child=pop_node(root->right_child,searched_value);
            return root;
        }
        ///am ajuns in punctul in care root este nodul care trb sa fie sters

        ///verificam daca unul din copii este NULL

        if(root->left_child==NULL)
        {
            struct tree_node* temp=root->right_child;
            free(root);
            return temp;
        }
        else if(root->right_child==NULL)
        {
            struct tree_node* temp=root->left_child;
            free(root);
            return temp;
        }
        /// avem si left_child, dar si right_child
        /*
                    6
                   /  \
                  4    8
                 /  \    /\
                2    5  7  9
               / \
              1   3

              ex: vrem sa stergem 2
        */
        else
        {
            /// Messi = parinte_succesor
            /// Neymar = succesor
            struct tree_node* Messi=root;
            ///gasim succesorul
            struct tree_node* Neymar=root->right_child;
            while(Neymar->left_child!=NULL)
            {
                Messi=Neymar;
                Neymar=Neymar->left_child;
            }
            if(Messi!=root)
                Messi->left_child=Neymar->right_child;
            else
                Messi->right_child=Neymar->right_child;
            ///dam valoarea
            root->info=Neymar->info;
            free(Neymar);
            return root;
        }
    }
    else
        printf("The value you entered is not in the BST!\n");
}
int number_of_leaves(struct tree_node *root)
{
    if(root==NULL)
        return 0;
    if(root->left_child==NULL && root->right_child==NULL)
        return 1;
    else
        return number_of_leaves(root->left_child)+number_of_leaves(root->right_child);
}
int Max_in_BST(struct tree_node *root)
{
    int Max;
    if(root->right_child==NULL)
        return root->info;
    else
        return Max_in_BST(root->right_child);
}
int Min_in_BST(struct tree_node *root)
{
    int Min;
    if(root->left_child==NULL)
        return root->info;
    else
        return Min_in_BST(root->left_child);
}
void show_leaves(struct tree_node *root)
{
    if(root==NULL)
        return;
    if(root->left_child==NULL && root->right_child==NULL){
        printf("%d, ",root->info);
        return;
    }
    if(root->left_child)
        show_leaves(root->left_child);
    if(root->right_child)
        show_leaves(root->right_child);
}
