#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	struct node *left;
	int data;
	struct node *right;
}Node;


Node *constructBTreeRoot(Node *root_ref){
	root_ref = (Node *)malloc(sizeof(Node));
	root_ref->data = 1;
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

void doubleorder(Node *root_ref){
	if(root_ref){
		printf("%d ", root_ref->data);
		doubleorder(root_ref->left);
		printf("%d ", root_ref->data);
		doubleorder(root_ref->right);
	}
}

void tripleorder(Node *root_ref){
	if(root_ref){
		printf("%d ", root_ref->data);
		tripleorder(root_ref->left);
		printf("%d ", root_ref->data);
		tripleorder(root_ref->right);
		printf("%d ", root_ref->data);
	}	
}

void B(Node *t);

void A(Node *t){
	if(t){
		printf("%d ", t->data);
		B(t->left);
		B(t->right);
	}
}

void B(Node *t){
	if(t){
		A(t->left);
		printf("%d ", t->data);
		A(t->right);		
	}
}

int main(){
	Node *root = NULL;
	
	//construct root	
	root = constructBTreeRoot(root);

	//construct children
	root = constructBTreeChildren(root, 2, 3);
	root->left = constructBTreeChildren(root->left, 4, 5);
	root->right = constructBTreeChildren(root->right, 6, 7);

	//inorder traversal
	printf("Inorder Traversal----> ");
	inorder(root);	
	printf("\n");	

	//double order traversal
	printf("Double Order Traversal---->");
	doubleorder(root);
	printf("\n");

	//triple order traversal
	printf("Tripe Order Traversal--->");
	tripleorder(root);
	printf("\n");

	// indirect recursion on trees on A
	printf("Indirect recursion calling on A----->");
	A(root);
	printf("\n");	

	// indirect recursion on trees on A
	printf("Indirect recursion calling on B----->");
	B(root);
	printf("\n");	
	
	return 0;
}
