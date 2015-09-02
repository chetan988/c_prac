#include<stdio.h>
#include<conio.h>
int wordCount(char *);
int wordCount(char *s) {
//printf("got s = %s\n",s);
    int flag=1,count=0;
    while (*s != '\0'){
    //    printf("got *s = %c\n",*s);
        if(flag == 1 && !(*s == ' ' || *s == '\t' || *s == '\n')){
          flag =0;
          count++;    // next char after space
       }
       if((*s == ' ' || *s == '\t' || *s == '\n') ) {  //continious space or tab or new lines
            flag =1;
       }
       /*
       if(flag ==1 ) { // if here that means after space there is a valid character
           count++;
           flag = 0;
       }
     */
     s++;
    }
    printf("count=%d\n",count);
    return count;
}

void main() {

  char str[30];
  int count;
  printf("Enter the string: ");
  gets(str);
  count = wordCount(str);
  printf("String has %d words\n",count);
}