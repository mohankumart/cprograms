#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int top;
	char *a;
	int capacity;
}Stack;

Stack *s = NULL;

int isFull(){
	return s->capacity-1 == s->top;
}

int isEmpty(){
	return s->top == -1;
}

void createStack(int capacity){
	s = (Stack *)malloc(sizeof(Stack));
	s->top = -1;
	s->capacity = capacity;
	s->a = (char *)malloc(capacity * sizeof(char));
}

void push(char operator){
	if(!isFull())
		s->a[++s->top] = operator;
}

char pop(){
	if(!isEmpty())
		return s->a[s->top--];
	else
		return -1; 
}

int checkifoperator(char ch){
	if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')){
		return -1;
	}else{
		return 1;
	}
}

int operatorPrecesence(char ch){
	int precedence;
	switch(ch){
		case '(':
			precedence = 1;
			break;
		case '+':
		case '-':
			precedence = 2;
			break;
		case '*':
		case '/':
			precedence = 3;
			break;
		default:
			precedence = 0;
	}
	return precedence;
}

char *infixtopostfix(char *string){
	//loop over each character to verify if it operator or operand
	int i,j=0;
	char *output;
	for(i=0; string[i] !='\0'; i++){
		if(checkifoperator(*(string+i)) == 1){
			// add support for brackets
			if(*(string+i) == ')'){
				char topToken = pop();
				while(topToken != '('){
					output = (char *)realloc(output, sizeof(char));
               output[j++] = topToken;
					topToken = pop();
				}
			}else if(*(string+i) == '('){
				push(*(string+i));
			}else{
				while(!isEmpty() && (operatorPrecesence(string[i]) <= operatorPrecesence(s->a[s->top]))){
					output = (char *)realloc(output, sizeof(char));
					output[j++] = pop();
				}
				push(*(string+i));
			}	
		}else{	
			output = (char *)realloc(output, sizeof(char));
			output[j++] = *(string+i);
		}
	}	
	while(!isEmpty()){
		output = (char *)realloc(output, sizeof(char));
      output[j++] = pop();
	}
	return output;	
}

int evaluatePostfix(char *string){
	int i,value=0,op1, op2;
	for(i=0; string[i] !='\0'; i++){
		if(checkifoperator(*(string+i)) == 1){
			op2 = pop();
			op1 = pop();
			switch(*(string+i)){
				case '+': 
					push(op1 + op2);
					break;
				case '-':
					push(op1 - op2);
					break;
				case '*':
					push(op1 * op2);
					break;
				case '/':
					push(op1 / op2);
					break;		
			}
		}else{
			push(*(string+i)-'0');
		}		
	}
	return pop();
}

int main(){
	createStack(100);
	// read the infix string
	char *string;
	printf("Enter infix expression: ");
	scanf("%s", string);
	char *postfixNotation = infixtopostfix(string);
	printf("The postfix expression: %s\n", postfixNotation);
	printf("The value of expression is %d\n", evaluatePostfix(postfixNotation));
	return 0;
}
