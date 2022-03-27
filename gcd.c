#include <stdio.h>
int gcd(int,int);
 int main()
{
int m,n;
printf("enter the value m and n\n");
scanf("%d%d",&n,&m);
printf("gcd of number%d ",gcd(m,n));
return 0;
}
 
int gcd(int n ,int m )
{
  if(n==0)
  return m;
  if(m==0)
  return n;
  if(n>m)
  return(gcd (n%m,m));
  else
  return(gcd(n,m%n));

}