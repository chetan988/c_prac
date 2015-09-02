#include<stdio.h>
#include<stdlib.h>

int turnament_method(int *,int,int);
int find_k_bubble(int *,int);
int find_k_min_pivot(int *,int,int,int);
int getPivot(int *,int ,int);
void display (int *, int );
int max(int x,int y) {if(x>=y) return x; return y;}
int HIGH;
int LOW = 0;


int main() {
	int arr[10] = {10,20,1,5,30,60,7,8,55,65};
	int second_max,k,k_max;
	HIGH=9;
	display(arr,10);
	//second_max = turnament_method(arr,0,9);
	//printf("2nd max = %d\n",second_max);
	printf("enter the value of k : ");
	scanf("%d",&k);
	display(arr,10);
	//k_max = find_k_bubble(arr,k);
	//printf("%dth max = %d\n",k,k_max);
	printf("%d th min = %d\n",k,find_k_min_pivot(arr,0,9,k-1));
	
	return 0;
}

int getPivot(int *arr,int low,int high) {
	int i = low,j,temp,pivot_index;
	int pivot = arr[low];
	//printf("pivot element = %d\n",pivot);
	for(j = low+1; j<=high;j++) {
		if(arr[j] < pivot) {
	//		printf("swapping %d\n",arr[j]);
			i++;
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
	pivot_index =i;
	temp = arr[i];
	arr[i] = arr[low];
	arr[low] = temp;
	//printf("pivot index = %d\n",pivot_index);
	return pivot_index;
}

int find_k_min_pivot(int *arr, int low, int high,int k) {
	static count =0;
	count++;
	if(count == 10)
		return;
	if(high <= low)
		return arr[low];
	else {
		//printf("low = %d  high = %d\n",low,high);
		int pivot = getPivot(arr,low,high);
		if(pivot == k) 
			return arr[pivot];
		else if(k < pivot)
			find_k_min_pivot(arr,low,pivot-1,k);
		else
			find_k_min_pivot(arr,pivot+1,high,k);
	}
	
}

int turnament_method(int *arr,int low,int high) {
	if(high == low)
		return arr[low];
	if(high == low+1)
		if(arr[high] > arr[low])
			return arr[high];
		else
			return arr[low];
	int mid = (high+low)/2;
	printf("low = %d \t mid = %d \t high = %d\n",arr[low],arr[mid],arr[high]);
	int max1 = turnament_method(arr,low,mid);
	int max2 = turnament_method(arr,mid+1,high);
	printf("max1=%d\tmax2=%d\n",max1,max2);
	
	if(low == LOW && high ==HIGH)
		if(max1 > max2) return max2;
		else return max1;
	else
		if(max1 > max2) return max1;
		else return max2;	
}

int find_k_bubble(int *arr ,int k) {
	int i,j,temp;
	if(k > HIGH)
		return -1;
	for(i=0;i<k;i++) {
		for(j=HIGH;j > i;j--) {
			printf("arr[high] = %d, high = %d\n",arr[HIGH],HIGH);
			if(arr[j] > arr[j-1]) {
				temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	display(arr,10);
	return arr[k-1];
}


void display(int *arr,int n) {
	int i;
	for (i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}



