#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

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

Node *move_to_front(Node *head_ref){
	Node *p, *q;
	if(!head_ref || !head_ref->next)
		return head_ref;
	q=NULL, p=head_ref;
	while(p->next){
		q=p;
		p=p->next;
	}	
	q->next = NULL;
	p->next = head_ref;
	head_ref = p;
	return head_ref;
}

void printLinkedList(Node *head_ref){
	if(head_ref){
		printf("%d ", head_ref->data);
		printLinkedList(head_ref->next);
	}	
}

void printLinkedListInReverse(Node *head_ref){
	if(head_ref){
		printLinkedListInReverse(head_ref->next);
		printf("%d ", head_ref->data);
	}	
}

Node *reverseLinkedList(Node *current){
	Node *prev = NULL, *next = NULL;
	while(current){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
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
	insertAfter(head, 20, 70);
	insertAfter(head, 20, 80);
	
	//delete begining node
	head = deleteFromBegining(head);	

	//delete last node
	deleteLastNode(head);		
	
	//delete node
	deleteNode(head, 60);

	//move to front
	head = move_to_front(head);
	
	//print the linked list 
	printLinkedList(head);
	printf("\n");

	//print the linked list in reverse order
	printLinkedListInReverse(head);	
	printf("\n");
	
	//reverse the linked list
	head = reverseLinkedList(head);
   printLinkedList(head);
   printf("\n");

	return 0;
}
