#include<stdlib.h>
#include<stdio.h>
void dfs(){
  
}

void bfs(){
  
}

int main(){
  int n;
  printf("Enter Number of elements in the Graph : ");
  scanf("%d",&n);
  int g[n][n],v[n];
  printf("Enter the graph adjacency matrix %dx%d : ",n,n);
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      scanf("%d",g[i][j]);
    }
  }
}