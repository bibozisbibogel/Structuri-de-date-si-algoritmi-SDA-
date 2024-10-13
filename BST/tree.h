#ifndef CODE_SKELETON_TREES_TREE_H
#define CODE_SKELETON_TREES_TREE_H
struct tree_node {
    struct tree_node *left_child;
    struct tree_node *right_child;
    int info;
};

void insert_node(struct tree_node **root, int new_element_value);
void preorder(struct tree_node *root);
void postorder(struct tree_node *root);
void inorder(struct tree_node *root);
int search_node(struct tree_node *root, int searched_value);
struct tree_node* pop_node(struct tree_node *root, int searched_value);
int number_of_leaves(struct tree_node *root);
void show_leaves(struct tree_node *root);
int Max_in_BST(struct tree_node *root);
int Min_in_BST(struct tree_node *root);
#endif //CODE_SKELETON_TREES_TREE_H
