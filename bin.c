#include <stdio.h>

int main() {
  int i,n,first,last,mid,a[100] ,key,pos;
  printf("enter the number of element : ");
  scanf("%d",&n);
printf("enter the integer no : ");
for(i=0;i<n;i++)
scanf("%d", &a[i]);
printf(" enter the  value to find : ");
scanf("%d",&key);
first = 0;
last= n-1;
while(first<=last)
{
  mid=(first+last)/2;
  if(a[mid]== key)
  {
    pos = mid;
    printf("search is success to found at the postion %d",pos);
    return 0;
  }
  if(key<a[mid])
 last = mid -1;
 else 
 first =mid +1;
}
printf("search is unsuccessful");
}