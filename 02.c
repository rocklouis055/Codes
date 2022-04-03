#include<stdio.h>
#define MAX 50*50

char str[MAX],pat[MAX],rep[MAX];
int i,j,c=0,f=0,k;
int slen,plen,rlen;

int len (char a[MAX]){
	for(i=0;a[i]!='\0';i++);
	return(i);
}

void input(){
	printf("\nLength of all the strings should be less than or equal to 50.\n");
	printf("\nEnter the Main string (STR) : ");
	scanf("%s",str);
	printf("Enter the Pattern string  (PAT) : ");
	scanf("%s",pat);
	printf("Enter the Replace string (REP) : ");
	scanf("%s",rep);
	slen=len(str);
	plen=len(pat);
	rlen=len(rep);
}

void replace(){
	for(i=0,j=0;i<slen-plen+1;i++){
		for(j=0;j<plen && str[i+j]==pat[j];j++);
		if(j==plen){
			c+=1;
      f=rlen-plen;
			if(f>=0){
        for(k=slen;k>i;k--)
          str[k+f]=str[k];
        slen+=f;
        for(k=0;k<rlen;i++,k++)
          str[i]=rep[k];
			}
      else{
        f=-f;
        for(k=i;k<f+slen;k++)
          str[k]=str[k+f];
        slen+=f;
        for(k=0;k<rlen;i++,k++)
          str[i]=rep[k];
      }
      i-=1;
		}
	}
}

void msg(){
	if(c!=0){
		printf("\nReplaced %d occurance of %s.",c,pat);
		printf("\nThe new replaced string is %s.\n\n",str);
	}
	else
		printf("\nPattern %s not found in %s.\n\n",pat,str);
}
int main(){
	input();
	replace();
	msg();
	return(0);
}