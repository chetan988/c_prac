#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "stack.h"

void printRange_2 (struct tree *,int, int);
void findMinMax(struct tree *, int *, int *, int);
void traverseVertically(struct tree *,int,int);
void printarr(int *,int);

/* make the mid element as root and put all left as lef sub tree and right as right tree
ex arr = 1,2,3,4,5,6,7
               4
             /  \
            2    6
           / \  / \
          1   3 5  7

          */

/*  ===============================================
               queue to hold tree nodes
    =============================================== */
struct queue {

	struct tree **data;
	int rear,front;
	int capacity;
};

struct queue * createqueue(int);
void enqueue (struct queue*,struct tree*);
struct tree* dequeue (struct queue*);

struct queue * createqueue(int n) {
    int i;
    printf("creating a queue of size %d\n",n);
    struct queue *temp = (struct queue *) malloc (sizeof(struct queue));
    if(temp == NULL)
       printf("can not create the queue");
    else {
       temp->capacity = n;
       temp->front=temp->rear=-1;
       temp->data = (struct tree **) malloc (temp->capacity * sizeof(struct tree));
       for(i=0;i<n;i++)
           temp->data[i] = (struct tree *) malloc (sizeof(struct tree));
    }
    return temp;
}

void enqueue (struct queue* s,struct tree *val){
    if(s->rear == s->capacity -1){
        printf("queue is full\nqueueoverflow occured\n");
        return;
    }
    else {
	  if(s->rear == -1)
	     s->front=0;
      s->rear++;
      s->data[s->rear] = val;
     // printf("Entering s->data[%d] = %d\n",s->top,val);
      return ;
    }
}

struct tree* dequeue(struct queue* s) {
  struct tree *temp;
  if(s->front == -1) {
    printf("queue is empty\nqueueunderflow occured\n");
    return temp;
  }
  else {
     temp=s->data[s->front];
	if(s->front == s->rear)
	   s->front=s->rear=-1;
	 else
	   s->front++;
     return temp;
  }
}

int get_size(struct queue *q) {
if(q->front == -1)
    return 0;
//else if (q->front == q->rear)
  //   return 1;
else
    return ((q->rear - q->front)+1);

}

void deletequeue(struct queue* s) {
     free(s->data);
     free(s);
}

/*  ===============================================
               queue to hold tree nodes
    =============================================== */

/*  ===============================================
		queue to hold tree with sibling
    =============================================== */

struct queue_ws {
	struct tree_with_sibling **data;
	int front,rear,capacity;

};

struct queue_ws * createqueue_ws(int n) {
	int i;
	struct queue_ws *temp = (struct queue_ws *) malloc (sizeof(struct queue_ws));
	if(temp == NULL)
		printf("unable to allocate memory\n");
	else {
		temp->rear = temp->front=-1;
		temp->capacity = n;
		temp->data = (struct tree_with_sibling **) malloc (n * sizeof(struct tree_with_sibling));
		for(i=0;i<n;i++)
			temp->data[i] = (struct tree_with_sibling *) malloc (sizeof(struct tree_with_sibling));
	}
	return temp;
}

void enqueue_ws(struct queue_ws *q, struct tree_with_sibling *node) {

	if(q->rear== q->capacity-1)
		printf("queue overflow\n");
	else {
		if(q->rear == -1)
			q->front = 0;
		q->rear++;
		q->data[q->rear] = node;
	/*	if(q->data[q->rear] == NULL)
			printf("enqued : NULL\n");
		else
			printf("enqued: %d\n",q->data[q->rear]->data);*/
	}
}


struct tree_with_sibling* dequeue_ws (struct queue_ws *q) {
	struct tree_with_sibling *temp;
	if(q->front == -1) 
		printf("queue underflow\n");
	else {
		temp = q->data[q->front];
		if(q->rear == q->front)
			q->rear = q->front = -1;
		else
			q->front++;
	}
/*	if(temp == NULL)
		printf("dequeing : NULL\n");
	else
		printf("dequeing %d\n",temp->data);*/
	return temp;
}

int isEmptyQueue_ws(struct queue_ws *q) {
	if(q->rear == -1)
		return 1;
	else 
		return 0;
}


void deleteQueue_ws (struct queue_ws *q) {
	free(q->data);
	free(q);
}

/*  ===============================================
		queue to hold tree with sibling
    =============================================== */

/*  ===============================================
                stack implementation
    =============================================== */


