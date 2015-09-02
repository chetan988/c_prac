#include<stdio.h>
#include<conio.h>

// declaration

void getArrayElement (int a[], int);
void putArrayElement (int a[], int);
void selectionsort (int a[], int);
void bubblesort (int a[],int);
void insertion (int a[],int);
void mergesort(int a[],int,int);
void merge(int a[],int,int,int);
void heapsort(int a[],int);
void buildheap(int a[], int);
void maxhipify (int a[],int,int);
int partition(int a[],int,int);
void quicksort(int a[],int,int);
void bucketsort(int a[],int);
void swap (int *, int *);

void main() {
  int N,l1index,l21index,l22index;
  char choice;
  printf("Enter the size of the array : ");
  scanf("%d",&N);
  int a[N];
  getArrayElement(a,N);
  putArrayElement(a,N);
  printf("\n\n\t=======================\n\t         menu\n\t=======================\n\n");
  printf ("\t1 - sort the array\n");
  printf("\t2 - search a value\n");
  printf("Enter your choice: ");
  scanf("%d",&l1index);
  switch(l1index) {
    case 1:
        printf("\n\n\t=======================\n\t       sub menu\n\t=======================\n\n");
        printf("\t1 - selection sort \n\n");
        printf("\t2 - bubble sort\n\n");
        printf("\t3 - insertion sort\n\n");
        printf("\t4 - merge sort\n\n");
		printf("\t5 - heap sort\n\n");
		printf("\t6 - quick sort\n\n");
		printf("\t7 - bucket sort\n\n");
        printf("Enter your choice: ");
        scanf("%d",&l21index);
        switch(l21index) {
            case 1:
               selectionsort (a,N);
               putArrayElement(a,N);
               break;
            case 2:
               bubblesort(a,N);
               putArrayElement(a,N);
               break;
            case 3:
               insertion(a,N);
               putArrayElement(a,N);
               break;
            case 4:
               mergesort(a,0,N-1);
               putArrayElement(a,N);
               break;
			case 5:
               heapsort(a,N);
               putArrayElement(a,N);
               break;
            case 6:
               quicksort(a,0,N-1);
               putArrayElement(a,N);
               break;
            case 7:
               bucketsort(a,N);
               putArrayElement(a,N);
               break;

        }
        break;
    case 2:
        printf("\n\n\t=======================\n\t       sub menu\n\t=======================\n\n");

        printf("Enter your choice: ");
        scanf("%d",&l22index);
        switch(l22index) {
            case 1:
              break;
        }
        break;
  }

}


void getArrayElement(int a[],int n) {
  // method to get the array value
  int i;
  if(n<1) {
     printf("not an array");
     return 1;
  }
  else {
    for(i=0;i<n;i++) {
        printf("get the [%d] element: ",i);
        scanf("%d",&a[i]);
       // scanf("%c");
       // printf ("debug a[%d] = %d\n",i,a[i]);
     }
   }
}
void putArrayElement (int a[], int n) {
    int i;
  if(n<1) {
     printf("not an array");
     return 1;
  }
  else {
      printf ("\narray element are: \n");
    for(i=0;i<n;i++) {
        printf("%d   ",a[i]);
     }
  }
}


void selectionsort (int a[], int n) {
   /*
   Selection Sort
-----------------------
The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.

1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.

In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.

Following example explains the above steps:

arr[] = 64 25 12 22 11

// Find the minimum element in arr[0...4] and place it at beginning
11 25 12 22 64

// Find the minimum element in arr[1...4] and
// place it at beginning of arr[1...4]
11 12 25 22 64

// Find the minimum element in arr[2...4] and
// place it at beginning of arr[2...4]
11 12 22 25 64

// Find the minimum element in arr[3...4] and
// place it at beginning of arr[3...4]
11 12 22 25 64

Time Complexity: O(n*n) as there are two nested loops.

Auxiliary Space: O(1)

The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation.
   */

   int i,j,min_ind;
   for (i = 0 ; i < n; i++) {
      min_ind = i;  // initialize the min index value
      for(j = i+1; j < n ; j++)
          if (a[min_ind] > a[j])
             min_ind = j;  // from i - n j is the min value
      // now min_ind contain next min value what present in i so swap so i will become the next min
      swap (&a[i],&a[min_ind]);
   }

}

