// search s2 in s1 and tell number of occurance and the places
#include<stdio.h>
#include<conio.h>

void search(char *,char *,int *);
int replace(char *, char *,char *,int *);
void main() {
   char str1[100],str2[20],str3[20];
   int occ[10], *ptr,i,ret;
   printf("ENTER FIRST STRING: ");
   gets(str1);
   printf("ENTER THE STRING TO BE SEARCHED: ");
   gets(str2);
   search(str1,str2,occ);
   if(occ[0] == -1) {
      printf("Searched string not found\n");
      return;
   }
/*
   for(i=0;i<10;i++)
       if(occ[i] != -1){
          printf("\nfound string at :%d\n",occ[i]);
       }
       else
          break;
*/
    printf("ENTER THE STRING TO BE REPLACE WITH %s : ", str2);
    gets(str3);
    ret = replace(str1,str2,str3,occ);
    if(ret !=1)
      printf("after replace string is : %s\n",str1);

}

int replace(char *s1,char *s2,char *s3, int *arr){
    int i=0,j=0,k=0,l,len1=strlen(s1),len2=strlen(s2),len3=strlen(s3),count =0;
    if(len3 ==0)
       return 0;  // nothing to replace
    if(len3 > len2) {
    for(i=0;i<10;i++)
        if(arr[i] != -1)
            count++;
    // calculate the space is sufficent or not bec s1 max size is 100
       if(len1 + (len3 - len2)*count >= 100)
       // can not accomodate return
           return 1;
    }
    for(i=0;i< len1;){
        if(arr[k] != -1 && k < 10){
           l= arr[k++];
            // now start replacing
            if(len3 > len2) {
            // handle case where s3 is greater than s2
                if(k >1)  // first replace is done so arr[k] loc has to be evaluate properly
                   l= l+(len3-len2)*(k-1);
                while(j<len2)
                   s1[l++] = s3[j++];
          //   printf("1-now string is : %s\n",s1);
                // now we have to move all char len3-len2 times and insert char
                j=len1+(len3-len2);
                printf("j=%d\tl=%d\n",j,l);
                while (j> l){   // move all char 1 place to right
                    s1[j]=s1[j-(len3-len2)];
                    j--;
                }
            //    printf("2-now string is : %s\n",s1);
                j=len2;
                while(j< len3)
                   s1[l++] = s3[j++];
             //   printf("3-now string is : %s\n",s1);
                i=l;
                j=0;
                len1=strlen(s1);
            //    printf("i=%d\ts3=%s\tlen=%d\n",i,s3,len1);
                continue;
            }
            if(len3 < len2){
                if(k>1)
                  l= l -(len2-len3)*(k-1);
                while(j < len3)
                    s1[l++] = s3[j++];   // copy the char
         //       printf("1-now string is : %s\n",s1);
                j=l+(len2-len3);
                while(j <= len1)
                    s1[l++] = s1[j++];
           //     printf("2-now string is : %s\n",s1);
                j=0;
                len1=strlen(s1);
          //      printf("i=%d\ts3=%s\n",i,s3);
                continue;
            }
            if(len3 == len2){
                while(j < len3)
                    s1[l++] = s3[j++];
           //      printf("1-now string is : %s\n",s1);
                j=0;
                continue;
            }

        }
        else
           break;

    }
 return 0;
}

void search(char *s1,char *s2,int *arr) {
    int len1=strlen(s1),len2=strlen(s2),i=0,j=0,k=0;
//    printf("string 1: %s\n",s1);
//    printf("string 2: %s\n",s2);
    for(i=0;i<10;i++)
        arr[i]=-1;
    if((len1<len2) || len2 == 0)
       return ;
    for(i=0;s1[i] != '\0';i++){
        if(s1[i] == s2[j]){   // matching
        //    printf("here-%c-%d\n",s2[j],i);
            j++;              // search for next str in s2
            if(j == len2) {  // if next char is null means all str matched
               arr[k++]=i-len2+1;  // store the loc of main str
                j=0;
            }
        }
        else
          j=0;                // did not match reset j val
    }
    return;
}