struct stack * createStack(int n) {
    int i;
  //  printf("creating a stack of size %d\n",n);
    struct stack *temp = (struct stack *) malloc (sizeof(struct stack));
    if(temp == NULL)
       printf("can not create the stack");
    else {
       temp->capacity = n;
       temp->top=-1;
       temp->data = (struct tree **) malloc (temp->capacity * sizeof(struct tree));
       for(i=0;i<n;i++)
           temp->data[i] = (struct tree *) malloc (sizeof(struct tree));
    }
    return temp;
}

void push (struct stack* s,struct tree *val){
    if(s->top == s->capacity -1){
        printf("stack is full\nstackoverflow occured\n");
        return ;
    }
    else {
      s->top++;
      s->data[s->top] = val;
     // printf("Entering s->data[%d] = %d\n",s->top,val);
      return ;
    }
}

struct tree * pop(struct stack* s) {
  struct tree *temp = NULL;
  if(s->top == -1) {
    printf("stack is empty\nstackunderflow occured\n");
    return temp;
  }
  else {
    return s->data[s->top--];
  }

}

struct tree * TOP(struct stack* s){
    struct tree *temp = NULL;
  if(s->top == -1) {
    //printf("stack is empty\nstackunderflow occured\n");
    return temp;
  }
  else {
    return s->data[s->top];
  }
}


void deleteStack(struct stack* s) {
     free(s->data);
     free(s);
}
/* ================================================== */

struct tree * createTreeFromArrayMid(int *arr,int front,int rear) {
    if(front > rear)
        return NULL;
    int mid = (front + rear)/2;
    struct tree *root = (struct tree *) malloc (sizeof(struct tree));
    root->data=arr[mid];
    root->left = createTreeFromArrayMid(arr,front,mid-1);
    root->right = createTreeFromArrayMid(arr,mid+1,rear);
    return root;

}


struct tree_with_sibling * createTreeFromArrayMid_ws(int *arr,int front,int rear) {
    if(front > rear)
        return NULL;
    int mid = (front + rear)/2;
    struct tree_with_sibling *root = (struct tree_with_sibling *) malloc (sizeof(struct tree_with_sibling));
    root->data=arr[mid];
    root->left = createTreeFromArrayMid_ws(arr,front,mid-1);
    root->right = createTreeFromArrayMid_ws(arr,mid+1,rear);
    return root;

}


void r_preorder (struct tree *root) {
   if(root == NULL)
       return;
    printf("%d ",root->data);
    r_preorder(root->left);
    r_preorder(root->right);

}

void r_postorder (struct tree *root) {
   if(root == NULL)
       return;
    r_postorder(root->left);
    r_postorder(root->right);
    printf("%d ",root->data);
}

void r_inorder (struct tree *root) {
   if(root == NULL)
       return;
    r_inorder(root->left);
    printf("%d ",root->data);
    r_inorder(root->right);
}

void i_preoder(struct tree *root) {
    struct stack *q = createStack(10);

    while(1) {
       while(root) {
          printf("%d ",root->data);
          push(q,root);
          root = root->left;
       }

       if(q->top == -1)
           break;
        root = pop(q);
        root=root->right;
     }
     printf("\n");
     deleteStack(q);
}


void i_inorder(struct tree *root) {
    struct stack *s = createStack(10);
    while(1) {
        while(root) {
            push(s,root);
            root = root->left;
        }
        if(s->top == -1)
            break;
        root = pop(s);
        printf("%d  ",root->data);
        root = root->right;
    }
    printf("\n");
    deleteStack(s);

}


void i_postorder(struct tree *root) {
    struct stack *s = createStack(10);
 /*   int count=0;
  //  printf("root->data=%d, root->left->data=%d,root->left->left->data=%d,root->left->right->data=%d,root->right->data=%d\n",root->data,root->left->data,root->left->left->data,root->left->right->data,root->right->data);
    while (1) {

       while(root) {
           printf("\npushing - %d\n",root->data);
            push(s,root);
            root=root->left;
       }
       if (s->top == -1)
           break;
       root = pop(s);
       printf("%d  ",root->data);
       if(TOP(s)->right == root) {
           root = pop(s);
           printf("%d  ",root->data);
       }

       if(TOP(s)->right != NULL){
            root=TOP(s)->right;
            printf("right root = %d\n",root->data);
       }
        else
            root = NULL;
    count++;
    if(count==10)
        break;

    }
    printf("\n");
    deleteStack(s);
*/

   while(1){
      if(root != NULL) {
        push(s,root);
        root=root->left;
      }
      else {
        if(s->top==-1)
            break;
        else if(TOP(s)->right == NULL){
            root=pop(s);
            printf("%d ",root->data);
            if(TOP(s)->right == root){
                printf("%d ",TOP(s)->data);
                pop(s);
            }
        }
        if(s->top != -1)
            root = TOP(s)->right;
        else
            root = NULL;
      }
   }
   printf("\n");
    deleteStack(s);
}


