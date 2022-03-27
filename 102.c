#include<stdio.h>
#include<stdlib.h>
struct BST
{
  struct BST *l;
  int data;
  struct BST *r;
}node;
struct BST *ptr,*root;
int menu();
void create();
void insert(struct BST *);
void inorder(struct BST *);
void preorder(struct BST *);
void postorder(struct BST *);
void search(struct BST *,int);
int main()
{
  int ca,key,d;
  printf("..Binary search tree operations..");
  do
  {
    ca=menu();
    switch(ca)
    {
      case 1    : create();
                  if(root==NULL)
                  root=ptr;
                  else
                  insert(root);
                  break;
      case 2    : printf("Inorder:\t");
                  inorder(root);
                  break;
      case 3    : printf("preorder:\t");
                  preorder(root);
                  break;
      case 4    : printf("Postorder:\t");
                  postorder(root);
                  break;
      case 5    : printf("enter the key to be searched:\t");
                  scanf("%d",&d);
                  search(root,d);
                  break;
      case 6    : exit(0);
      default  : printf("invalid choice");

    }
  }while(ca!=6);

}
int menu()
{
  int c;
  printf("\n1.create\n2.inorder\n3.preorder\n4.postorder\n5.searching\n6.exit\n");
  scanf("%d",&c);
  return c;
}
void create()
{
  ptr=(struct BST *)malloc(sizeof(struct BST));
  ptr->r=NULL;
  ptr->l=NULL;
  printf("enter number:");
  scanf("%d",&ptr->data);
}
void insert(struct BST *temp)
{
  int x;
  x=ptr->data;
  if(x>temp->data)
  {
    if(temp->r==NULL)
    temp->r=ptr;
    else
    insert(temp->r);
  }
  else
  {
    if(temp->l==NULL)
    temp->l=ptr;
    else
    insert(temp->l);
  }
}
void inorder(struct BST *temp)
{
  if(temp!=NULL)
  {
    inorder(temp->l);
    printf("\t%d",temp->data);
    inorder(temp->r);
  }
}
void preorder(struct BST *temp)
{
  if(temp!=NULL)
  {
    printf("\t%d",temp->data);
    preorder(temp->l);
    preorder(temp->r);
  }
}
void postorder(struct BST *temp)
{
  if(temp!=NULL)
  {
    postorder(temp->l);
    postorder(temp->r);
    printf("\t%d",temp->data);
  }
}
void search(struct BST *temp,int key)
{
  if(temp==NULL)
  printf("empty tree..");
  else
  {
    while(temp!=NULL)
    {
      if(temp->data==key)
      {
        printf("key found");
        return;
      }
      else if(key>=temp->data)
      temp=temp->r;
      else if(key<temp->data)
      temp=temp->l;
    }
    printf("key not found");
  }
}