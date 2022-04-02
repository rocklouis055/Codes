#include<stdlib.h>
#include<stdio.h>

void dfs(int *g,int *v,int c,int n){
  printf(" %d",c);
  v[c]=1;
  for(int i=0;i<n;i++)
    if(*(g+c*n+i) && !v[i])
      dfs(g,v,i,n);
}

void bfs(int *g,int *v,int c,int n){
  int f=-1,r=0;
  int q[n];
  printf(" %d",c);
  q[r++]=c;
  v[c]=1;
  while(r>f){
    for(int i=0;i<n;i++)
      if(*((g+c*n)+i) && !v[i]){
        v[i]=1;
        printf(" %d",i);
        q[r++]=i;
      }
    c=q[++f];
  }
}

int main(){
  int n;
  printf("Enter Number of elements in the Graph : ");
  scanf("%d",&n);
  int g[n][n],v[n];
  for(int i=0;i<n;v[i]=0,i++);
  printf("Enter the graph adjacency matrix %dx%d :\n",n,n);
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
      scanf("%d",&g[i][j]);
  printf("\nThe DFS order of the graph is :");
  dfs(*g,v,0,n);
  for(int i=0;i<n;v[i]=0,i++);
  printf("\nThe BFS order of the graph is :");
  bfs(*g,v,0,n);
  printf("\n");
  return(0);
}
