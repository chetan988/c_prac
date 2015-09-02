#include<stdio.h>
#include<conio.h>

void main() {
   char str[30];
   int len,i,j ;
   printf("Enter the string to check palendrum: ");
   gets(str);
   //start checking palendrum
   len=j=strlen(str)-1;
   for(i=0;i<= len/2;i++,j--){
      if(toupper(str[i]) == toupper(str[j])){}
      else
         break;

   }
   if(i >= j)
      printf("string is palendrum\n");
    else
      printf("string is not palendrum\n");
}