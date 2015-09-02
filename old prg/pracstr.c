#include<stdio.h>
#include<conio.h>

void reverse(char *);
void nreverse(char *,int,int);
void extract(char st[],int,int);
void encrypt(char *);
void decrypt(char *);
void convert_num_word(int);
void fun(char ch[]);
char *num_in_char[10] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
char *decimal[4] = {"","","HUNDRED","THOUSAND"};
int lstrlen(char *);
void lreverse(char *);
void fun1(char *);
void fun2(char *);
int strcmpic(char *,char*);
int main () {

 // char ch1[]="hello\n";
//  char ch2[]="india\n";
//    char *str1="hello";//&ch1;
//    char *str2="india";//&ch2;
//    strcpy(str1,str2);
//  printf("str=%s\n",str1);
/*  char name[20];
  puts("enter name");
  gets(name);
  printf("name is:");
  puts(name);
*/

/* 2d array to store str using malloc

char *nameset[5],*str;
int i;

for (i=0;i<5;i++){
  printf("Enter name :");
  gets(str);
  nameset[i] = (char *) malloc ((strlen(str)*sizeof(char))+1);
  strcpy(nameset[i],str);
}

for (i=0;i<5;i++){
    printf("\nname : \n");
    puts(nameset[i]);
}

*/
/* reverse a string and reverse n number of string

char str[50];
int start,last;
int x=y=6;
printf("Eneter a string to reverse: ");
gets(str);
printf("input string : ");
puts(str);
reverse(str);
printf("after reversal string is: ");
puts(str);
printf("\nreverse a portion of string\n");
printf("you have : ");
puts(str);
printf("Enter the start and end point of reversal: ");
scanf("%d %d",&start,&last);
if (start > last){
   printf("not valid start and last value\n");
   return 1;
}
if(last > strlen(str)){
    printf("last value exceeding string length\n");
    return 1;
}

printf("piece of string that we are going to reverse: ");
extract(str,start,last);
printf("####\n");
nreverse(str,start,last);
printf("after reversal string is : ");
puts(str); */

/*  print each word in string
char str[50];
int i=0;
printf("Enter a string: ");
gets(str);
int first=0;
while (str[i] != '\0'){
     if(isspace(str[i]) && first == 0){
         i++;
         continue;
     }

     first=1;
     if(isspace(str[i])) printf("\n");
     else putchar(str[i]);
    // printf("i=%d\n",i);
     i++;

}  */

/* print all alpha numerical character in string and its occurace ignore case

char str[50];
int i=0,charset[36],temp;
for (i=0;i<36;i++)
   charset[i]=0;
printf("enter a string: ");
gets(str);
i=0;
while(str[i]!= '\0'){
    temp = str[i];
    printf("str[%d]=%c\ttemp=%d\n",i,str[i],temp );
    if(temp < 9) charset[temp]++;
    if(temp > 64 && temp < 91) charset[temp-55]++;
    if(temp > 96 && temp < 123) charset[temp-87]++;
    i++;
}
    for (i=0;i<36;i++) {
      if(charset[i] != 0){
       if((i<10))
           printf ("%c  ---> %d\n",i,charset[i]);

       else
         printf("%c  ---> %d\n",i+55,charset[i]);
      }
    }
*/

/* encrypt the string with next char a->b z->a

char str[50];
int i=0;
printf("enter the string :");
gets(str);
encrypt(str);
printf("after encryption str is : %s\n\n",str);
printf("decrypting now....\n");
decrypt(str);
printf("after decryption str is : %s\n\n",str);    */
/* number to charcter representation
int i;
printf("Enter a four digit number: ");
scanf("%d",&i);
convert_num_word(i);
*/
/*  tricky questions  */
/*  qestion -1
char *str;
gets(str);
puts(str);  // str is unintitialized pointer so gets(str) will take the value but will not store
            // and puts will restut core dump for illigal memory access (run time error)
*/
/*  ques -2
char str[]="hello";
char *p;
//str=str+1; // comple time error :- str is a arry of char and array is constant pointer so address manipulation not allowed
//str = "hi"; // again constant pointer can not modify address as "hi" base add will be diff
str[2]='i'; // possible because modifing the value at the address
p=str;
p="hi";    // this is possible because p is not constant pointer
puts(str);
puts(p);
*/

/* ques-3
char ch[]="hello";
fun(ch);
*/
/*  ques-4
// q:4:prc char *p="cheTan";
char ch[] = "cheTan";
char *p=ch;   //  now p is writable
*(p+3)='t';   // q:4:prc1 is non writable pointer can not modify the value
ch[3]='t';
puts(p);
puts(ch);
 */

 /*que -5
printf("%c\n","chetan"[2]);   // same as ch[]="chetan"; ch[2];
printf("%c\n",*("chetan"+2)); //  -do-
printf("hichetan"+2);
printf("\n");
printf("hichetan das"+strlen("hi") );
*/

/*  ques -6
char str[]="cheTan";
char *p=str+1; //"heTan"
p[2]='t';      // "hetan"
puts(p);       // hetan
puts(str);     // chetan  //because pointer directly modify the value
*/

/* ques -7
/* make strcpt to behave like strcmp
char str1[]="hello ";
char str2[]="chetan";

strcpy(str1+strlen(str1),str2); // hello chetan because strcpy will copy from str1+its length to str2
puts(str1);
*/
/*  ques - 8
char str[]="chetan";
char str1[]="chetan";
if(str == str1)     //  comparing address not value
   puts("same");
else
   puts("different");    // ans diff
   */
   /* ques -9
char ch[10];
ch = "chetan";  // not allowed as ch is constant pointer and we are trying assigning ch to start address of "chetan" string so error
*/
/*quest 10
char ch[]="hello";
char ch1[] = {'h','e','l','l','o'};
if(strcmp(ch,ch1) == 0)
    printf("same\n");
else
    printf("diff\n");  // should come diff because ch1 did not end will null but here coming same :P
*/
/* quest 11
char ch1[]="das";
char ch2[]="chetan";
if(strlen(ch1)-strlen(ch2) >=0)
   puts(ch1);              // o/p - das (always will be) because strlen return unsigned int so if negative comes it will convert to positive so expression will be always true
else
   puts(ch2);
*/

/*quest 12  solution to quest 11
char ch1[]="das";
char ch2[]="chetan";
if((int)(strlen(ch1)-strlen(ch2)) >=0)
   puts(ch1);           // op-chetan thid time it will work
else
   puts(ch2);
   */
/*    quest 13 sol to quest 11
char ch1[]="das";
char ch2[]="chetan";
if(strlen(ch1)>= strlen(ch2))
   puts(ch1);           // op-chetan thid time it will work
else
   puts(ch2);
*/
/*    quest 14
char *str[3];  // we declare here but did not initialized it
int i;
for(i=0;i<3;i++)
    scanf("%s",str[i]);     // will core dump becuse str is not initialized
for(i=0;i<3;i++)
    printf("%s\n",str[i]);
*/
/*  quest 15 solution to quest 14
char *str[3];  // we declare here but did not initialized it
int i;
for(i=0;i<3;i++){
    str[i] = (char *) malloc (20 * sizeof(char));  // we reserve 20 address and assign the strting add to str[i]
    gets(str[i]);
}
for(i=0;i<3;i++)
    printf("%s\n",str[i]);
    */
    /*quest 16    */
    /* create a lstrlen api to return string length
    int len = lstrlen("chetan");
    printf("length = %d\n",len);
    */

    /* quest 17 reverse a string using recursion
     char str[20],rstr[20];
     puts("Enter string to be reversed");
     gets(str);
     lreverse(str);
*/
/* quest 18
     char str[]="chetan";
     puts(str);
     fun1(str);
     puts(str);  // after returing from fun1 str is stll "chetan" because st is local to fun1 and we changed the address stored in st
     fun2(str);
     puts(str);  // here changes will reflect because changes are done on the address it self
    */

    /*questions */

    /* convert a sting to uppercase */

    /* write a function to perform case insensitive match */
    char str1[20];
    char str2[20];
    int i,j=0;
    printf("ENTER TWO STRING TO COMPAIRE:\n");
    gets(str1);
    gets(str2);
    printf("%d\t%d\n",strlen(str1),strlen(str2));
    i = strcmpic(str1,str2);
    if (i != 0)
        printf("not matching\n");
    else
        printf("matching\n");
printf("i=%d\n",i);
return 0;

}