int get_number_of_node(struct tree *node) {
     if(node == NULL)
        return 0;
    else
        return get_number_of_node(node->left)+1+get_number_of_node(node->right);
}

int get_height_of_tree(struct tree *node) {
    int left_height,right_height;
    if(node == NULL)
       return 0;
    left_height = get_height_of_tree(node->left);
    right_height = get_height_of_tree(node->right);
    if(left_height > right_height) {
  //  	 printf("left=%d and data=%d\n",left_height,node->data);
       return left_height+1;
    }
    else {
  //  	  printf("right=%d and data=%d\n",right_height,node->data);
        return right_height+1;
     }
}

void levelorder(struct tree *root,int level,int cur_level) {
    if(root == NULL)
        return;
    if(cur_level == level) {
        printf("%d ", root->data);
    }
    levelorder(root->left,level,cur_level+1);
    levelorder(root->right,level,cur_level+1);

}

int i_get_height_of_tree_and_levelorder(struct tree *root){
    struct queue *q = createqueue(15);
    int size,height=0;
    struct tree *temp;
    enqueue(q,root);

    do {
        size = get_size(q);
        if(size !=0){
            printf("\nlevel %d:\n",height+1);
            while(size > 0){
                temp = dequeue(q);
                printf("%d ",temp->data);
                if(temp->left != NULL)
                    enqueue(q,temp->left);
                if(temp->right != NULL)
                    enqueue(q,temp->right);
                size --;
            }
            height++;
        }
        else
            break;
    } while(1);
    deletequeue(q);
    return height;
}

int findmax(struct tree *root) {
    int root_data,left_data,right_data,max_data;
    if(root->left == NULL && root->right == NULL)
      return root->data;
    root_data = root->data;
    if(root->left != NULL)
        left_data = findmax(root->left);
    if(root->right != NULL)
        right_data = findmax(root->right);
    if(left_data > right_data)
       max_data = left_data;
    else
       max_data = right_data;
    if(root_data > max_data)
       max_data = root_data;
    return max_data;
}


int findelement (struct tree *root, int x) {

if(root == NULL)
    return 0;
if(root->data == x)
    return 1;
if(findelement(root->left,x) != 0)
    return 1;
return (findelement(root->right,x));

}

int findHalfNodes( struct tree * root) {
    if(root == NULL)
    	return 0;
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)){
        printf("half node : %d\n",root->data);
        return 1;
    }
    return (findHalfNodes(root->left) + findHalfNodes(root->right));  
}

int areTreeConfigSame(struct tree *root1, struct tree *root2) {
	if(root1 == NULL && root2 == NULL )
		return 1;
       if(root1 == NULL || root2 == NULL)
		return 0;
	return (areTreeConfigSame(root1->left,root2->left) && areTreeConfigSame(root1->right,root2->right));

}

int areTreeSame(struct tree *root1, struct tree *root2) {
	if(root1 == NULL && root2 == NULL )
		return 1;
       if(root1 == NULL || root2 == NULL)
		return 0;
	return ((root1->data == root2->data) && areTreeConfigSame(root1->left,root2->left) && areTreeConfigSame(root1->right,root2->right));

}


//print root to leaf

void printRootToLeaf(struct tree *root, int *arr,int len) {
	if(root == NULL)
		return;
	arr[len++] = root->data;
	if(root->left == NULL && root->right == NULL)
		printarr(arr,len);
	else {
		printRootToLeaf(root->left,arr,len);
		printRootToLeaf(root->right,arr,len);	
	}
}

void printarr(int *arr,int len) {
	int i;
	for(i=0;i<len;i++) {
		printf("%d ",arr[i]);
		if(i!=len-1)
			printf("-> ");
	}

	printf("\n");
}

