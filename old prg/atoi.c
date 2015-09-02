#include<stdio.h>
#include<conio.h>

int isnumeric(char );
float atoi(char *);

void main() {
    char str[20];
    float i;
    printf("Enter the numeric string: ");
    gets(str);
    i=atoi(str);
    printf("i=%f\n",i);
}

int isnumeric(char ch){
  if(ch >= '0' && ch <= '9'){
     return 1;
}
  else{
     return 0;
  }
}

float atoi(char *str) {
    int sign=1,i=0,flag=0;
    float res=0,temp;
    if(str == NULL)
      return -1;
    if (str[0] == '-'){
       sign = 0;
       i++;
    }
    if (str[0] == '+'){
       sign = 1;
       i++;
    }
    for(;i<strlen(str);i++){
    //    printf("flag = %d\n",flag);
        if(flag == 0 && str[i] == '.'){
            flag =1;
            continue;
        }
        if(isnumeric(str[i]) == 0 && flag != 1)
          return -1;
        if(flag == 0)
           res = (res * 10) + (str[i] - '0');
        else{
          //  temp =(str[i] - '0');
          //  printf("temp = %f\tstr=%c\n",temp,str[i]);
            temp =((str[i] - '0') /(10.0 * flag));
         //   printf("[2]temp = %f\n",temp);
           res = res +temp ;
           flag=flag*10;
        }
    }
    if(sign == 0)
       res = res * -1;
       printf("res = %f\n",res);
    return res;
}