#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dp[100] = {0};

void display(int *,int,int);
int max(int x,int y) {
	if(x>y)
		return x;
	else
		return y;
}

int min (int x,int y) {
	if(x<y)
		return x;
	else
		return y;
}
int feb(int n) {
	if(n==0 || n == 1)
		return 1;
	dp[0]=1;
	dp[1]=1;
	if(dp[n] != 0) return dp[n];
	dp[n] = feb(n-1)+feb(n-2);
	return dp[n];
}


int maximumSubStr(char *str1,char *str2) {
	
	int m,n,i,j;
	m = strlen(str1);
	n = strlen(str2);
	printf ("m=%d  n=%d\n",m,n);
	int mss[m+1][n+1];
	for(i=0;i<m+1;i++)
		mss[i][0]=0;
	for(i=0;i<n+1;i++)
		mss[0][i] = 0;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++) {
			if(str1[i-1] == str2[j-1])
				mss[i][j] = 1+mss[i-1][j-1];
			else {
				mss[i][j]= max(mss[i-1][j],mss[i][j-1]);
			}
		//	printf ("mss[%d][%d] = %d\n",i,j,mss[i][j]);
		}	
	//display ((int *)mss,m,n);
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++)
			printf("%d ",mss[i][j]);
		printf("\n");
	}
	
	
		
	return mss[m][n];
}

void display (int *x,int m,int n) {
	
	int i,j;
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++)
			printf("%d ",*((x+j*m)+i));
		printf("\n");
	}
}


int maxSum (int * arr,int n) {
	
	int i,maxsumsofar,actualmaxsum;
	
	for(i=0;i<n;i++) {
		maxsumsofar += arr[i]; 
		if(maxsumsofar > 0 && maxsumsofar > actualmaxsum)
			actualmaxsum = maxsumsofar;
		if(maxsumsofar < 0)
			maxsumsofar =0;
			
	}
	return maxsumsofar;
}


void knapsack(int *weight,int *value,int maxweight, int n) {
	
	// if we have a knapsack that can carry maximum maxweight and we have n items
	// knapsack[i][j] = max(M(i-1,j), M(i-1,j-wi))
	// M(i-1,j) indicate if we do not choose the ith item then we have to go with i-1 item
	// M(i-1,j-wi) indicate if we choose ith item then wi weight is gone from the available wight and i-1 item is remaining
	
	int knapsack[n+1][maxweight+1];   // we will iterate for n item and will check how much we can carry for 0 to maxweight limit
	// knapsack[i][j]  means the value we carried while 0 to i item can be carried and j is maximum wight
	int i,j;
	for(i=0;i<=n;i++)
		knapsack[i][0] = 0;  // maximum allowbale weight is 0 so we can not carry anything
	for(i=0;i<=maxweight;i++)
		knapsack[0][i] = 0;  // no item avaiable so regardless of maximum allowbale weight we can carry nothing
	for(i=1;i<=n;i++) {
		for(j=1;j<=maxweight;j++) {
			if(weight[i-1] <= j)
				knapsack[i][j] = max(knapsack[i-1][j], (knapsack[i-1][j-weight[i-1]]+value[i-1]));  // i staring from 1 so i-1
			else
				knapsack[i][j] = knapsack[i-1][j];
		}
	}
	
	for(i=0;i<=n;i++) {
		for(j=0;j<=maxweight;j++)
			printf("%d ",knapsack[i][j]);
		printf("\n");
	}
		
}


int changecoin (int n, int *change,int m) {
	int i,j,ch;
	if (n == 0) return 0;
	if (n< 0) return 0;
	if(dp[n] != 0)
		return dp[n];
	ch = changecoin(n-change[0],change,m);
	for (i=1;i<m;i++)
		ch = min(ch,changecoin(n-change[i],change,m))+1;
	dp[n] = ch;
	return dp[n];
}