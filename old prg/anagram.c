#include<stdio.h>
#include<conio.h>
void sort(char **);
void main() {
  char tstr[10][20],*str[10],*pstr[10],ch;
  int ind[10],i;
  i=0;
  do{
    printf("Enter a word: ");
    gets(tstr[i]);
    str[i]=pstr[i]=&tstr[i];
  //  printf("do you want to continue?\n");
 //   ch=getch();
  //  getch();
  //  if(ch == 'y' || ch == 'Y')
        i++;
  //  else
  //     break;
  } while (i<5);
  for(i=0;i<5;i++){
        printf("str[%d] = %s\n",i,str[i]);
  }
  for(i=0;i<5;i++){
        printf("pstr[%d] = %s\n",i,pstr[i]);

  }

  sort (str);


}
void sort(char **st){
    int i,j=0,k;
    char ch;
    for(i=0;i<5;i++)
    {
       for(j=0;j<20 && st[i][j] !='\0';j++){
/*         for(k=0;k<20 && st[i][k] !='\0';k++){
            if(st[i][j] < st[i][k]){
               ch = st[i][j];
               st[i][j] = st[i][k];
               st[i][k]=ch;
               printf("%c\n",ch);
            }
         }*/
printf()

       }
    }
  for(i=0;i<5;i++){
        printf("st[%d] = %s\n",i,*st[i]);
  }
}