int strcmpic(char *st1,char *st2) {
    int i,len1,len2;
    len1=strlen(st1);
    len2=strlen(st2);
    for (i=0; i< len1 && i<len2; i++){
        if(toupper(*st1) != toupper(*st2))
           return (*st1 - *st2);
 //          printf("char matching...\tst1=-%c-\tst2=-%c-\n",*st1,*st2);
           st1++;
           st2++;

    }
 //   printf("i=%d\n\tst1=-%c-\tst2=-%c-\n",i,*st1,*st2);
    // if it comes here that means all char in st1 matches with st2 or one string is subset of other
    // make a length cmp if differ then retun diff again else return o
    if(len1 > len2)
       return (*st1);
    else if (len1 < len2)
       return (*st2);
    return 0;


}
void fun1(char *st){ //st is a locl pointer which stored str address
    st="CHETAN";        // here assign st the address of "CHETAN" so st add changes
    puts(st);
}

void fun2(char *st) {  // again st got the base address od str string array
   st[0]='C';  // we are changing value at the address which is pointing to str so changes will refect
   st[1]='H';
   st[3]='E';
   puts(st);
}
void lreverse (char *ch){
    if(*ch ){
      lreverse(ch+1);
      printf("%c",*ch);
    }

}
int lstrlen(char *str){
   int i=0;
   if(str[0] == '\0') return 0;
   while(str[++i]);
   return i;
}
void fun(char ch[]) {
  ch="hiii";  // this is fine because ch is a local to hold just line p in ex-2
  puts(ch);
}

