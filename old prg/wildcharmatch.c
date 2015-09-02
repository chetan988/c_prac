#include<stdio.h>
#include<conio.h>

//int testfun(int x ) { return (x==5) || (x==6);}
int match (char *,char *);
void main(){
/*
int res;
res = testfun(5);
printf("res = %d\n",res);
res = testfun(6);
printf("res = %d\n",res);
res = testfun(7);
printf("res = %d\n",res);
*/

char str1[20],str2[30];
int res;
printf("enter string with wild char: ");
gets(str1);
printf("enter string witout wild charcter: ");
gets(str2);
res = match(str1,str2);
if(res == 0){
   printf("not matched\n\n");
}
else {
   printf("matched\n\n");
}
}

int match (char *s1,char *s2) {

  if(*s1 == '\0' && *s2 == '\0')
      return 1;
  if(*s1 == '?' || *s1 == *s2)
      return match(s1+1,s2+1);
  if(*s1 == '*')
      return (match(s1+1,s2) || match(s1,s2+1));
   return 0;
}