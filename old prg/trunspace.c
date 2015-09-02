#include<stdio.h>
#include<conio.h>

void makeperfstr(char *);

void main(){
   char st[30];
   printf("get string :");
   gets(st);
   makeperfstr(st);
}

void makeperfstr(char *str) {
       int i=0,j=0,k,l;
       while(str[i] != NULL){
            if(str[i] == 32 && str[i+1] == 32){
             // get number of white space from first white space
        //     printf("i=%d\n",i);
             i++;
             k=0;
             j=i;
             while(str[j] != NULL){
                if(str[j]==32)
                   k++;
                else
                   break;
                // k contain the number of extra space that needs to be truncate
                j++;
            }
            j=i;
        //    printf("space=%d\n",k);
            l=i+k;
        //   printf("next start loc = %d\n",l);
            while(str[l] != '\0')
               str[j++] = str[l++];
            str[j]='\0';
       }
       i++;
    }
    printf("string == %s\n",str);
}