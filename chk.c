#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
  int a=10234;
  printf("\n %d %d",a,(int)floor(log10(a)+1));
  auto b=10000.0000;
  printf("\n %f",b);

  return(0);
}