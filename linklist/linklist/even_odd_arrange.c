/*

Segregate even and odd nodes in a Linked List
Given a Linked List of integers, write a function to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list. Also, keep the order of even and odd numbers same.

Examples:
Input: 17->15->8->12->10->5->4->1->7->6->NULL
Output: 8->12->10->4->6->17->15->5->1->7->NULL

Input: 8->12->10->5->4->1->6->NULL
Output: 8->12->10->4->6->5->1->NULL

// If all numbers are even then do not change the list
Input: 8->12->10->NULL
Output: 8->12->10->NULL

// If all numbers are odd then do not change the list
Input: 1->3->5->7->NULL
Output: 1->3->5->7->NULL

*/

#include <stdio.h>
 #include <stdlib.h>
 #include "insertnode.h"


int main() {
	struct node *head = NULL,*current,*ith,*temp_n;
    int temp;
	addNode(&head,17);
	addNode(&head,15);
	addNode(&head,8);
	addNode(&head,12);
	addNode(&head,10);
	addNode(&head,5);
	addNode(&head,4);
	addNode(&head,1);
	addNode(&head,7);
	addNode(&head,6);
	printNodes(&head);
	current=ith=head;
	/*  //below method does not preserve the order of odd numbers 
	while(current != NULL && ith != NULL) {
		printf("[begin]current data .. %d \t ith data =%d\n",current->data,ith->data);
		if((current->data)%2 == 0) {
			
			if(current == ith){
				current = current->next;
				ith = ith->next;
			}
			else {
				printf("[before switch]current data .. %d \t ith data =%d\n",current->data,ith->data);
				temp=ith->data;
				ith->data = current->data;
				current->data = temp;
				current = current->next;
				ith = ith->next;
			}
		}
		else
		current = current->next;
		
	}
	 * */
	 while(current != NULL && ith != NULL) {
		printf("[begin]current data .. %d \t ith data =%d\n",current->data,ith->data);
		if((current->data)%2 == 0) {
			
			if(current == ith){
				current = current->next;
				ith = ith->next;
			}
			else {
				printf("[before switch]current data .. %d \t ith data =%d\n",current->data,ith->data);
				temp_n=ith;
				ith = current;
				current = temp_n;
				printf("[after switch]current data .. %d \t ith data =%d\t temp=%d\n",current->data,ith->data,temp_n->data);
				if(head == temp_n)
					head = ith;
				current = ith->next;
				ith = temp_n->next;
				
			}
		}
		else
		current = current->next;
		
	}
	 
	printNodes(&head);
	return 0;
}