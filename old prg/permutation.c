#include<stdio.h>
#include<stdlib.h>

void swap (char *,char*);
void permute(char *,int ,int);

void main() {
   char str[10];
   int len;
   printf("provide the string to generate the permutation\n");
   gets(str);
   len=strlen(str);
   permute(str,0,len-1);

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