void bubblesort (int a[],int n) {
/*
Bubble Sort
February 2, 2014
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.

Example:
First Pass:
( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1.
( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Swap since 5 > 4
( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Swap since 5 > 2
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.

Second Pass:
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 )
( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Swap since 4 > 2
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 )
Now, the array is already sorted, but our algorithm does not know if it is completed. The algorithm needs one whole pass without any swap to know it is sorted.

Third Pass:
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )

*/

/* //optimized bubble sort written below

     int i,j;
     for(i=0;i<n;i++)
       for(j=0;j<n-i-1;j++)    // last i elememt already swapped
           if (a[j] > a[j+1])
               swap(&a[j],&a[j+1]);

*/
/*
Optimized Implementation:
The above function always runs O(n^2) time even if the array is sorted. It can be optimized by stopping the algorithm if inner loop didn’t cause any swap.

// Optimized implementation of Bubble sort
*/

  int i,j,flag =0;
     for(i=0;i<n;i++) {
       flag =0;
       for(j=0;j<n-i-1;j++)    // last i elememt already swapped
           if (a[j] > a[j+1]){
               swap(&a[j],&a[j+1]);
               flag =1;
           }
        if(flag == 0) {
            // we traverse the whole array but all element are sorted so no need to go for next iteration
            break;
        }
     }

/*
Time Complexity: O(n*n)

Auxiliary Space: O(1)

Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.

Sorting In Place: Yes

Stable: Yes

Due to its simplicity, bubble sort is often used to introduce the concept of a sorting algorithm.
In computer graphics it is popular for its capability to detect a very small error (like swap of
just two elements) in almost-sorted arrays and fix it with just linear complexity (2n).
For example, it is used in a polygon filling algorithm, where bounding lines are sorted by their x coordinate at a
 specific scan line (a line parallel to x axis) and with incrementing y their order changes (two elements are swapped)
  only at intersections of two lines (Source: Wikipedia)

*/
}

void insertion (int a[],int n) {
/*
Insertion Sort

Insertion sort is a simple sorting algorithm that works the way we sort playing cards in our hands.

Insertion Sort

Algorithm
// Sort an arr[] of size n
insertionSort(arr, n)
Loop from i = 1 to n-1.
……a) Pick element arr[i] and insert it into sorted sequence arr[0…i-1]

Example:
12, 11, 13, 5, 6

Let us loop for i = 1 (second element of the array) to 5 (Size of input array)

i = 1. Since 11 is smaller than 12, move 12 and insert 11 before 12
11, 12, 13, 5, 6

i = 2. 13 will remain at its position as all elements in A[0..I-1] are smaller than 13
11, 12, 13, 5, 6

i = 3. 5 will move to the beginning and all other elements from 11 to 13 will move one position ahead of their current position.
5, 11, 12, 13, 6

i = 4. 6 will move to position after 5, and elements from 11 to 13 will move one position ahead of their current position.
5, 6, 11, 12, 13


Time Complexity: O(n*n)

Auxiliary Space: O(1)

Boundary Cases: Insertion sort takes maximum time to sort if elements are sorted in reverse order. And it takes minimum time (Order of n) when elements are already sorted.

Algorithmic Paradigm: Incremental Approach

Sorting In Place: Yes

Stable: Yes

Online: Yes

Uses: Insertion sort is uses when number of elements is small. It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.
*/

  int key,i,j;

  for (i=i ; i < n; i++) {
      key = a[i];
      j = i-1;
      while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j = j-1;
      }
      a[j+1] = key;
  }

}
// ****************   morge sort start    ****************************8
void merge(int a[],int strt,int mid,int last) {  // merge part of arry divided by middle element
   int i,j,k;
   int n1 = mid - strt +1;   // n1 is left array length
   int n2 = last - mid ;     // n2 right array length
   int l[n1];
   int r[n2];
   for (i=0;i<n1;i++)
      l[i] = a[strt+i];     // assign first to middle
   for(j=0;j<n2;j++)
      r[j] = a[mid+j+1];    // assign middle to last

   i=j=0;
   k=strt;

   while((i < n1) && (j<n2) ){    // merge two array but in sorted order
       if(l[i] <= r[j]){
            a[k] = l[i];
            i++;
       }
       else {
            a[k] = r[j];
            j++;
       }
       k++;
   }

   while(i < n1) {  // after while there exist some more element in left array
        a[k] = l[i];
        k++;
        i++;
   }
   while(j < n1) {  // after while there exist some more element in left array
        a[k] = r[j];
        k++;
        j++;
   }
}

