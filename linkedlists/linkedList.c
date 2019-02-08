#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *insertAtBegining(struct node *head_ref, int data){
	struct node *t = (struct node *)malloc(sizeof(struct node));
	t->data = data;
	if(head_ref){
		t->next = head_ref;
		head_ref = t;
	}else{
		t->next = NULL;
		head_ref = t;
	}
	return head_ref;
}

void insertAtEnd(struct node *head_ref, int data){
	while(head_ref->next != NULL){
		head_ref = head_ref->next;
	}
	struct node *t = (struct node *)malloc(sizeof(struct node));
   t->data = data;
	t->next = NULL;
	head_ref->next = t;
}

void insertAfter(struct node *head_ref, int cur_data, int data){
	while(head_ref->data != cur_data){
		head_ref = head_ref->next;
	}
	struct node *t = (struct node *)malloc(sizeof(struct node));
	t->data = data;
	t->next = head_ref->next;
	head_ref->next = t;	
}

struct node *deleteFromBegining(struct node *head_ref){
	if(head_ref == NULL){
		return NULL;
	}else if(head_ref->next == NULL){
		free(head_ref);
		return NULL;
	}else{
		struct node *t = head_ref;
		head_ref = head_ref->next;
		//free t from memory
		free(t);
		return head_ref;	
	}
}

void deleteLastNode(struct node *head_ref){
	while(head_ref->next->next != NULL){
		head_ref = head_ref->next;
	}
	free(head_ref->next);	
	head_ref->next = NULL;

}

void deleteNode(struct node *head_ref, int data){
	while(head_ref->next->data != data){
		head_ref = head_ref->next;
	}	
	struct node *temp = head_ref->next;
	head_ref->next = temp->next;
	free(temp); 
}

int main(){
	struct node *head = NULL;
	
	//insert at begining
	head = insertAtBegining(head, 10);

	//insert at end
	insertAtEnd(head, 20);
	
	//insert after
	insertAfter(head, 20, 40);
	insertAfter(head, 20, 50);
	insertAfter(head, 20, 60);

	//delete begining node
	head = deleteFromBegining(head);	

	//delete last node
	deleteLastNode(head);		
	
	//delete node
	deleteNode(head, 60);
	printf("data is -->%d\n",head->next->data);	
	return 0;
}
