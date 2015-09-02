#include<stdio.h>
#include<conio.h>
//typedef enum { false, true } bool;
typedef int bool;
#define true 1
#define false 0
int interleave(char *,char *,char *);

void main() {
   char a[10],b[0],c[10];
   int i;
   printf("Enter A: ");
   gets(a);
   printf("Enter B: ");
   gets(b);
   printf("Enter C: ");
   gets(c);
   if(strlen(c) != strlen(a)+strlen(b))
    {   printf("[1]false\n");  return ;}
   i=interleave(a,b,c);
   printf("i=%d\n",i);
   if(i){
      printf("%c is interleave of %c and %c\n",c,a,b);
   }
   else
      printf("false\n");

}

int interleave(char *x,char *y,char *z){
    printf("a=%s\tb=%s\tc=%s\n",x,y,z);
        if (!(*x || *y || *z))
           return 1;
        if(*z='\0'){
            printf("here\n");
          return 0;
        }

        return (((*z == *x) && interleave(x+1,y,z+1)) || ((*z == *y) && interleave(x,y+1,z+1)));

}