#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define MAX 100

int top=-1,i;
double t,o1,o2;
double s[MAX];
char pf[MAX];

void push(double t3){
    if(top==MAX-1){
        printf("Error : STACK OVERFLOW!\nTerminating....\n");
    exit(0);
    }
    else{
        top+=1;
        s[top]=t3;
    }
}

double pop(){
    if(top==-1){
        printf("Error : STACK UNDERFLOW!\nTerminating....\n");
    exit(0);
  }
    else{
        t=s[top];
        top-=1;
    }
    return(t);

}

double eval(char o){
o1=pop();
o2=pop();
    switch(o){
    case '+':return(o2+o1);
    case '-':return(o2-o1);
    case '*':return(o2*o1);
    case '/':return(o2/o1);
    case '%':return(fmod(o2,o1));
    case '^':return(pow(o2,o1));
    default:printf("\nERROR: INVALID EXPRESSION!\nTerminating....");
    exit(0);
    }
}
int main(){
    printf("\nEnter the Postfix expression : ");
    scanf("%s",pf);
    for(i=0;pf[i];i++){
        if(isdigit(pf[i]))
            push(pf[i]-'0');
        else
            push(eval(pf[i]));
    }
      printf("After Evaluation,the result is : %.2lf\n",pop());
     return 0;
 }

