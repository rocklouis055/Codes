#include<stdio.h>
#include<math.h>
double TimeDiffInHours(int minA,int secA,int minB,int secB){
  double SecDiff=(minB*60+secB)-(minA*60+secA);
  return(fabs(SecDiff/3600));
}

int main(){
  printf("\n%f %f %f",TimeDiffInHours(500,45,46,468),TimeDiffInHours(70,30,309,45),TimeDiffInHours(20,0,0,0));
}