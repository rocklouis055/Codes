#include<stdio.h>
#include<stdlib.h>

struct tree{
  int data;
  struct tree *left;
  struct tree *right; 
};
typedef struct tree *bst;
bst start;

bst create(){
  int v;
  bst temp;
  temp=(bst)malloc(sizeof(struct tree));
  temp->data=v;
  temp->left=temp->right=NULL;
  return(temp);
}

void insert(int v,bst temp){
  if(v<=temp->data){
    if(temp->left!=NULL)
      insert(v,temp->left);
    else{
      temp->left=create();
      temp->left->data=v;
    }
  }
  else if(v>temp->data){
    if(temp->right!=NULL)
      insert(v,temp->right);
    else{
      temp->right=create();
      temp->right->data=v;
    }
  }
}

void inorder(bst temp){
  if(temp->left!=NULL)
    inorder(temp->left);
  printf("%d ",temp->data);
  if(temp->right!=NULL)
    inorder(temp->right);
}

void preorder(bst temp){
  printf("%d ",temp->data);
  if(temp->left!=NULL)
    inorder(temp->left);
  if(temp->right!=NULL)
    inorder(temp->right);
}

void postorder(bst temp){
  if(temp->left!=NULL)
    postorder(temp->left);
  if(temp->right!=NULL)
    postorder(temp->right);
  printf("%d ",temp->data);
}

void search(int v,bst temp){
  if(v==temp->data)
    printf("Key present in the BST.\n\n");
  else if(v<=temp->data){
    if(temp->left==NULL)
      printf("NOT FOUND IN THE BST.\n\n");
    else
      search(v,temp->left);
  }
  else if(v>temp->data){
    if(temp->right==NULL)
      printf("NOT FOUND IN THE BST.\n\n");
    else
      search(v,temp->right);
  }
}

void delete(int v,bst temp){

}

int main(){
  int o,v;
  while(1){
    printf("Binary Search Tree (BST)\n");
    printf("1.Create Root node.\n");
    printf("2.Insert.\n");
    printf("3.Inorder.\n");
    printf("4.Preorder.\n");
    printf("5.Postorder.\n");
    printf("6.Search.\n");
    printf("7.Delete a node.\n");
    printf("8.Exit.\n");
    printf("Choose an Option : ");
    scanf("%d",&o);
    switch(o){
      case 1: printf("\nEnter the value to be inserted : ");
              scanf("%d",&v);
              start=create();
              start->data=v;
              break;
      case 2: printf("\nEnter the value to be inserted : ");
              scanf("%d",&v);
              insert(v,start);
              break;
      case 3: printf("\nInorder Series is : ");
              inorder(start);
              printf("\n\n");
              break;
      case 4: printf("\nPreorder Series is : ");
              preorder(start);
              printf("\n\n");
              break;
      case 5: printf("\nPostorder Series is : ");
              postorder(start);
              printf("\n\n");
              break;
      case 6: printf("\nEnter the element to be search : ");
              scanf("%d",&v);
              search(v,start);
              break;
      case 7: printf("\nEnter the element to be deleted : ");
              scanf("%d",&v);
              delete(v,start);
              break;
      case 8: printf("Exiting.....\n\n"); 
              exit(0);
      default: printf("Invalid value selected! Try again.\n\n");
    }
  }
  return(0);
}