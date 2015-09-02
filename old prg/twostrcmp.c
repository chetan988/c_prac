#include<stdio.h>
#include<conio.h>
char * checkstr(char *,char *);

void main(){
  char st1[30],st2[30];
  char *ct;
  printf("Enter string1: ");
  gets(st1);
  printf("Enter the second :");
  gets(st2);
  ct=checkstr(st1,st2);
  printf("ct = %s\n",ct);
}

char * checkstr(char *str1,char *str2){

  int len1,len2,i=0,j=0,flag=-1;
  len1=strlen(str1);
  len2=strlen(str2);
//  printf("str1=%s->len=%d->str2=%s->len2=%d\n",str1,len1,str2,len2);
  if(len2 > len1)
     return;
  while(i<len1){
     if(str1[i] == str2[j] && j<len2){
         // if here we are here char match found
         // now increment both count till it matchs if failed
         // go out and reset j and flag
         if(flag == -1)
              flag=i;
         j++;
         i++;
         continue;
     }
     // if it here it may be a match or search still going
     if(j == len2){
         printf("flag=%d\n",flag);
         return (&str1[flag]);
     }
     else {
       j=0;
       flag=-1;
       i++;
     }
  }
  // if comes out that means match not found
  if(j == len2){
         return (&str1[flag]);
  }
  return NULL;
}