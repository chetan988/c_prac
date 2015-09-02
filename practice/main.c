#include <stdio.h>
#include <stdlib.h>
/* this is solution to tower of hanoi problem
prob:
you have to move all disc from A to C and you have given B as an auxilary tower
rules are:
 1. you can move one disc at a time
 2. a large disc can not be placed on top of a small diac

 */

void towerOfHanoi(int,char,char,char);
int main()
{
    int noOfDisc;
	printf ("Welcomr to tower of hanoi problem\n We will move given disc from tower A to tower C using an auxilary tower B\nenter the number of disc: ");
	scanf("%d",&noOfDisc);
	towerOfHanoi(noOfDisc,'A','C','B');
	return 0;
}


void towerOfHanoi (int n, char from, char to, char aux) {
    // base condition
    if(n==1) {
       printf("moving disc from %c to %c \n", from,to);
       return;
    }
   // move n-1 disc from A to B using C as a auxilary
    towerOfHanoi(n-1,from,aux,to);
    // move the largest piece from A to C

    printf("moving disc from %c to %c \n",from,to);

    // move n-1 disc from B to C

    towerOfHanoi(n-1,aux,to,from);

}