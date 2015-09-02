#include<stdio.h>
#include<conio.h>


void heapsort(int a[],int);
void printarray(int a[],int n){
        int i;
        for(i=0;i<n;i++)
           printf("%d   ",a[i]);
        printf("\n");
}
void buildheap(int a[], int);
void maxhipify (int a[],int,int);
void swap ( int *x, int *y) { int t = *x; *x = *y; *y = t; }
void main() {

    int a[8] = {30,18,40,38,1,4,46,88};
    printarray(a,8);
    heapsort(a,8);
}

void heapsort(int a[],int n) {
    int i=0;
    buildheap(a,n);
    printarray(a,8);
    while(i < n) {
        swap(&a[0],&a[n-1]);
        n--;
        maxhipify(a,0,n);
    }
    printarray(a,8);
}

void buildheap(int a[], int n) {
    int i;
    for(i = (n-2)/2; i>=0; i--)     // start the left most node of dept-1 level node
        maxhipify(a,i,n);
    printarray(a,8);
}

void maxhipify (int a[], int l_root, int size){

   int left = 2 * l_root + 1;
   int right = 2 * l_root + 2;
   int largest = l_root;
   if (left < size && a[left] > a[largest])
        largest = left;
   if (right < size && a[right] > a[largest])
        largest = right;
   if(largest != l_root) {
        swap (&a[largest],&a[l_root]);
        maxhipify(a,largest,size);
   }
}

