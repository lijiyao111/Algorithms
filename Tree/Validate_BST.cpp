// C program for different tree traversals
#include <stdio.h>
#include <stdlib.h>
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
     int data;
     struct node* left;
     struct node* right;
};
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
     struct node* node = (struct node*)
                                  malloc(sizeof(struct node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;
 
     return(node);
}

// int a=0, *visited_data=&a;
// bool b=false, *flag_visited=&b;
 

 
/* Given a binary tree, print its nodes in inorder*/
bool printInorder(struct node* node)
{
    static int * visited_data=NULL;
    // static bool flag_visited=false;
     if (node == NULL){
          return true;
     }
 
     /* first recur on left child */
     if (!printInorder(node->left)) return false;
 
     /* then print the data of node */
     printf("%d \n", node->data);  
     if(visited_data)
        printf("%d %d\n",*visited_data,node->data);

     if(visited_data){
        if(*visited_data>node->data){
            return false;
        }
        visited_data=&(node->data);
     }

     if(!visited_data){
        visited_data=&(node->data);
     }


 
     /* now recur on right child */
     if(!printInorder(node->right)) return false;

     return true;


}
 

/* Driver program to test above functions*/
int main()
{
     // struct node *root  = newNode(4);
     // root->left             = newNode(2);
     // root->right           = newNode(5);
     // root->left->left     = newNode(1);
     // root->left->right   = newNode(3);
     struct node *root  = newNode(5);
     root->left             = newNode(14);
     // // root->right           = NULL;
     root->left->left     = newNode(1);
     // root->left->right   = NULL;
     /*
         1
        / \
       2   3
      / \
     4   5
     */ 
 
     // printf("\nPreorder traversal of binary tree is \n");
     // printPreorder(root);
 
     printf("\nInorder traversal of binary tree is \n");
     // printf("\n");
     printf("%d\n",printInorder(root));  
 
     // printf("\nPostorder traversal of binary tree is \n");
     // printPostorder(root);
 
}