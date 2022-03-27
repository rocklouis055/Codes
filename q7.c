#include<stdio.h>

int CountNeuralValues(int *values,int numValues){
 int a[numValues],ca[10000][3],m,max=0,c;
 for(int i=0;i<numValues;i++){
   m=values[i]>0?values[i]:-values[i];
   values[i]>0?ca[m][1]++:ca[m][2]++;
   ca[m][0]++;
   max=max<m?m:max;
 }
 for(int i=0;i<=max;i++){
   if(ca[i][0]!=0 && ca[i][0]%2==0 && (ca[i][1]==ca[i][2]))
    c++;
 }
 return(c);
}

int CountNeuralValues2(int *values,int numValues){
 int c=0,t;
 for(int i=0;i<numValues;i++){
   t=values[i];
   if(values[i]){
    for(int j=i+1;j<numValues;j++){
      if(values[i]==values[j] || values[i]==-values[j]){
        t+=values[j];
        values[j]=0;
      }
    }
    if(t==0)
      c+=1;
    values[i]=0;
   }
 }
 return(c);
}


int main(){
  int a[7]={50,50,-50,-50,40,-40,60};
  printf("%d ",CountNeuralValues2(a,7));
}