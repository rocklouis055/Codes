#include<stdio.h>

void move(int n,char a,char b,char c){
  if (n==1){
    printf("Move disc %d from %c to %c.\n",1,a,b);
    return;}
  else{
    move(n-1,a,c,b);
    printf("Move disc %d from %c to %c.\n",n,a,b);
    move(n-1,c,b,a);
  }
}
int main(){
  int n;
  printf("\nEnter the number of disc : ");
  scanf("%d",&n);
  move(n,'A','C','B');
}