#include<stdio.h>
#include<conio.h>
void rmspace(char *);

int main(){
    char st[30];
    printf("Enter the string: ");
    gets(st);
    rmspace(st);
    printf("now from main :-%s-",st);
return 0;
}

void rmspace(char *str){

    int len,i=0,j=1;
    len=strlen(str);
    if(len ==0)
       return;
    printf("Got the string -%s-\n",str);
    printf("stripping leading space\n");
    if(str[0]==32){
       while(len != 0){
          while(j<len)
             str[i++] = str[j++];
          str[i]='\0';
          if(str[0]==32){
              i=0;
              j=1;
              len=strlen(str);
          }
          else
            break;
      }
    }
     printf("after processing string -%s-\n",str);
     printf("processing trailing space\n");
     len=strlen(str);
     while(len != 0){
         i=len-1;
         if(str[i] == 32){
             str[i]='\0';
             len = strlen(str);
         }
         else
           break;
     }
     printf("after processing string -%s-\n",str);
}
