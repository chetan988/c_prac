#include<stdio.h>
#include<conio.h>

void lcs(char *,char*, int, int);
int max (int,int);
void main (){
    char str1[10],str2[10];
    int l1,l2;
    printf("entre two string: ");
    gets(str1);
    gets(str2);
    l1=strlen(str1);
    l2=strlen(str2);
    lcs(str1,str2,l1,l2);

}

void lcs(char *s1,char *s2,int m, int n){
    int l[m+1][n+1];
    int i,j,index;
    char lcs[10];
    for (i=0;i<=m;i++){
       for(j=0;j<=n;j++){
          if(i==0 || j==0)
             l[i][j]=0;
          else if(s1[i-1] == s2[j-1])
              l[i][j] = l[i-1][j-1] +1;
          else
              l[i][j] = max(l[i-1][j],l[i][j-1]);
          printf("%d\t",l[i][j]);
       }
       printf("\n");
    }
    index = l[m][n];
    i=m;
    j=n;
    lcs[index] = '\0';
    while(i > 0 && j > 0) {
       if(s1[i-1] == s2[j-1]){
          lcs[--index]=s1[i-1];
          i--; j--;
       }
       else if(l[i-1][j] > l[i][j-1])
           i--;
       else
           j--;
    }
    printf ("longest common string of %s and %s is %s",s1,s2,lcs);
}

int max(int a,int b){
   return (a > b ? a : b);
}