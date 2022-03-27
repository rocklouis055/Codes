#include<stdlib.h>
#include<stdio.h>
int fibonacci( int ) ;
 int main( ){
 int num;
 int result;
 printf("Enter the nth number in series: ");
 scanf("%d",&num);
 if (num< 0)
 printf( "negat ive number is not poss ible. \n");
 else
 result = fibonacci(num);
 printf("The %d number in fibonacci series is %d\n", num, result);
 return(0);
 }
 int fibonacci(int num){
 if (num==0)
 return 0;
 else if (num==1)
 return 0;
 else
 return (fibonacci(num)+fibonacci(num-1));
 }