void mergesort(int a[],int strt, int last) {

/*

Merge Sort
March 15, 2013
MergeSort is a Divide and Conquer algorithm. It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves. The merg() function is used for merging two halves. The merge(arr, l, m, r) is key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one. See following C implementation for details.

MergeSort(arr[], l,  r)
If r > l
     1. Find the middle point to divide the array into two halves:
             middle m = (l+r)/2
     2. Call mergeSort for first half:
             Call mergeSort(arr, l, m)
     3. Call mergeSort for second half:
             Call mergeSort(arr, m+1, r)
     4. Merge the two halves sorted in step 2 and 3:
             Call merge(arr, l, m, r)
The following diagram from wikipedia shows the complete merge sort process for an example array {38, 27, 43, 3, 9, 82, 10}. If we take a closer look at the diagram, we can see that the array is recursively divided in two halves till the size becomes 1. Once the size becomes 1, the merge processes comes into action and starts merging arrays back till the complete array is merged.

Merge-Sort

Time Complexity: Sorting arrays on different machines. Merge Sort is a recursive algorithm and time complexity can be expressed as following recurrence relation.
T(n) = 2T(n/2) + \Theta(n)
The above recurrence can be solved either using Recurrence Tree method or Master method. It falls in case II of Master Method and solution of the recurrence is \Theta(nLogn).
Time complexity of Merge Sort is \Theta(nLogn) in all 3 cases (worst, average and best) as merge sort always divides the array in two halves and take linear time to merge two halves.

Auxiliary Space: O(n)

Algorithmic Paradigm: Divide and Conquer

Sorting In Place: No in a typical implementation

Stable: Yes

Applications of Merge Sort
1) Merge Sort is useful for sorting linked lists in O(nLogn) time. Other nlogn algorithms like Heap Sort, Quick Sort (average case nLogn) cannot be applied to linked lists.
2) Inversion Count Problem
3) Used in External Sorting

*/
    if(strt < last) {
        int mid = strt + (last-strt)/2; // same as (last - start)/2 but acoid overflow
        mergesort(a,strt,mid);
        mergesort(a,mid+1,last);
        merge(a,strt,mid,last);
    }
}

//************************ merge sort end  ********************************

// ***********************  heap sort start ********************************
/*

Heap Sort
March 16, 2013
Heap sort is a comparison based sorting technique based on Binary Heap data structure. It is similar to selection sort where we first find the maximum element and place the maximum element at the end. We repeat the same process for remaining element.

What is Binary Heap?
Let us first define a Complete Binary Tree. A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible (Source Wikipedia)

A Binary Heap is a Complete Binary Tree where items are stored in a special order such that value in a parent node is greater(or smaller) than the values in its two children nodes. The former is called as max heap and the latter is called min heap. The heap can be represented by binary tree or array.

Why array based representation for Binary Heap?
Since a Binary Heap is a Complete Binary Tree, it can be easily represented as array and array based representation is space efficient. If the parent node is stored at index I, the left child can be calculated by 2 * I + 1 and right child by 2 * I + 2.

Heap Sort Algorithm for sorting in increasing order:
1. Build a max heap from the input data.
2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1. Finally, heapify the root of tree.
3. Repeat above steps until size of heap is greater than 1.

How to build the heap?
Heapify procedure can be applied to a node only if its children nodes are heapified. So the heapification must be performed in the bottom up order.

Lets understand with the help of an example:

Input data: 4, 10, 3, 5, 1
                 4(0)
		/   \
	     0(1)   3(2)
            /   \
	 5(3)    1(4)

The numbers in bracket represent the indices in the array representation of data.
Applying heapify procedure to index 1:
 		4(0)
		/   \
            10(1)    3(2)
           /   \
	5(3)    1(4)
Applying heapify procedure to index 0:
	        10(0)
		/  \
	     5(1)  3(2)
            /   \
         4(3)    1(4)
The heapify procedure calls itself recursively to build heap in top down manner.

Notes:
Heap sort is an in-place algorithm.
Its typical implementation is not stable, but can be made stable (See this)

Time Complexity: Time complexity of heapify is O(Logn). Time complexity of createAndBuildHeap() is O(n) and overall time complexity of Heap Sort is O(nLogn).

Applications of HeapSort
1. Sort a nearly sorted (or K sorted) array
2. k largest(or smallest) elements in an array

Heap sort algorithm has limited uses because Quicksort and Mergesort are better in practice. Nevertheless,
the Heap data structure itself is enormously used. See Applications of Heap Data Structure

*/
void heapsort(int a[],int n) {
    int i=0;
    buildheap(a,n);
    while(i < n) {
        swap(&a[0],&a[n-1]);
        n--;
        maxhipify(a,0,n);
    }

}

