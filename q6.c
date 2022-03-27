#include<stdio.h>

void SwapAdjacent(char *words){
  char t;
  for(int i=0;words[i+1];i+=2){
    t=words[i];
    words[i]=words[i+1];
    words[i+1]=t;
  }
}

int main(){
  char m[100]={"we are open!"};
  SwapAdjacent(m);
  printf("%s\n",m);
}