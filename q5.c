#include<stdio.h>

void PositionOfMinimum(int *values,int rows,int cols,int *row,int *col){
  int min=values[0];
  *row=*col=0;
  for(int i=1;i<rows*cols;i++)
  if(min>values[i]){
    *row=i/cols;
    *col=i%cols;
    min=values[i];
  }
}

int main(){
  int r,c;
  int a[15]={4,2,7,70,20,90,732,612,108,44,65,52,0,1,-1};
  PositionOfMinimum(a,5,3,&r,&c);
  printf("%d %d",r,c);
}