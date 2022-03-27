#include<stdio.h>
#include<stdlib.h>
#define MAX 10000
int H[MAX],max;
int hash(int k){
    if(H[k%max]==0)
        return(k%max);
    else
        return(hash(k+1));
}
int main(){
    printf("Enter the array size of the keys : ");
    scanf("%d",&max);
    int a[max];
    printf("Enter the keys of the employee : ");
    for(int i=0;i<max;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<max;i++)
        H[hash(a[i])]=a[i];
    printf("Employee Keys are : ");
    for(int i=0;i<max;i++)
        printf("%d ",H[i]);
    return(0);
}