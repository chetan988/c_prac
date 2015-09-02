#include<stdio.h>
#include<conio.h>

void remdup (char *,int,int,int,int );

void main () {
    char str[10];
    printf("get a string: ");
    gets(str);
    remdup(str,0,-1,strlen(str),strlen(str));
}

void remdup (char *st,int k,int n,int l,int m){
    int i,j;
  //  printf("st[%d] = %c\tl=%d\tm=%d\n",k,st[k],l,m);
    if(st[k] == '\0'){
  //      printf("\nst=%s\tl=%d\tm=%d\n",st,l,m);
        if(l == m){
  //          printf("here");
           return;
        }
        else
          remdup(st,0,-1,strlen(st),strlen(st));
    }
    if(n == -1){
         if(st[k] == st[k+1]){
            n=k;
          //  printf("n1=%d\n",n);
         }
       remdup(st,k+1,n,strlen(st),m);
    }
    else {
       if(st[k+1] == st[n])
          remdup(st,k+1,n,strlen(st),m);
        else{
          for(i=n,j=k+1;j<=l;i++,j++)
             st[i]=st[j];
          if(st[i] == '\0'){
             printf("st=%s\n",st);
             return;
          }
          k=n;
          n=-1;
          remdup(st,k+1,n,strlen(st),m);
        }
    }


}