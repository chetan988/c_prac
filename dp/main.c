#include<stdio.h>
#include<stdlib.h>
#include "dp.c"


void main() {
	
	/* program of febonaci series of n=5*/
/*	int first=1,second=1,next,i;
	for(i=0;i<5;i++) {
		if(i <=1) {
			next = 1;
		}
		else {
			next = first+second;
			first = second;
			second=next;
		}
		printf ("%d ",next);
	}
	printf("\n");
	for(i=0;i<5;i++)
		printf("%d ",feb(i));
	printf("\n");
	
	// end of febonaci series using dp */
/*	
	char str1[]="hellohowareyou";
	char str2[] = "walkingdead";
	int  len = maximumSubStr(str1,str2);
	printf("maximum string length = %d\n",len);
	*/
	
	//  knapsack problem
	/*
	int weight[] = {2,3,4,5};
	int value[] = {3,4,5,6};
	int maxweight =5;
	
	knapsack(weight,value,5,4);
	*/
	
	int change[] = {1,2,3};
	printf("min change required : %d\n",changecoin(7,change,3));
}