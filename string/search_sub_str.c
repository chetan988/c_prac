#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void permute (char *s,int i,int n);
void reverse_str_limit (char *str,int start,int end);
void swap(char *c1,char *c2);



int check_for_sub_str(char *str,char *substr) {
	int i,j;
	int str_len = strlen(str);
	int substr_len = strlen(substr);
	for(i=0; i < (str_len - substr_len) ;i++ ) {
		j=0;
		while(j < substr_len && str[i+j] == substr[j])
			j++;
		if(j==substr_len)
			return 0;
	}
	return 1;
	
}

void strip_newline(char *str) {
	int i;
	int len = strlen(str);
	for(i=0;i<len;i++)
		if(str[i] == '\n') {
			str[i] = '\0';
			return;
		}
}

void reverse_str (char *str) {
	
	int i,j;
	int len = strlen(str);
	char temp;
	for(i=0,j=len-1; i < j;i++,j--) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

void prefix_table(char *p,int m, int *F) {
	
	int i=1,j=0;
	F[0] = 0;
	while(i<m) {
		if(p[i] == p[j]) {
			F[i] = j+1;
			j++;
			i++;
		}
		else if (j > 0)
			j = F[j-1];
		else {
			F[i] = 0;
			i++;
		}
	}
}

void kmp_algo (char *t, char *p, int n, int m, int *F) {
	int i,j;
	i=j=0;
	while (i<n) {
		if(t[i]==p[j]) {
			if(j == m-1){
				printf("String found at %d\n",i-j);
				j=F[j-1];
			}
			else {
				i++;
				j++;
			}
		}
		
		else if(j>0)
			j = F[j-1];
		else
			i++;
	}
}

void display(int *arr,int n) {
	int i;
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int match_pattern(char *text, char *pattern ) {
	
	if(*text == '\0' && *pattern == '\0')
		return 1;
	if(*pattern == '*' && *(pattern+1) != '\0' && *text == '\0')
		return 0;
	if(*pattern == '?' || *pattern == *text)
		return match_pattern(text+1,pattern+1);
	if(*pattern == '*')
		return match_pattern(text+1,pattern) || match_pattern(text,pattern+1);
	return 0;
}


void reverse_sentense(char *sentence) {
	int l = strlen(sentence);
	int start_ind,end_ind;
	start_ind = end_ind =0;
	// reverse the sentense completely
	reverse_str(sentence);
	// now reverse  the word one by one
	while(end_ind < l) {
		start_ind = end_ind;
		if(start_ind == end_ind && sentence[start_ind] == ' ' ) {
			start_ind++;
			end_ind++;
		}
		while(sentence[end_ind] != ' ' && end_ind < l)
			end_ind++;
		end_ind--;
		reverse_str_limit(sentence,start_ind,end_ind);
		end_ind++;
	}
}

void reverse_str_limit (char *str,int start,int end) {
	
	int i,j;
	char temp;
	for(i=start,j=end; i < j;i++,j--) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

void permute (char *s,int i,int n){
  int j;
  if (i==n) {
    printf("%s\t",s);
  }
  else {
    for(j=i;j<=n;j++){
      printf("before permut before swaping s1 -> %s,i->%d,j->%d\n",s,i,j);
      swap((s+i),(s+j));
      printf("before permut after swaping s1 -> %s,i->%d,j->%d\n",s,i,j);
      permute(s,i+1,n);
      printf("after permute before swapping s2 -> %s,i->%d,j->%d\n",s,i,j);
      swap((s+i),(s+j));
      printf("after permute after swapping s2 -> %s,i->%d,j->%d\n\n\n",s,i,j);
    }
  }
}

void swap(char *c1,char *c2) {
    char temp;
    temp=*c1;
    *c1=*c2;
    *c2=temp;

}

void combination(char *original,int n,int original_index, char *temp, int temp_index,int r) {
	// combination of all element of size r
	
	if(temp_index == r) {
		// print the combination
		int i;
		for(i=0;i<temp_index;i++)
			printf("%c",temp[i]);
		printf("\n");
		return;
	}
	if(original_index >= n)   // over flow
		return;
	temp[temp_index] = original[original_index];
	combination(original,n,original_index+1,temp,temp_index+1,r);  // add element to temp till it reaches r
	
	// now replace the element with next element
	combination(original,n,original_index+1,temp,temp_index,r);
	
}