#include<stdio.h>
#include<stdlib.h>

struct db{
	char usn[20];
	char name[20];
	char branch[20];
	int sem;
	long int phone;
	struct db *link;
};
typedef struct db *student;
student start=NULL,tail=NULL;
int size=0;

void tailfix(){
  tail=start;
  while(tail->link!=NULL)
			tail=tail->link;
}

student create(){
	student node;
	size+=1;
	node=(student)malloc(sizeof(struct db));
  if(node==NULL){
    printf("ERROR: Failed to allocate memory!\n");
    return(NULL);
  }
	printf("Enter details of the student(usn,name,branch,sem,phone) : ");
	scanf("%s%s%s%d%ld",node->usn,node->name,node->branch,&node->sem,&node->phone);
	return(node);
}

void icreate(){
	int n;
	printf("Enter the no of elements : ");
	scanf("%d",&n);
	student new,temp;
	new=start;
	for(int i=0;i<n;i++){
	  new=create();
		if(new==NULL){
			start=new;
		}
		else{
			new->link=start;
			start=new;
		}
	}
}

void display(){
  int i=0;
	student temp=start;
	if (size==0){
		printf("ERROR: Empty SSL!\n");
		return;
	}
	else{
		printf("Student details are : \n");
		while(temp!=NULL){
			printf("Student %d : %s %s %s %d %ld\n",i+1,temp->usn,temp->name,temp->branch,temp->sem,temp->phone);
			temp=temp->link;
			i+=1;
		}
    printf("The size of the SLL is : %d\n",i);
		return;
	}
}

void ibeg(){
  student temp=create();
  temp->link=start;
  start=temp;
  if (size==1)
    tail=start;
}

void iend(){
  if(size==0){
    start=create();
    tail=start;
  }
  else{
    tail->link=create();
    tail=tail->link;
  }
}

void dbeg(){
  if(size==0){
    printf("ERROR: Cant delete from empty SLL!\n");
    return;
  }
  else{
    size-=1;
    student temp;
    temp=start;
    start=start->link;
    //free(temp);
    return;
  }
}

student dend(){
  if(size==0){
    printf("ERROR: Cant delete from empty SLL!\n");
    return (NULL);
  }
  else if(size==1){
    size=0;
    student temp;
    temp=start;
    start=NULL;
    tail=NULL;
    return(temp);
  }
  else{
    size-=1;
    student temp=start;
    while(temp->link->link!=NULL)
      temp=temp->link;
    tail=temp;
    tail->link=NULL;
    return (temp);
  }
}

void pop(){
  student last=dend();
  if (last!=NULL){
    printf("Poped Student data are : %s %s %s %d %ld\n",last->usn,last->name,last->branch,last->sem,last->phone);
    //free(last);
  }
  else
    printf("ERROR: UNDERFLOW!\n");
  return;
}

int main(){
  student temp;
  int o;
  while(1){
    printf("\nOptions:\n");
    printf(" 1. Create SLL with n elements.\n");
    printf(" 2. Display all the elements and size.\n");
    printf(" 3. Insert on the beginning.\n");
    printf(" 4. Insert on the end.\n");
    printf(" 5. Delete from the beginning.\n");
    printf(" 6. Delete from the end.\n");
    printf("Stack Operatins:.\n");
    printf(" 7. Push.\n");
    printf(" 8. Pop.\n");
    printf(" 9. Exit\n\n");
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
      case 6: temp=dend();
          //free(temp);
          break;
      case 7: iend();
          break;
      case 8: pop();
          break;
      case 9: printf("Exiting....\n");
          exit (0);
      default:printf("Invalid option,select again.\n");
    }
  }
  return 0;
}