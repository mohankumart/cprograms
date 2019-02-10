#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	struct node *left;
	int data;
	struct node *right;
}Node;


Node *constructBTreeRoot(Node *root_ref, int data){
	root_ref = (Node *)malloc(sizeof(Node));
	root_ref->data = data;
	root_ref->left = NULL;
	root_ref->right = NULL;
	return root_ref;
}

Node *constructBTreeChildren(Node *root_ref, int leftData, int rightData){
	Node *leftChild = (Node *)malloc(sizeof(Node));
	leftChild->data = leftData;
	leftChild->left = NULL;
	leftChild->right = NULL;

	Node *rightChild = (Node *)malloc(sizeof(Node));
	rightChild->data = rightData;
	rightChild->left = NULL;
	rightChild->right = NULL;
	
	root_ref->left = leftChild;
	root_ref->right = rightChild;
	return root_ref;		
}

void inorder(Node *root_ref){
	if(root_ref){
		if(root_ref->left)
			inorder(root_ref->left);
		printf("%d ", root_ref->data);
		if(root_ref->right)
			inorder(root_ref->right);
	}
}

Node *max(Node *root_ref){
	while(root_ref->right){
		root_ref = root_ref->right;
	}	
	return root_ref;
}

Node *min(Node *root_ref){
	while(root_ref->left){
		root_ref = root_ref->left;
	}
	return root_ref;
}


int main(){
	Node *root = NULL;
	
	//construct root	
	root = constructBTreeRoot(root, 20);

	//construct children
	root = constructBTreeChildren(root, 15, 30);
	root->left = constructBTreeChildren(root->left, 10, 17);
	root->right = constructBTreeChildren(root->right, 25, 40);
	root->left->left = constructBTreeChildren(root->left->left, 2, 12);
	root->left->right = constructBTreeChildren(root->left->right, 16, 19);
	
	//inorder traversal
	printf("Inorder Traversal of BST is ascending order----> ");
	inorder(root);	
	printf("\n");	

	//find max/min nodes
	printf("The Max value is %d\n",max(root)->data);	
	printf("The Min value is %d\n",min(root)->data);	
}



