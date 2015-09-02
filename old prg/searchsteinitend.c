#include<stdio.h>
#include<conio.h>

int sreachinit(char *,char *);
int searchend(char *,char*);

void main(){
    char str1[50],str2[20];
    int retval,k;
    printf("Get the first string: ");
    gets(str1);
    printf("get the second string to search: ");
    gets(str2);
    if(strlen(str1)< strlen(str2)) {
       printf("second string length is larger than first one\n");
       return;
    }
    printf("\nchoose your option:\n\n1-search the string in the begning\n2-search the string in the end\n");
    scanf("%d",&k);
    switch(k){
       case 1:
          retval=sreachinit(str1,str2);
          if(retval == 0 )
             printf("%s is found in the begning of %s\n",str2,str1);
          else
              printf("%s is not found in the begning of %s\n",str2,str1);
          break;
       case 2:
          retval = searchend(str1,str2);
          if(retval == 0 )
             printf("%s is found in the end of %s\n",str2,str1);
          else
              printf("%s is not found in the end of %s\n",str2,str1);
          break;
        default:
           printf("invalid option\n\n");
    }

}

int sreachinit(char *s1,char *s2){
    int len=strlen(s2),i=0,count=0;
    printf("str1-> %s\n",s1);
    printf("str2-> %s\n",s2);
    while (*s2 == *s1) { // && s2[i] != '\0' ){
       //printf("s2[%d] -> %c\n",i,*s2);
       s1++;
       s2++;
       i++;
    }
    if(i == len)
       return 0;
    return 1;
}

int searchend (char *s1,char *s2){
    int len1=strlen(s1),len2=strlen(s2),count=0;
     s1 = s1+(len1 - len2);
     while (*s1 == *s2 && count < len2) {
   //      printf("s2[%d] -> %c\n",count,*s1);
         count++;
         s1++;
         s2++;
     }
     if(count == len2)
       return 0;
    return 1;
}