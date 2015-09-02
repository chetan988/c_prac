#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*   given a syntax check if bracket is balanced */

int main()
{
	struct stack *s = createStack(5);
    //deleteStack(s);
    char str[20];
    int i=0,flag =0;
    printf("enter equation: ");
    scanf("%s",&str);
    while(str[i] != '\0') {
         if(str[i] == '(')
            push(s,'(');
         else if (str[i] == '{')
            push(s,'{');
        else if (str[i] == '[')
            push(s,'[');
        else if (str[i] == ')') {
           if(pop(s) != '(')
              flag =1;
        }
        else if (str[i] == '}' ){
            if(pop(s) != '{' )
                flag =1;
        }
        else if(str[i] == ']') {
            if(pop(s) != '[')
                flag =1;
        }
        i++;
    }
    if(!(isEmpty(s)))
        flag = 1;
    if(flag)
       printf("equation is not balance\n");
    else
       printf("equation is balanced\n");

	return 0;
}
