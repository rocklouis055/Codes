#include<stdio.h>
#include<stdlib.h>

int zeroindegree(int *indeg,int n,int *v){
  for(int i=0;i<n;i++)
      if(indeg[i]==0 && !v[i])
        return(i);
  exit(0);
}

void topsort(int *g,int n,int *indeg,int *v,int m){
  printf(" %d",m);
  v[m]=1;
  for(int i=0;i<n;i++)
    if(*(g+m*n+i))
      indeg[i]-=1;
  topsort(g,n,indeg,v,zeroindegree(indeg,n,v));
}

int main(){
  int n;
  printf("Enter the number of the vertices : ");
  scanf("%d",&n);
  int g[n][n],indeg[n],v[n];
  for(int i=0;i<n;v[i]=0,indeg[i]=0,i++);
  printf("Enter the Adjacency Marrix (DAG only) :\n");
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      scanf("%d",&g[i][j]);
      indeg[j]+=g[i][j];
    }
  printf("The Topological Sort order is :");
  topsort(*g,n,indeg,v,zeroindegree(indeg,n,v));
  return(0);
}
/*
Example :

Enter the number of the vertices : 7
Enter the Adjacency Marrix (DAG only) :
0 1 1 0 0 0 0 
0 0 1 0 0 1 0
0 0 0 1 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0 
0 0 0 1 1 0 0 
0 1 0 0 0 1 0
The Topological Sort order is : 0 6 1 2 5 3 4

*/
