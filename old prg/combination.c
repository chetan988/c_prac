#include<stdio.h>
#include<conio.h>

void combination (int *,char *,int,int);

char code[][5] = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
char out[] = {'\0','\0','\0','\0','\0'};
void main(){
  int st[3]={0,4,5};
  int ln;
  char ch;
  ln= sizeof(st)/sizeof(st[0]);
  printf("%d\n",ln);
  combination(st,out,0,ln);

}

void combination (int *s,char *out,int l,int n){
   int i;
 //  printf("here\n");
   if(l==n){
       printf("%s\t",out);
       return;
   }
   for(i=0;i< strlen(code[s[l]]);i++){
      out[l] = code[s[l]][i];
      combination(s,out,l+1,n);
   }
}