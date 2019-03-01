#include<stdio.h>
#include<stdlib.h>


struct node {
	int data;
};

int main(){

	struct node *a[4];
	for(int i=0; i<4;i++){
	 	a[i]= (struct node*)malloc(sizeof(struct node));
	}

	a[0]->data = 10;

	return 0;
}
