#include<stdio.h>
#include<stdlib.h>


void quicksort(int *,int,int);
int getPivot(int *arr,int,int);
void searchTwo(int *,int,int);
void SearchThree(int *,int,int);
void display (int *,int);
int getBitonic(int *,int,int); 
void findValue (int *,int,int,int);

int main () {
	int n,i,val,flag;
	int *arr;
	printf("Enter number of element: ");
	scanf("%d",&n);
	arr = (int *) malloc (n*sizeof(int));
	for(i=0;i<n;i++) {
		printf("Enter %d Elelemnt: ",i);
		scanf("%d",&arr[i]);
	}
	printf("Array is :\n");
	display(arr,n);
	//quicksort(arr,0,n-1);
	//printf("after sorting array : \n");
	//display(arr,n);
	//printf("enter the value to search : ");
	//scanf("%d",&val);
	//searchTwo(arr,n,val);
	//searchThree(arr,n,val);
	/*
	flag = getBitonic(arr,0,n-1);
	if(flag == -1)
		printf("array is not bitonic\n");
	else
		printf("array is bitonic %d\n",flag);
	*/
	
	/* find the value in a rotated array */
	printf("enter the value to search : ");
	scanf("%d",&val);
	findValue(arr,0,n-1,val);
	return 0;
	
}

// lets say the sorted array is rotated for unknown times and we are given a number to find the if number exist or not

void findValue (int *arr,int lo,int hi,int val) {
	printf("lo=%d    hi=%d\n",lo,hi);
	if(lo > hi) {
		printf("element not found \n");
		return;
	}
	
	int mid = (lo+hi)/2;
	if(arr[mid] == val) {
		printf("value found at %d \n",mid);
		return;
	}
	else if (arr[lo] < arr[mid]) {	// find thepart of array in sorted order
	printf("debug - mid=%d \n",mid);
		if(arr[lo] <= val && arr[mid] > val)		// due to rotation higher value is at start search at other half
			findValue(arr,lo,mid-1,val);
		else
			findValue(arr,mid+1,hi,val);		
	}
	else {
		if(arr[hi] > val && arr[mid] < val)
			findValue(arr,mid+1,hi,val);
		else
			findValue(arr,lo,mid-1,val);
	}

}


// bitonic array have k such that 0<k<n where arr[0] .. arr[k] is increasing array and arr[k+1] ..arr[n] is decreasing

int getBitonic(int *arr,int lo,int hi) {
	int mid;
	if(lo >= hi)
		return arr[lo];
	if(lo == hi-1)
		if(arr[lo] > arr[hi])
			return arr[lo];
		else
			return arr[hi];
	mid = (lo+hi)/2;
	if((arr[mid] > arr[mid-1]) && arr[mid] > arr[mid+1])
		return arr[mid];
	if((arr[mid] > arr[mid-1]) && (arr[mid+1] > arr[mid]))
		getBitonic(arr,mid+1,hi);
	if((arr[mid] < arr[mid-1]) && arr[mid+1] < arr[mid])
		getBitonic(arr,lo,mid+1);
}

// find arr[i]+arr[j]+arr[k] = sum

void searchThree(int *a,int n,int sum) {
printf("searching all 3 pair\n");
	int i,j,k,temp_sum;
	for(i=0;i<n;i++) {
		j=i+1;
		k=n-1;
	   while (j < k) {	
		temp_sum = a[i]+a[j]+a[k];
		if(temp_sum < sum)
			j++;
		else if(temp_sum > sum)
			k--;
		else {
			printf("arr[%d]+arr[%d]+arr[%d] = %d\n",i,j,k,sum);
			j++;
			k--;
		}
	   }
	
	}

}

// find such element where arr[lo]+arr[hi] =k
void searchTwo(int *arr,int n,int k) {
	int lo=0,hi=n-1;
	while (lo <= hi ) {
		if(arr[lo] + arr[hi] > k)
			hi--;
		else if (arr[lo] + arr[hi] < k)
			lo++;
		else {
			printf ("arr[%d] + arr[%d] = %d\n",lo,hi,k);
			lo++;
			hi--;
		}
	}
}

void quicksort(int *arr,int lo,int hi) {
	if(lo < hi) {
		int p=getPivot(arr,lo,hi);
		quicksort(arr,lo,p-1);
		quicksort(arr,p+1,hi);
	}
}

int getPivot(int *arr,int lo,int hi) {
	int p = arr[hi];
	int i=lo-1;
	int j,temp;
	//printf("lo = %d   hi=%d\n",lo,hi);
	for(j=lo;j<hi;j++) {
	//printf("pivot = %d and arr=%d\n",p,arr[j]);
		if(arr[j] < p) {
			i++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;		
		}
	}
	i++;
	temp = arr[i];
	arr[i]=arr[hi];
	arr[hi]=temp;
	printf("pivot index=%d\n",i);
	return i;
} 

void display(int *a,int n) {
	int i;
	for (i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");

}
