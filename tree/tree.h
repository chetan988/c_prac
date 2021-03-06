#ifndef tree_h

#define tree_h

struct tree {
   int data;
   struct tree *left;
   struct tree *right;
};

// another tree have data,left,right,sibling

struct tree_with_sibling {
	int data;
	struct tree_with_sibling *left;
	struct tree_with_sibling *right;
	struct tree_with_sibling *sibling;
	
};


struct tree * createTreeFromArrayMid(int *,int,int);
// recursive printing tree
void r_preorder(struct tree *);
void r_postorder(struct tree *);
void r_inorder(struct tree *);

// iterative printing tree
void i_preoder(struct tree *);
void i_inorder(struct tree *);
void i_postorder(struct tree *);

// level order traversal
void levelorder(struct tree *,int,int);
//get number of nodes in the tree
int get_number_of_node(struct tree *);
int get_height_of_tree(struct tree *);
int i_get_height_of_tree_and_levelorder(struct tree *);

// now find the maximum in the tree
int findmax(struct tree *);

// find a elememnt in the tree

int findelement(struct tree *, int val);

// find number of half nodes

int findHalfNodes( struct tree *);

// are two tree structurally same?

int areTreeConfigSame(struct tree *, struct tree *);

// are two tree same?

int areTreeSame(struct tree *, struct tree *);

//print root to leaf

void printRootToLeaf(struct tree *, int *,int);

// sum of all element in the tree

int sumOfAllEle(struct tree *);

// mirror the tree

void mirror(struct tree *);

// check if both tree are mirror with each other?
int checkIfMirror(struct tree *, struct tree *);

// vertical traverse

void verticalTraverse(struct tree *);


// create a tree with sibling
// without recursion
struct tree_with_sibling * createTreeFromArrayMid_ws(int *, int, int);
void display_tree_with_sibling(struct tree_with_sibling *);
void createTreeWithSibling(struct tree_with_sibling *);

// check if tree is binary search tree or not

int isBST(struct tree *);
int isBST_1(struct tree *);
int isBST_2(struct tree *);
int isBST_3(struct tree *);
int isAVL (struct tree *);
#endif
