#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define and &&
#define or ||

struct pol{
	float coff;
  int x,y,z;
  struct pol *next;
};
typedef struct pol *poly;
poly tail,h1,h2,h3;
int s1,s2,n;
poly create(){
  poly temp;
  temp=(poly)malloc(sizeof(struct pol));
  if(temp==NULL){
    printf("ERROR: Failed to allocate memory!\n");
    return(NULL);
  }
  temp->next=NULL;
  return(temp);
}

poly read(){
  poly temp,last;
  printf("Enter the number of terms : ");
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    temp=create();
    printf("Enter coefficient : ");
    scanf("%f",&temp->coff);
    printf("Enter exponent of x,y and z : ");
    scanf("%d %d %d",&temp->x,&temp->y,&temp->z);
    if(i==0){
      tail=temp;
      last=temp;
    }
    else{
      tail->next=temp;
      tail=temp;
    }
  }
  return(last);
}

void insert(float coff,int x,int y,int z){
  poly temp;
  if (coff!=0){
    if(h3->next==NULL){
      tail=h3->next=create();
    }
    else{
      temp=create();
      tail->next=temp;
      tail=tail->next;
    }
    tail->x=x;
    tail->y=y;
    tail->z=z;
    tail->coff=coff;
    tail->next=h3;
  }
}

void display(char i[],poly p){
  poly temp=p->next;
  printf("\nThe Polynomial %s is : ",i);
  while(temp!=p){
    printf("+%.1f(x**%d)(y**%d)(z**%d)",temp->coff,temp->x,temp->y,temp->z);
    temp=temp->next;
  }
}

float evaluate(poly p,int x,int y,int z){
  float sum=0;
  poly temp=p->next;
  while(temp!=p){
      sum+=temp->coff*pow(x,temp->x)*pow(y,temp->y)*pow(z,temp->z);
      temp=temp->next;
  }
  return(sum);
}

void add(poly h1,poly h2){
  poly temp1=h1->next,temp2=h2->next,temp3;
  while(temp1!=h1 or temp2!=h2){
    temp2=h2->next;
    while(temp2!=h2){
      if(temp2->coff!=0 and temp1->x==temp2->x and temp1->y==temp2->y and temp1->z==temp2->z){
        insert(temp1->coff+temp2->coff,temp2->x,temp2->y,temp2->z);
        temp2->x=temp2->y=temp2->z=temp2->coff=0;
        
        s1-=1;
        s2-=1;
        temp1=temp1->next;
        break;
      }
      temp2=temp2->next;
    }
    if(temp1==h1){
      while(temp2!=h2){
        if(temp2->coff!=0){
          s2-=1;
          insert(temp2->coff,temp2->x,temp2->y,temp2->z);
        }
        temp2=temp2->next;
      }
    }
    if(temp2==h2 and temp1->coff!=0){
      insert(temp1->coff,temp1->x,temp1->y,temp1->z);
      temp1=temp1->next;
      s1-=1;
    }
  }
  if(s2>0 and s1==0){
      temp2=h2->next;
      while(s2>0){
        if(temp2->coff!=0){
          insert(temp2->coff,temp2->x,temp2->y,temp2->z);
          s2-=1;
        }
        temp2=temp2->next;
      }
    }
}

int main(){
  int x,y,z;

  printf("\nEnter x,y and z : ");
  scanf("%d%d%d",&x,&y,&z);

  h1=create();
  h1->next=read();
  s1=n;
  n=0;
  tail->next=h1;
  display("1",h1);
  printf("\nEvaluated result is : %.2f\n\n",evaluate(h1,x,y,z));

  h2=create();
  h2->next=read();
  s2=n;
  n=0;
  tail->next=h2;
  display("2",h2);
  printf("\nEvaluated result is : %.2f\n\n",evaluate(h2,x,y,z));

  h3=create();
  add(h1,h2);
  display("1 + Polynomial 2",h3);
  printf("\nEvaluated result is : %.2f\n\n",evaluate(h3,x,y,z));
}
