#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100000
#define MAX_VAL 1000000001

void mergeSort(int *,int ,int);
void merge(int *,int,int,int);

int list[MAX];

int main() {
    
    int N,K;
    int i;
    int potential_min,potential_max,current_unfair;
    
    scanf("%d %d",&N,&K);
    for(i = 0;i < N;i++)
        scanf("%d", &list[i]);
  
    int unfairness = INT_MAX;// Compute the min unfairness over here, using N,K,candies
    mergeSort(list,0,N-1);
 
    for(i=0;i<=N-K;i++) {
        potential_min = list[i];
        potential_max = list[i+K-1];
        current_unfair = potential_max - potential_min;
        if(unfairness > current_unfair) unfairness = current_unfair;
    }
        
    printf("%d",unfairness);
    return 0;
}

void mergeSort(int *list,int low,int high) {
    if(low < high) {
        int mid = (low+high)/2;
        mergeSort(list,low,mid);
        mergeSort(list,mid+1,high);
        merge(list,low,mid,high);
    }
}

void merge(int *list,int low, int mid, int high) {
    int i,j,k;
    int n1 = (mid - low) +1;
    int n2 = (high - mid);
    int left[n1];
    int right[n2];
    for(i=0;i<n1;i++)
        left[i] = list[low+i];
    for(i=0;i<n2;i++)
        right[i] = list[mid+i+1];
    
    k=low;
    i=0;
    j=0;
    while((i<n1) && (j<n2)) {
        if(left[i] < right[j]) {
            list[k] = left[i];
            i++;
        }
        else {
            list[k] = right[j];
            j++;
        }
        k++;
    }
    
    while(i < n1){
        list[k] = left[i];
        k++;
        i++;
    }
    
    while(j<n2) {
        list[k] = right[j];
        j++;
        k++;
    }
        
}

