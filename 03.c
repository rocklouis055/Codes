#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int ele,top=-1,i,o,stack[MAX],temp[MAX],c=0,t,k;

void display(){
	if(top==-1)
		printf("Error : STACK UNDERFLOW!\n\n");
	else{
		printf("Stack Elements are : ");
		for(i=top;i>=0;i--)
			printf("%d ",stack[i]);
		printf("\n");
	}
}

void push(int t3){
	if(top==MAX-1)
		printf("Error : STACK OVERFLOW!\n\n");
	else{
		top+=1;
		stack[top]=t3;
		printf("Pushed element is : %d\n\n",stack[top]);
		display();
	}
}
int pop(){
	if(top==-1)
		printf("Error : STACK UNDERFLOW!");
	else{
		printf("The popped element is : %d\n\n",stack[top]);
		t=stack[top];
		top-=1;
		display();
	}
	return(t);
}
void push2(int t4){
	top+=1;
	stack[top]=t4;
}
int pop2(){
	int z;
	z=stack[top];
	top-=1;
	return(z);
}
void chkpal(){
	int t6;
	if(top==-1)
		printf("\nError : STACK UNDERFLOW!\n\n");
	else{
		t6=top;
		for(i=0;i<=t6;i++)
			temp[i]=pop2();
		for(i=t6;i>=0;i--)
			push2(temp[i]);
		for(i=top;i>=top/2;i--)
			if(temp[i]!=temp[top-i]){
				c=1;
				break;
			}
		if(c==0)
			printf("\nPalindrome Stack\n");
		else
			printf("\nNOT a Palindrome Stack\n");
		c=0;			
	}
}

int main(){
int t2;
 while(1){
 	printf("\nOptions:\n");
 	printf("1. Push an element.\n");
 	printf("2. Pop an element.\n");
 	printf("3. Check Palindrome.\n");
 	printf("4. Display Stack elements.\n");
 	printf("5. Exit.\n\n");
 	printf("Select an option : ");
 	scanf("%d",&o);
 
 	switch(o){
 		case 1: printf("Enter the element to be push : ");
		scanf("%d",&t2);
 				push(t2);
 				break;
 		case 2: pop();
 				break;
 		case 3: chkpal();
 				break;
 		case 4: display();
 				break;
 		case 5: printf("Exiting....\n");
 				exit (0); 
 		default:printf("Invalid option,select again.\n");
 	}
  }
 	return 0;
 }
