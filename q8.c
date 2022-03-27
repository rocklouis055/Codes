#include<stdio.h>
#include<string.h>
void DartBoard(char *board,int width,int height){
  for(int i=0;i<height;i++){
    for(int j=0;j<width+1;j++){
      if(((i==0 || i==height-1) && (j<width)) || (j==0 || j==width-1)){
        board[i*(width+1)+j]='#';
      }
      else if(j==width){
        board[i*(width+1)+j]='\n';
      }
      else if((i==height/2 || i==(height-1)/2)&&(j==width/2 || j==(width-1)/2))
        board[i*(width+1)+j]='O';
      else
        board[i*(width+1)+j]=' ';
    }
  }
  board[height*(width+1)]='\0';
}

int main(){
  char a[1000]="";
  DartBoard(a,1,1);
  printf("%s\n%ld",a,strlen(a));

}