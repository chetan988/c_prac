#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "search_sub_str.c"

int main() {
	
	char str[50],substr[10];
	int flag;
	int *F,n,m;
	/* check for  the sub string */
	/*
	printf("Enter the string: ");
	fgets(str,50,stdin);
	strip_newline(str);
	printf("enter the string you want to search: ");
	fgets(substr,10,stdin);
	strip_newline(substr);
	flag = check_for_sub_str(str,substr);
	if(flag)
		printf("%s could not found in the string\n",substr);
	else
		printf("%s found in the string\n",substr);
	/* string reversing */
//	reverse_str(substr);
//	printf("reversed string =%s\n",substr);
	
	//kmp algo
/*	m=strlen(substr);
	n=strlen(str);
	F = (int *) malloc (sizeof(int) * m);
	prefix_table(substr,m,F);
	display(F,m);
	kmp_algo(str,substr,n,m,F);
	*/
	
	/* pattern matching */
//	pattern("chetan","che?an");
	
	/*reverse a sentense */
/*	printf("Enter the sentence: ");
	fgets(str,50,stdin);
	strip_newline(str);
	reverse_sentense(str);
	printf("reversed sentence =%s\n",str);
*/
	
	/* permutation */
	char s[3]="abc";
	permute(s,0,2);
	
	
	/*combination */
	
/*	char s[6] = "abcdef";
	char t[3];
	combination(s,5,0,t,0,3); */
	return 0;
}

void pattern(char *text,char *pattern) {
	if(match_pattern(text,pattern))
		printf("pattern matched\n");
	else
		printf("pattern mismatched\n");
}