void convert_num_word (int x){
    static int count;
    int temp;
    //printf("here - count=%d\tdiv=%d\tx=%d\n",count,div,x);
    if(x/10 == 0){
        printf("%s  ",num_in_char[x]);
        printf("%s  ",decimal[count]);
        return;
    }
    count++;
    convert_num_word(x/10);
    count --;
   // printf("x=%d\n",x);
    temp = x%10;
    printf("%s  ",num_in_char[temp]);
    printf("%s  ",decimal[count]);
    return;
}

void decrypt(char *st) {
    while(*st != '\0') {
        if((*st >64 && *st <91) || (*st >96 && *st<123)){
           if(*st == 'a') { *st='z';}
           else if (*st == 'A') {*st='Z';}
           else {*st = --*st;}
         }
        st++;
    }
}
void encrypt(char *st){

   while(*st != '\0'){
       //putchar(*st);
     if((*st >64 && *st <91) || (*st >96 && *st<123)){
         if(*st == 'z') { *st='a';}
         else if (*st == 'Z') {*st='A';}
         else {*st = ++(*st);}
     }
     //putchar(*st);
st++;
   }

}
void extract(char *st,int start,int last){
    start--;
    last--;
printf("start=%d  last =%d\n",start,last);
     while(last >= start){
         printf("%c",st[start]);
         start++;
     //    printf("start=%d \n",start);
     }
}
void reverse(char *st){
    int len,i,j;
    char temp;
    len =j =  strlen(st)-1;
    printf("length = %d\n",len);
    for(i=0;i<=(len/2) && i!=j ;i++,j--){
        temp = st[i];
        st[i] = st[j];
        st[j]=temp;
    }
}

void nreverse(char *st,int start,int last){
       char temp;
       start--;
       last--;
       while(last >= start){
            temp=st[start];
            st[start]=st[last];
            st[last]=temp;
            start++;
            last--;
       }
}