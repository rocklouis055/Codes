#include<stdio.h>
#include<stdlib.h>
#define MAX 3

int f=-1,r=-1;
char q[MAX],e;

void display(){
	int i;
	if(f==-1){
		printf("\nERROR: UNDERFLOW!\n");
		return;
	}
	printf("\nElements are : f=");
	for(i=f;i!=r;i=(i+1)%MAX)
 		printf("%c, ",q[i]);
 	printf("r=%c.\n",q[i]);
}
void insert(){
	if(f==0 && r==MAX-1){
		printf("\nERROR: OVERFLOW!\n");
		return;
	}
	if(r==-1 && f==-1)
		f=0;
	r=(r+1)%MAX;
	printf("\nEnter the element : ");
	scanf(" %c",&e);
	q[r]=e;
}
void rem(){
	if(f==-1){
		printf("\nERROR: UNDERFLOW!\n");
		return;
	}
	printf("\nDeleted element is : %c",q[f]);
	if(f==r){
		f=-1;
		r=-1;
	}
	else
		f=(f+1)%MAX;
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
 
 	switch(o)
 	{
 		case 1: insert();
 				break;
 		case 2: rem();
 				break;
 		case 3: display();
 				break;
 		case 4: printf("Exiting....\n");
 				exit (0);
 		default:printf("Invalid option,select again!\n");
 	}}
 	return 0;
 }