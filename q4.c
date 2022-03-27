#include<stdio.h>
#include<math.h>

int NotebookRacksRequired(int delegates,int firstHour,int unusedNotebooks,int notebooksPerRack){
  return((delegates*(1+firstHour)-unusedNotebooks)/notebooksPerRack+1);
}

int main(){
  printf("\n%d %d %d",NotebookRacksRequired(51,1,7,9),NotebookRacksRequired(24,0,4,13),NotebookRacksRequired(13,0,0,12));
}