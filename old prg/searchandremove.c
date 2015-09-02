#include<stdio.h>
#include<conio.h>

void main() {
    char str[20];
    int i=0,j=1,k;
    printf("get the string: ");
    gets(str);
    while (str[i] != '\0'){
        printf("str[%d] = %c\n",i,str[i]);
        if(str[i] == 'b'){
           k=i;
           while (str[k] !='\0'){
              str[k] = str[k+1];
              k++;
           }
           str[k]='\0';
       //    i++;
           printf("[1]str = %s\n",str);
        //   continue;
        }
        if(str[i] == 'a' && str[i+1] == 'c'){
           k=i;
           while (str[k+2] !='\0'){
              str[k] = str[k+2];
              k++;
           }
           str[k]='\0';
      //     i++;
      //     continue;
        }
        while(i >= 1 && str[i-1] == 'a' && str[i] == 'c'){
             k=i-1;
             while (str[k+2] !='\0'){
              str[k] = str[k+2];
              k++;
             }
           str[k]='\0';
        }
      i++;
    }
    printf("str = %s\n",str);
}