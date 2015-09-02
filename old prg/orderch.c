#include <stdio.h>
#include <stdlib.h>
void orderch(char *);
int main()
{
	char st[30];
	printf("get the string: ");
	gets(st);
    orderch(st);
	return 0;
}

void orderch(char *str) {
    int i,j,len,temp1=0,temp2=0;
    char temp;
    printf("got the string %s\n",str);
    len=strlen(str);
//    printf("len=%d\n",len);
    for(i=0;i<len;i++){
        if(str[i] <65 || (str[i] > 90 && str[i] < 97) || str[i] >122 ){
   //         printf("debug-1\n");
            continue;
        }
      for(j=i+1;j<len;j++){
           if(str[j] <65 || (str[j] > 90 && str[j] < 97) || str[i] >122 ){
   //            printf("debug-2\n");
              continue;
           }
           if(str[i] > 64 && str[i] < 91) temp1= (str[i])+32;
           else temp1=str[i];
           if(str[j] > 64 && str[j] < 91) temp2= (str[j])+32;
           else temp2=str[j];
           if(temp1 > temp2){
               temp=str[i];
               str[i]=str[j];
               str[j]=temp;
             //  str[i]=temp1;
             //  str[j]=temp2;
           }
      }

    }
    printf("string= %s\n",str);
}