#include<stdio.h>
#include<math.h>

int IsComposite(int number){
  int f=0;
  if(number<2)
    return(0);
  for(int i=2;i<=sqrt(number);i++)
    if(number%i==0){
      f=1;
      break;
    }
  return(f);
}

int main(){
  printf("\n%d %d %d",IsComposite(2),IsComposite(1),IsComposite(8));
}