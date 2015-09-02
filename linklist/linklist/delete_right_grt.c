/*

Delete nodes which have a greater value on right side
Given a singly linked list, remove all the nodes which have a greater value on right side.

Examples:
a) The list 12->15->10->11->5->6->2->3->NULL should be changed to 15->11->6->3->NULL. Note that 12, 10, 5 and 2 have been deleted because there is a greater value on the right side.

When we examine 12, we see that after 12 there is one node with value greater than 12 (i.e. 15), so we delete 12.
When we examine 15, we find no node after 15 that has value greater than 15 so we keep this node.
When we go like this, we get 15->6->3

b) The list 10->20->30->40->50->60->NULL should be changed to 60->NULL. Note that 10, 20, 30, 40 and 50 have been deleted because they all have a greater value on the right side.

c) The list 60->50->40->30->20->10->NULL should not be changed.

*/

/*            working   */
#include <stdio.h>
#include <stdlib.h>
#include "insertnode.h"


int main() {
	struct node *root = NULL,*current,*del_n,*prev;
	addNode(&root,12);
	addNode(&root,15);
	addNode(&root,10);
	addNode(&root,11);
	addNode(&root,5);
	addNode(&root,6);
	addNode(&root,2);
	addNode(&root,3);
//	addNode(&root,20);
//	addNode(&root,10);
	printNodes(&root);
	current = root;
	while(current->next != NULL) {
		if(current->data < current->next->data) {
			// we need to delete this node if head shift the head
			if(current == root) {
				root = current->next;
			}
			else {
				prev->next = current->next;
			}
			del_n = current;
			current = current->next;
            printf("deleting .... %d\n",del_n->data);
			free(del_n);
			
		}
		else {
			prev = current;
			current = current->next;
		
		}
	}
	printNodes(&root);
	return 0;
}