#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100

int top=0,i,j,t;
char stack[MAX]={'#'},inf[MAX],pf[MAX];

void push(int t3){
	if(top==MAX-1){
		printf("Error : STACK OVERFLOW!\nTerminating....\n");
    exit(0);
    }
	else{
		top+=1;
		stack[top]=t3;
	}
}

int pop(){
	if(top==-1){
		printf("Error : STACK UNDERFLOW!\nTerminating....\n");
    exit(0);
  }
	else{
		t=stack[top];
		top-=1;
	}
	return(t);

}
int pty(char a){
  if(a=='(')
    return(-1);
  if(a=='#')
    return(0);
  if(a=='-' || a=='+')
    return(1);
  if(a=='%'|| a=='/' || a=='*')
    return(2);
  if(a=='^')
    return(3);
}

int main(){
	printf("\nEnter the Infix expression : ");
	scanf("%s",inf);
	for(i=0,j=0;inf[i]!='\0';i++){
    if(isalnum(inf[i]))
      pf[j++]=inf[i];
    else if(inf[i]=='(')
      push('(');
    else if(inf[i]==')'){
      while(stack[top]!='(')
        pf[j++]=pop();
      pop();
    }
    else{
      while(pty(inf[i])<=pty(stack[top]))
        pf[j++]=pop();
      push(inf[i]);
    }}
    while(stack[top]!='#')
      pf[j++]=pop();
  printf("The Postfix expression is : %s\n",pf);
 	return 0;
 }