void buildheap(int a[], int n) {
    int i;
    for(i = (n-2)/2; i>=0; i--)     // start the left most node of dept-1 level node
        maxhipify(a,i,n);
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

//  *********************** heap sort end *****************************

// ***********************  quick sort start **************************

/*

QuickSort
January 7, 2014
Like Merge Sort, QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions
the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways.
1) Always pick first element as pivot.
2) Always pick last element as pivot (implemented below)
3) Pick a random element as pivot.
4) Pick median as pivot.

The key process in quickSort is partition(). Target of partitions is, given an array and an element x of array as pivot,
put x at its correct position in sorted array and put all smaller elements (smaller than x) before x,
and put all greater elements (greater than x) after x. All this should be done in linear time.

Partition Algorithm
There can be many ways to do partition, following code adopts the method given in CLRS book. The logic is simple,
we start from the leftmost element and keep track of index of smaller (or equal to) elements as i. While traversing,
if we find a smaller element, we swap current element with arr[i]. Otherwise we ignore current element.

Analysis of QuickSort
Time taken by QuickSort in general can be written as following.

 T(n) = T(k) + T(n-k-1) + \theta(n)
The first two terms are for two recursive calls, the last term is for the partition process. k is the number of elements which are smaller than pivot.
The time taken by QuickSort depends upon the input array and partition strategy. Following are three cases.

Worst Case: The worst case occurs when the partition process always picks greatest or smallest element as pivot. If we consider above partition strategy where last element is always picked as pivot, the worst case would occur when the array is already sorted in increasing or decreasing order. Following is recurrence for worst case.

 T(n) = T(0) + T(n-1) + \theta(n)
which is equivalent to
 T(n) = T(n-1) + \theta(n)
The solution of above recurrence is \theta(n2).

Best Case: The best case occurs when the partition process always picks the middle element as pivot. Following is recurrence for best case.

 T(n) = 2T(n/2) + \theta(n)
The solution of above recurrence is \theta(nLogn). It can be solved using case 2 of Master Theorem.

Average Case:
To do average case analysis, we need to consider all possible permutation of array and calculate time taken by every permutation which doesn’t look easy.
We can get an idea of average case by considering the case when partition puts O(n/9) elements in one set and O(9n/10) elements in other set. Following is recurrence for this case.

 T(n) = T(n/9) + T(9n/10) + \theta(n)
Solution of above recurrence is also O(nLogn)

Although the worst case time complexity of QuickSort is O(n2) which is more than many other sorting algorithms
like Merge Sort and Heap Sort, QuickSort is faster in practice, because its inner loop can be efficiently implemented
on most architectures, and in most real-world data. QuickSort can be implemented in different ways by changing the choice
of pivot, so that the worst case rarely occurs for a given type of data. However, merge sort is generally considered better
when data is huge and stored in external storage.
*/

int partition (int a[], int low, int high) {
    int i,j,pivot;
    pivot = a[high];   // taking the last element as pivot element
    i = low -1;                 // we will do i++ fo low - 1 will becom the index of exact location of low wlwmwnt value

    for (j = low; j < high ; j++ ) { // no need to check for last element as it is the pivot element
        if(a[j] <= pivot) {    // at index j found an element less tan pivot element now put it at the left side of array
            i++;
            swap(&a[i],&a[j]);    // put it at the last side of the array
        }
    }
    i++; // place for the pivot elemet befor i all are less than pivot
    swap(&a[i],&a[high]);
    return i;
}

void quicksort (int a[], int low, int high) {
    if(low < high) {
        int p = partition(a,low,high);
        quicksort(a,low,p-1);        // pivort is at correct position so sort before that
        quicksort(a,p+1,high);
    }
}
// ********************** quick sort end ******************************


// *************************  start of bucket sort  **********************
// this is a easy and stright forward bucket sort algo with capable of sorting interger from 0-20

void bucketsort (int a[], int n) {
    int count[20], i,j;

    for (i=0;i<20;i++){
        count[i] = 0;   // initialize a empty bucket
    }
    printf("here\n");
    for(i=0;i<n;i++) {
       if( a[i] < 20)
           (count[a[i]])++;   // put all element of arry into bucket

       else
          printf("This sort is only capable of sorting 0-20 range so %d is ignored",a[i]);
    }

    for(i=0,j=0;i<20;i++)
       for(;count[i]>0;count[i]--)  // if (count[i] > 0) do loop and count[i]--
          a[j++] = i;
}

// ************************* end of bucket sort *************************

void swap (int *x,int *y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
  }