#include<stdio.h>
#include<stdlib.h>

int size;
struct heap {
	int *arr;
	int count;
	int capacity;
};

void buildHeap(struct heap **,int *,int);
void heapify(int *,int);
void display(struct heap*);
void insertElement(struct heap*,int);
void swap (int *x, int *y) {int temp = *x; *x =*y; *y=temp;}
void deleteElement(struct heap *,int);
void heapsort(struct heap *);
//void findMaxk(struct heap *h,int);

int main() {
	int in;
	int arr[8] = {10,3,6,44,7,80,50,33};
	struct heap *h= (struct heap *) malloc (sizeof(struct heap));;
	h->capacity=20;
//	printf("Enter the array size : ");
//	scanf("%d",&size);
	size=8;
	//arr = (int *) malloc (sizeof(int) * size);
	/*for(i=0;i<size;i++) {
		printf("Enter the %dth element : ",i+1);
		scanf("%d",&arr[i]);
	}
	*/


	//display(arr);
	/*
	for(i=(size-2)/2;i>=0;i--)
		heapify(arr,i);
	display(arr);
*/
	buildHeap(&h,arr,size);
	display(h);
	insertElement(h,2);
	display(h);
	insertElement(h,50);
	display(h);
	printf("now deleting element\n");
	//deleteElement(h,3);
	//deleteElement(h,5);
	size=h->count;
	//display(h);
	printf("running heap sort\n");
	heapsort(h);
	display(h);
	return 0;
	}

void buildHeap(struct heap **h,int *arr,int n) {
	int i;
	(*h)->count = n-1;
	(*h)->arr= (int *) malloc ((*h)->count *sizeof(int));
	for(i=0;i<n;i++)
		(*h)->arr[i] = arr[i];
	size=(*h)->count;
	for(i=(n-2)/2;i>=0;i--)
		heapify((*h)->arr,i);

}

void insertElement (struct heap *h,int data) {
	h->count++;
	int i = h->count;
	printf("i=%d,data=%d\n",i,data);
	while(i>0 && data > h->arr[(i-1)/2]) {
		printf("overriding %d to %d\n",h->arr[i],h->arr[(i-1)/2]);
		h->arr[i] = h->arr[(i-1)/2];
		i = (i-1)/2;
	}
	h->arr[i] = data;
}

void deleteElement(struct heap *h,int index) {

	if(index > h->count+1)
		printf("outof range\n");
	else {
		h->arr[index] = h->arr[h->count];
		h->count--;
		heapify(h->arr,index);
	}
}

void heapsort(struct heap *h) {
	size=h->count;
	while(size > 0) {
		swap(&(h->arr[0]),&(h->arr[size]));
		size--;
		heapify(h->arr,0);
	}
}


void display(struct heap *h) {
	int i;
	printf("Heap contain: ");
	for(i=0;i<=h->count;i++)
		printf("%d ",h->arr[i]);
	printf("\n");
}

void heapify(int *arr,int i) {

	int left,right,max;
	left = 2*i+1;
	right = 2*i+2;
	max=i;
//	printf("left = %d  right = %d  i=%d  size=%d\n",left,right,i,size);
	if(left < size && arr[left] > arr[max])
		max = left;
	if(right < size && arr[right] > arr[max])
		max=right;
	if(max != i) {
//		printf("swapping %d and %d\n",arr[i],arr[max]);
		swap(&arr[i],&arr[max]);
		heapify(arr,max);
	}
}

