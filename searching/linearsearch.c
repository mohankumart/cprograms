#include<stdio.h>
#include<stdlib.h>

int linearSearchUsingArray(int *a, int size, int target){
	for(int index=0; index<size; index++){
		if(a[index] == target){
			return index;
		}
	}	
	return -1;		
}

struct node {
	int data;
	struct node *next;
};


struct node *linearSearchUsingLinkedList(struct node *head, int target){
	if(head){
		while(head){
			if(head->data == target){
				return head;
			}
			head = head->next;
		}
	}
	return head;
}

int main(){
	int a[10] = {1, 34, 56, 78, 99, 32, 12, 87, 65, 23};
	int size = sizeof(a)/sizeof(a[0]);
	printf("The index is %d\n", linearSearchUsingArray(a, size, 99));

	// construct linked list
	struct node *head = (struct node*)malloc(sizeof(struct node));
	head->data = 20;
	head->next = (struct node*)malloc(sizeof(struct node));
	head->next->data = 45;
	head->next->next = (struct node*)malloc(sizeof(struct node));
	head->next->next->data = 15;
   head->next->next->next = NULL;
	printf("The node data is %d\n", linearSearchUsingLinkedList(head, 15)->data);
	return 0;
}
