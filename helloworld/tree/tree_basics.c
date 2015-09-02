#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int number_of_nodes,height,i;
    printf("creating the tree\n");
    struct tree *root = createTreeFromArrayMid(arr,0,9);
    int arr1[10] = {1,2,3,4,5,6,7,8,9},arr2[10];
    printf("creating the tree\n");
    struct tree *root1 = createTreeFromArrayMid(arr1,0,8);
    number_of_nodes = get_number_of_node(root);
    printf("\n===========================\ntree contain %d nodes\n",number_of_nodes );
    height = get_height_of_tree(root);
    printf("\ntree height is : %d\n===========================\n",height );

    printf("printing in recursive method\n");
    printf("\nprinting the tree in preorder\n");
    r_preorder(root);
    printf("\nprinting the tree in postorder\n");
    r_postorder(root);
    printf("\nprinting the tree in inorder\n");
    r_inorder(root);
    printf("\n\n");
    printf("printing in iterative method\n");
    printf("\nprinting the tree in preorder\n");
    i_preoder(root);
    printf("\nprinting the tree in inorder\n");
    i_inorder(root);
  //  printf("\nprinting the tree in postorder\n");
  //  r_postorder(root);
  //  i_postorder(root);

    //  level order traversal
    printf("\nprinting the tree in level order\n");
    for(i=0;i<height;i++){
        printf("\nlevel - %d\n",i+1);
        levelorder(root,i,0);
    }
    printf("\ntree height is : %d\n",i_get_height_of_tree_and_levelorder(root) );
    printf("maximum element in the tree is : %d\n",findmax(root));

    if(findelement(root,3))
       printf("element found\n");
       else
       printf("element not found\n");

    if(findelement(root,10))
       printf("element found\n");
    else
       printf("element not found\n");
    if(findelement(root,9))
       printf("element found\n");
    else
       printf("element not found\n");

    if(findelement(root,4))
       printf("element found\n");
    else
       printf("element not found\n");


     printf("the tree has %d half nodes\n",findHalfNodes(root));

     if(areTreeConfigSame(root,root1))
	printf("Both tree are structurally same\n");
     else
	printf("both tree are stucturally not same\n");

     if(areTreeSame(root,root1))
	printf("Both tree are same\n");
     else
	printf("both tree are not same\n");

	// print root to leaf
	printRootToLeaf(root,arr2,0);

	printf("sum of all element in the tree is : %d\n",sumOfAllEle(root));
	printf("\nmirroring the tree \n");
	mirror(root);
	printRootToLeaf(root,arr2,0);
       printf("\ncheck if both tree are mirror identical\n");
	if(checkIfMirror(root,root1)) {
		printf("both tree are mirror symetrical\n");
	}
	else {
		printf("both tree are not mirror symetrical\n");
	}

	printf("\n\ntraversing vertivally\n");
	verticalTraverse(root);
	printf("\n");
	
	printf("creating a tree with siblings\n\n");
	struct tree_with_sibling *root_ws = createTreeFromArrayMid_ws(arr,0,9);
      /*struct tree_with_sibling *temp = root_ws;
	while(temp != NULL) {
		printf("[main] %d\n",temp->data);
		temp= temp->left;
 	} */
	
	createTreeWithSibling(root_ws);
	
	display_tree_with_sibling(root_ws);
	
    return 0;
}
