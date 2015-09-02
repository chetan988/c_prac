#include<stdio.h>
#include<conio.h>

int lcstr(char *,char*,int,int);
int max(int a,int b);
int max(int a,int b){ return ((a > b) ? a : b);}
void main () {
   char str1[20],str2[20];
   int len1,len2,cl;

   printf("Enter str1:" );
   gets(str1);
   printf("Enter str1:" );
   gets(str2);
   len1 = strlen(str1);
   len2 = strlen(str2);
   cl=lcstr(str1,str2,len1,len2);
   printf("common string lenght = %d\n",cl);
}

int lcstr(char *x,char *y,int m,int n){
// create a 2d array to store the matching char
   int cl[m+1][n+1],result=0,i,j;
   for(i=0;i<=m;i++){
     for(j=0;j<=n;j++){
        if(i==0 || j==0) {
           cl[i][j] = 0;
     }
     else if(x[i-1] == y[j-1]){
         cl[i][j] = cl[i-1][j-1] + 1;   // if previous is match then increment
         result = max(result,cl[i][j]);
     }
     else
        cl[i][j]=0;

   }
   }
   printf("\n\n");
   for(i=0;i<=m;i++){
     for(j=0;j<=n;j++){
        printf("%d\t",cl[i][j]);
     }
     printf("\n");
   }
   return result;
}