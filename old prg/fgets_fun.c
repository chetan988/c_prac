/* this function to remove  all leading and trailling spaces from string given to it */

#include<stdio.h>
#include<conio.h>
void rmspace(char **);
void main(){

    char st[30];
    printf("enter a string: ");
    scanf("%s",st);
    printf("string: %s",st);
    rmspace(st);
}

void rmspace(char **str){
    int len=strlen(**str),i=0,j=1;
    if(len ==0)
      return;
printf("got stirng -%s- to strip\n",str);

while (i<len) {
    if(*str[j] == 32)
       *str[i]=*str[j];
i++;
j++;
}

}