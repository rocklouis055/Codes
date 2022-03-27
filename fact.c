#include<stdio.h>
#include<stdlib.h>
long long int fact(long int a){
  if (a<2)
  return(1);
  else
  return(a*fact(a-1));
}
int main(){
  for(long long int i=1;i<100;){
  printf("%lld\n",fact(i++));
  }
}