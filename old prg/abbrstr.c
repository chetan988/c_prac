#include<stdio.h>
#include<conio.h>

int main() {
   char st[30],abb[10];
   int i=0,j=0;
   printf("get the string:");
   gets(st);
   while(st[i] != NULL){
      if(i==0 && ((st[i] > 64 && st[i] < 91)||(st[i]>96 && st[i] <123)))
        abb[j++] = st[i];
      if(st[i] == 32 && ((st[i+1] > 64 && st[i+1] < 91)||(st[i+1]>96 && st[i+1] <123)))
         abb[j++]=st[i+1];
      i++;
   }
   abb[j]='\0';
   printf("abbrivation: %s\n",abb);
}