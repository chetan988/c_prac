#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void removeDuplicate(char[]);
void removeDuplicateWithextramem(char[]);
void checkAnagram(char[], char[]);
int contains(char[], char[]);
void containsRotated(char[], char[]);
void replaceSpace(char[]);
void makeRowCol();


int main() {
	char checkdup[] = "abbcccadef";
	/* remove duplicate start 
	 //	removeDuplicate(checkdup);
	 //	removeDuplicateWithextramem(checkdup);
	 remove duplicate end */

	/* annagram test start 
	 //check if two string are anagram : two string are said to be anagram if two string has same characters
	 char str1[] ="chetaant";
	 char str2[] ="ehcatnta";
	 char str3[] ="xchetanx";
	 
	 checkAnagram(str1,str2);
	 checkAnagram(str1,str3);
	 annagram test end   */

	/* test if a string is sub string 
	char str1[] = "waterbottle";
	char str2[] = "tlewaterbot";
	containsRotated(str1, str2);
	  end of test a string is roatated sub string */
	
	/*   Write a method to replace all spaces in a string with ‘%20’.
	
	char sentence[] = "hello world!! How are you??";
	replaceSpace(sentence);
	
	*/
	
	/* Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
		column is set to 0. 
	makeRowCol();
	*/
	
	return 0;
}

void makeRowCol() {
	int row[3],col[4];
	int i,j;
	int arr[3][4] = {
			{1,2,0,5},
			{5,6,3,7},
			{6,0,4,9}
	};
	for(i=0;i<3;i++) 
		for(j=0;j<4;j++) 
			if(arr[i][j] ==0) {
				row[i]=1;
				col[j] =1;
			}
	
	for(i=0;i<3;i++){
		for(j=0;j<4;j++) {
			if(row[i] == 1 || col[j] == 1) {
				arr[i][j] = 0;
			}
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

void replaceSpace(char sentence[]) {
	int spacecount=0;
	int i;
	int len = strlen(sentence);
	int newlen;
	
	printf("sentence before replaced space %s\n",sentence);
	for(i=0;i<len;i++){
		if(sentence[i] == ' ')
			spacecount++;
	}
	
	newlen = len + spacecount*2;
	sentence[newlen--]='\0';
	for(i=len-1;i>=0;i--) {
		
		if(sentence[i] == ' ') {
			sentence[newlen] = '0';
			sentence[--newlen] = '2';
			sentence[--newlen] = '%';
		}
		else {
			sentence[newlen] = sentence[i];
		}
		newlen--;
	}
	
	printf("sentence after replaced space %s\n",sentence);
}



void containsRotated(char str1[], char str2[]) {

	// append str1 with str1, if modified string contains str2 then str1 is rotated substring of str2
	str1 = strcat(str1, str1);
	if(contains(str1, str2)) {
		printf("%s is a rotated substring of %s\n",str1,str2);
	}
}

int contains(char str1[], char str2[]) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int i, j;
	for (i = 0; i < (len1 - len2); i++) {
		j = 0;
		while (j < len1) {
			if (str1[i + j] == str2[j])
				j++;
			else
				break;
		}
		if (j == len2) {
			printf("string matched at %d\n", i);
			return 1;
		}
	}
	return 0;
}

void checkAnagram(char str1[], char str2[]) {

	int countChar[256];
	int i, str1count = 0, str2count = 0;
	if (strlen(str1) != strlen(str2))
		return;

	for (i = 0; i < 256; i++)
		countChar[i] = 0;
	for (i = 0; i < strlen(str1); i++) {
		if (countChar[str1[i]] == 0) // unique character increment the count
			str1count++;
		countChar[str1[i]]++;
	}

	for (i = 0; i < strlen(str2); i++) {
		countChar[str2[i]]--;
		if (countChar[str2[i]] == 0) // unique char in str2 after removing the duplicates
			str2count++;
	}

	if (str1count == str2count) {
		printf("strings are anagram\n");
	} else {
		printf("strings are not anagram\n");
	}

}

void removeDuplicateWithextramem(char str[]) {

	/* here we used a extra data structure to solve the issue */
	int visited[256];
	int i, tail = 1;

	for (i = 0; i < 256; i++)
		visited[i] = 0;
	visited[str[0]] = 1;

	for (i = 1; i < strlen(str); i++) {
		if (visited[str[i]] == 0) {  // unique character
			str[tail] = str[i]; // put in the tail , till tail all are unique 
			tail++;
		}
	}
	str[tail] = '\0';
	printf("after removing duplicates : %s\n", str);
}

void removeDuplicate(char str[]) {
	if (str == '\0')
		return;

	int len = strlen(str);
	int tail = 1;
	int i, j;
	if (len < 2)
		return;
	// traverse from beg to end
	for (i = 1; i < len; i++) {
		// traverse small distance but check for duplicate
		for (j = 0; j < tail; j++) {
			if (str[i] == str[j])
				break;

		}
		if (j == tail) {
			// if come inside then till tail we did not find duplicate so increase tail and add the i nonunique element
			str[tail] = str[i];

			++tail;

		}

	}

	str[tail] = '\0';
	printf("%s\n", str);
}
