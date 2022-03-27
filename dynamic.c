#include<stdio.h>
#include<stdlib.h>
int main(){
  int b[10];
  int *a=(int*)calloc(100,4);
  printf("%ld",sizeof(a));
  free(*a);
  printf("\n%ld",sizeof(*a));
  char *c=(char*)malloc(10*sizeof(char));
  printf("\n%ld",sizeof(c));
  double *d=(double*)malloc(10*sizeof(double));
  printf("\n%ld",sizeof(d));
  return(0);
}