int sumOfAllEle(struct tree *root) {
	if(root == NULL)
		return 0;
	return(root->data + sumOfAllEle(root->left) + sumOfAllEle(root->right));
}


// mirror the tree

void mirror(struct tree *root) {
	
	if(root == NULL)
		return ;
	else {
		struct tree *temp = (struct tree *) malloc (sizeof(struct tree));
		temp = root->left;
		root->left = root->right;
		root->right =temp;
		mirror(root->left);
		mirror(root->right);
	}
}

// check if both tree are mirror with each other?
int checkIfMirror(struct tree *root1, struct tree *root2) {
	if(root1 == NULL && root2 == NULL)
		return 1;
	if(root1 == NULL || root2 == NULL)
		return 0;
	return((root1->data == root2->data) && checkIfMirror(root1->left,root2->right) && checkIfMirror(root1->right,root2->left));
}

// vertical travers means print all node with same vertical weight.
// vertical weight : if root->left   root_weight-1
//		     : if root->right  root_weight+1
void verticalTraverse(struct tree *root) {
	int min=0,max=0,i;
printf("debug-1\n");
       findMinMax(root,&min,&max,0);
 printf("min = %d  and max=%d\n",min,max);
	for(i=min;i<=max;i++){
		printf("\nvertical weight: %d: \n",i);
		traverseVertically(root,i,0);
	}
}

void findMinMax(struct tree *root, int *min, int *max, int curr) {
//printf("debug-2\n");
	if(root == NULL)
		return;
printf("debug-3\n");
printf("[in find] min= %d   max=%d curr=%d  data = %d\n", *min,*max,curr,root->data);

	if(curr < *min){
		*min = curr;
printf("[in find] min= %d  data = %d\n", *min,root->data);
	}
	if(curr > *max) {
		*max = curr;
printf("[in find] max= %d  data = %d\n", *min,root->data);
	}
	findMinMax(root->left,min,max,curr-1);
	findMinMax(root->right,min,max,curr+1);

}

void traverseVertically(struct tree *root,int curr,int count) {
	//static count=0;
	if(root == NULL)
		return;
	if(count == curr)
		printf("%d ",root->data);
	traverseVertically(root->left,curr,count-1);
	traverseVertically(root->right,curr,count+1);
}


// create a tree with siblings from a normal tree

void createTreeWithSibling(struct tree_with_sibling *root) {
	int i=0,j;
	struct queue_ws *q = createqueue_ws(15);
	struct tree_with_sibling *temp;
	enqueue_ws(q,root);
	enqueue_ws(q,NULL);
	while(!isEmptyQueue_ws(q)) {
		temp = dequeue_ws(q);
		if(temp == NULL) {
			if(!isEmptyQueue_ws(q))
				enqueue_ws(q,NULL);
		}
		else {
			temp->sibling = q->data[q->front];
			if(temp->left != NULL) {
				enqueue_ws(q,temp->left);
			}
			if(temp->right != NULL) {
				enqueue_ws(q,temp->right);
			}
		}
	}



deleteQueue_ws(q);
}

void display_tree_with_sibling(struct tree_with_sibling *root) {
	struct tree_with_sibling *temp;
	
	while (root != NULL) {
		temp = root->sibling;
		printf("sibling of : %d -> ",root->data);
		while(temp != NULL){
			printf("%d -> ",temp->data);
			temp = temp->sibling;
		}
		printf("NULL\n");			
		root = root->left;
	}
}

// same principle can be applied for level order traversal
// only push root->left in queue if root->data >= k1
// and push root->right id root->data <= k2
void printRange_2 (struct tree *root,int k1, int k2) {
	struct queue *q = createqueue(15);
	enqueue(q,root);
	while(q->rear != -1) {
	//	printf("processing : %d\n",root->data);
		root = dequeue(q);
		if(root->data >= k1 && root->left != NULL)
			enqueue(q,root->left);
		if(root->data <= k2 && root->right != NULL)
			enqueue(q,root->right);
		if(root->data >= k1 && root->data <= k2)
			printf(" % d ",root->data);
	}
	deletequeue(q);
}


int isAVL(struct tree *root) {

	int left,right;
	left = isAVL(root->left);
	if(!(left))
		return 0;
	right = isAVL(root->right);
	if(!(right))
		return 0;
	if(abs(left - right) > 1)
		return 0;
	else
		return max(left,right) + 1;
}

int max(int a, int b){

	if(a > b)
		return a;
	else return b;
}
