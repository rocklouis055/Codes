#include<stdio.h>
#include<ctype.h>

int main(){
  int a[3][3]={1,2,3,4,5,6,7,8,9};
  int b[3][3]={1,2,3,4,5,6,7,8,9};
  int c[3][3];
  int k=0;
  int *m=a;
  int *n=b;
  printf("\n%d\n",*m+2);
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++){
      c[i][j]=0;
      for(int l=0;l<3;l++){
        c[i][j]+=*(*(a+i)+l) * *(*(b+l)+j); 
        }
  }
    for(int j=0;j<3;j++){
    for(int i=0;i<3;i++){
      printf("%d ",c[j][i]);
    }
    printf("\n");
    }
  
  return(0);
}