#include <stdio.h>
#include <stdlib.h>

int n,i;
int o,e,l;
int arr[1000];

void create(){
  printf("Enter the elements : ");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
}

void display(){
  printf("\nElements are : ");
  for(i=0;i<n;i++)
    printf("%d ",arr[i]);
  printf("\n");
}

void insert(){
  printf("\nEnter the element : ");
  scanf("%d",&e);
  printf("Enter the location for the element : ");
  scanf("%d",&l);
  for(i=n;i>l-1;i--)
    arr[i]=arr[i-1];
  n+=1;
  arr[i]=e;
  display();
}

void rem(){
  printf("Enter the location of the element : ");
  scanf("%d",&l);
  for(i=l-1;i<n;i++)
    arr[i]=arr[i+1];
  n-=1;
  display();
}

int main() {
  while(1){
    printf ("\nOptions:\n");
    printf("1. Create an array.\n");
    printf("2. Display all the elements.\n");
    printf("3. Insert at a particular locaion.\n");
    printf("4. Delete an element from a location.\n");
    printf("5. Exit.\n\n");
    printf("Select an option : ");
    scanf ("%d" ,&o);

    switch(o){
      case 1: printf("\nEnter the size of the array : ");
              scanf("%d",&n);
              create();
              break;
      case 2: display();
              break;
      case 3: insert();
              break;
      case 4: rem();
              break;
      case 5: printf("Exiting.....\n");
              exit(0);
      default:printf("Invalid option,select again.\n");
    }
  }
  return 0;
}