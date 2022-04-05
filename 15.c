#include<stdio.h>
#include<stdlib.h>

struct db{
	int n;
	struct db *link;
};
typedef struct db *ll;
ll start=NULL,tail=NULL;
int size=0;


ll create(){
	ll node;
	size+=1;
	node=(ll)malloc(sizeof(struct db));
  if(node==NULL){
    printf("ERROR: Failed to allocate memory!\n");
    return(NULL);
  }
  node->link=NULL;
  scanf("%d",&node->n);
	return(node);
}

void insert(int n){
  printf("Enter the elements : ");
	ll new,temp;
	new=start;
	for(int i=0;i<n;i++){
	  new=create();
		if(start==NULL){
			start=new;
      tail=new;
		}
		else{
			tail->link=new;
      tail=new;
		}
	}
}

int product(int n,int k){
  int d=n-k,mul=1;
  ll temp=start;
  if (d<0){
    printf("ERROR! Value %d is greater than the size %d.\n",k,n);
    exit(0);
    }
  else{
    for(int i=0;i<d;i++,temp=temp->link);
    for(;temp;mul*=temp->n,temp=temp->link);
    return(mul);
  }
}

int main(){
  int n,k;
  printf("Enter the no of elements : ");
	scanf("%d",&n);
  insert(n);
  printf("Enter the no of elements you want to multiply from the last : ");
  scanf("%d",&k);
  printf("Product of the last %d elements is : %d\n",k,product(n,k));
  return 0;
}
/*
Example :
  nter the no of elements : 5
  Enter the elements : 1 2 3 4 5
  Enter the no of elements you want to multiply from the last : 5
  Product of the last 5 elements is : 120
    
  Enter the no of elements : 5
  Enter the elements : 1 2 3 4 5
  Enter the no of elements you want to multiply from the last : 6
  ERROR! Value 6 is greater than the size 5.

  Enter the no of elements : 5
  Enter the elements : 1 2 3 4 5
  Enter the no of elements you want to multiply from the last : 6
  ERROR! Value 6 is greater than the size 5.
*/    