#include<stdio.h>
#include<stdlib.h>

void merge(int *,int,int,int);
void sort(int *,int,int);
void display (int *, int );
int findFirstOccurance(int *,int,int,int);
int findLastOccurance(int *,int,int,int);

void arrange(int *,int);

int main () {

	int arr[10] = {10,20,30,10,20,20,50,60,20,10};
	int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
	int val,ind_l,ind_h;
	
	// comenting for other program
	//    start of prog 1
//	printf("array : \n");
//	display(arr,10);
//	/* if a sorted array has duplicated then find the index of first duplicate */
//	sort(arr,0,9);
//	printf("after sorting array : \n");
//	display(arr,10);
//	printf("Enter the value : ");
//	scanf("%d",&val);
//	ind_l = findFirstOccurance(arr,0,9,val);
//	if(ind_l == -1)
//		printf("element not found\n");
//	else
//		printf("first index of %d is %d\n",val,ind_l+1);
//	/* if a sorted array has duplicated then find the index of last duplicate */
//	ind_h = findLastOccurance(arr,0,9,val);
//	if(ind_l == -1)
//		printf("element not found\n");
//	else
//		printf("last index of %d is %d\n",val,ind_h+1);
//	if(ind_l != -1)
//		printf("array contain %d numbers of %d\n",(ind_h - ind_l+1),val);
	
	//        end of prog -1
	//***************************************************
	// start of prog 2
	// sort all the enen in the begining and all the odd at the end
	// the solution call dutch flag problem
	// we will sracn from begining if till odd found
	// we will scan from last till even found
	// we will swap and continue till both pointer cross eachother
	display(arr1,10);
	arrange(arr1,10);
	display(arr1,10);
}


void arrange (int *arr,int n) {
	int start=0,last=n-1,temp;
	while(start < last) {
		
		while(arr[start]%2 == 0)
			start++;
		while(arr[last]%2 != 0)
			last--;
		if(start < last){
			temp=arr[start];
			arr[start] = arr[last];
			arr[last]= temp;
			start++;
			last--;
		}
			
	}
}
int findLastOccurance(int *arr,int low,int high,int val) {
	if(low > high)
		return -1;
	int mid = low + (high-low)/2;
	if(arr[mid]==val && (mid == high || arr[mid+1] > val))
		return mid;
	if(arr[mid] <= val)
		findLastOccurance(arr,mid+1,high,val);
	else findLastOccurance(arr,low,mid-1,val);
}


int findFirstOccurance(int *arr,int low,int high ,int val) {
	
	if(low > high)
		return -1;
	int mid = (low+high)/2;
	if(arr[mid]== val && (low == mid || arr[mid-1] < arr[mid]))
		return mid;
	if(arr[mid] >= val)
		findFirstOccurance(arr,low,mid-1,val);
	else
		findFirstOccurance(arr,mid+1,high,val);
}


void sort (int *arr,int low, int high) {
	if(low < high) {
		int mid = (low+high)/2;
		sort(arr,low,mid);
		sort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}


void merge (int *arr,int low,int mid,int high) {
	
	int size1 = mid-low+1;
	int size2 = high -mid;
	int l[size1],h[size2];
	int i,j,k;
	for(i=0;i<size1;i++)
		l[i] = arr[low+i];
	for(i=0;i<size2;i++)
		h[i] = arr[mid+1+i];
	j=k=0;
	i=low;
	while((j < size1) &&( k < size2)) {
		
		if(l[j] < h[k]) {
			arr[i] = l[j];
			j++;
		}
		else{
			arr[i] = h[k];
			k++;
		}
		i++;
		
	}
	while (j<size1) {
		arr[i] = l[j];
		j++;
		i++;
	}
	while(k < size2) {
		arr[i] = h[k];
		k++;
		i++;
	}
	
	
}


void display(int *arr,int n) {
	int i;
	for (i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}