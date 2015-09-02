#include<stdio.h>
#include<stdlib.h>

void swap (char *,char*);
void permute(char *,int ,int);
void allpermutation(char *,char *, int ,int);
void main() {
   char str[10],data[10];
   int len;
   printf("provide the string to generate the permutation\n");
   gets(str);
   len=strlen(str);
   permute(str,0,len-1);
   printf("\n\nall permutation with repetation\n\n");
   data[len]='\0';
   allpermutation(str,data,0,len-1);
}

void permute (char *s,int i,int n){
  int j;
  if (i==n) {
    printf("%s\t",s);
  }
  else {
    for(j=i;j<=n;j++){
      swap((s+i),(s+j));
    //  printf("temp s1 -> %s,i->%d,j->%d\n",s,i,j);
      permute(s,i+1,n);
      swap((s+i),(s+j));
    //  printf("temp s2 -> %s,i->%d,j->%d\n",s,i,j);
    }
  }
}

void swap(char *c1,char *c2) {
    char temp;
    temp=*c1;
    *c1=*c2;
    *c2=temp;

}

void allpermutation(char *str,char *data,int index,int len){
	int i;
	for(i=0;i<=len;i++) {
		data[index] = str[i];
		printf("index = %d i=%d str[i] =%c\n",index,i,str[i]);
		if(index == len)
			printf("  %s  ",data);
		else {
			allpermutation(str,data,index+1,len);
		}
			
	}
	
}
