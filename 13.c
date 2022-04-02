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

int sum(){
  int sum=0;
  ll temp=start;
  while(temp!=NULL){
    sum+=temp->n;
    temp=temp->link;
  }
  return(sum);
}

int main(){
  int n;
  printf("Enter the no of elements : ");
	scanf("%d",&n);
  insert(n);
  printf("Sum of all the elements in the ll is : %d",sum());
  return 0;
}