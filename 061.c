#include<stdio.h>
#include<stdlib.h>
#define max 5

int f=0,r=0,n,c=0;
int q[max];

void insert(){
  if(c==max){
    printf("Overflow.\n");
    return;
  }
  printf("Enter the number : ");
  scanf("%d",&n);
  c+=1;
  q[r]=n;
  r=(r+1)%max;
}

void rem(){
  if(c==0){
    printf("Underflow.\n");
    return;
  }
  printf("\nDeleted Element is : %d\n",q[f]);
  f=(f+1)%max;
  c-=1;
}

void display(){
  if(c==0){
    printf("Underflow.\n");
    return;
  }
  printf("Queue elements are :");
  for(int i=0;i<c;i+=1)
    printf(" %d",q[(i+f)%max]);
  printf("\n");
}

int main(){
  int o;
  while(1){
   	printf("\nOptions:\n");
   	printf("1. Insert into the Circular Queue.\n");
   	printf("2. Delete from the Circular Queue.\n");
   	printf("3. Display the elements.\n");
   	printf("4. Exit.\n");
   	printf("Select an option : ");
   	scanf("%d",&o);
   
   	switch(o){
   		case 1: insert();
   				break;
   		case 2: rem();
   				break;
   		case 3: display();
   				break;
   		case 4: printf("Exiting....\n");
   				exit (0);
   		default:printf("Invalid option,select again!\n");
   	}
  } 
 	return 0;
}