#include<stdio.h>
#include<stdlib.h>

struct db{
	char ssn[20],name[20],dept[20],des[20];
  long sal,phone;
	struct db *llink,*rlink;
};
typedef struct db *employee;
employee start=NULL,tail=NULL;
int size=0;

void tailfix(){
  tail=start;
  while(tail->rlink!=NULL)
			tail=tail->rlink;
}

employee create(){
	employee node;
	size+=1;
	node=(employee)malloc(sizeof(struct db));
  if(node==NULL){
    printf("ERROR: Failed to allocate memory!\n");
    return(NULL);
  }
	printf("Enter details of the Employee(ssn,name,department,designation,sal,phone) : ");
	scanf("%s%s%s%s%ld%ld",node->ssn,node->name,node->dept,node->des,&node->sal,&node->phone);
	return(node);
}

void icreate(){
	int n;
	printf("Enter the no of elements : ");
	scanf("%d",&n);
	employee new,temp;
	for(int i=0;i<n;i++){
	new=create();
		if(size==1){
      start=new;
      tail=new;
      new->rlink=NULL;
      new->llink=NULL;
		}
		else{
      tail->rlink=new;
      new->llink=tail;
      tail=new;
      new->rlink=NULL;
		}
	}
}

void display(){
  int i=0;
	employee temp=start;
	if (size==0){
		printf("ERROR: Empty DLL!\n");
		return;
	}
	else{
		printf("Employee details are : \n");
		while(temp!=NULL){
			printf("Employee %d : %s %s %s %s %ld %ld\n",i+1,temp->ssn,temp->name,temp->dept,temp->des,temp->sal,temp->phone);
			temp=temp->rlink;
			i+=1;
		}
    printf("The size of the DLL is : %d\n",size);
		return;
	}
}

void bdisplay(){
  int i=0;
	employee temp=tail;
	if (size==0){
		printf("ERROR: Empty DLL!\n");
		return;
	}
	else{
		printf("Employee details are : \n");
		while(temp!=NULL){
			printf("Employee %d : %s %s %s %s %ld %ld\n",i+1,temp->ssn,temp->name,temp->dept,temp->des,temp->sal,temp->phone);
			temp=temp->llink;
			i+=1;
		}
    printf("The size of the DLL is : %d\n",size);
		return;
	}
}

void ibeg(){
  employee temp=create();
  if (size==1){
    start=temp;
    tail=temp;
    tail->rlink=NULL;
    tail->llink=NULL;
    return;
  }
  temp->rlink=start;
  start->llink=temp;
  start=temp;
  if (size==1)
    tail=start;
}

void iend(){
  employee temp;
  if(size==0){
    start=create();
    tail=start;
  }
  else{
    temp=create();
    tail->rlink=temp;
    temp->llink=tail;
    tail=temp;
  }
}

void dbeg(){
  if(size==0){
    printf("ERROR: Cant delete from empty DLL!\n");
    return;
  }
  else if(size==1){
    start=NULL;
    tail=NULL;
    size-=1;
    return;
  }
  else{
    size-=1;
    employee temp;
    temp=start;
    start=start->rlink;
    start->llink=NULL;
    //free(temp);
    return;
  }
}

employee dend(){
  if(size==0){
    printf("ERROR: Cant delete from empty DLL!\n");
    return (NULL);
  }
  else if(size==1){
    size=0;
    employee temp;
    temp=start;
    start=NULL;
    tail=NULL;
    return(temp);
  }
  else{
    size-=1;
    employee temp=start;
    while(temp->rlink->rlink!=NULL)
      temp=temp->rlink;
    tail=temp;
    tail->rlink=NULL;
    return (temp);
  }
}

int main(){
  int o;
  while(1){
    printf("\nOptions:\n");
    printf(" 1. Create DLL with n elements.\n");
    printf(" 2. Display all the elements and size.\n");
    printf(" 3. Insert on the beginning.\n");
    printf(" 4. Insert on the end.\n");
    printf(" 5. Delete from the beginning.\n");
    printf(" 6. Delete from the end.\n");
    printf(" 7. Traverse backwards.\n");
    printf("Queue Operatins:.\n");
    printf(" 8. Insert on the front.\n");
    printf(" 9. Insert on the end.\n");
    printf(" 10. Delete from the front.\n");
    printf(" 11. Delete from the end.\n");
    printf(" 12. Exit\n");
    printf("Select an option : ");
    scanf("%d",&o);
  
    switch(o){
      case 1: icreate();
              tailfix();
          break;
      case 2: display();
          break;
      case 3: ibeg();
          break;
      case 4: iend();
          break;
      case 5: dbeg();
          break;
      case 6: (dend());
          break;
      case 7:bdisplay();
          break;
      case 8: ibeg();
          break;
      case 9: iend();
          break;
      case 10: dbeg();
          break;
      case 11: dend();
          break;
      case 12: printf("Exiting....\n");
          exit (0);
          break;
      default:printf("Invalid option,select again.\n");
    }
  }
  return 0;
}