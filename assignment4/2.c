#include<stdio.h>

void swap(int *p, int *q){
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

int GCD(a, b){
	if(a < b){
		swap(&a, &b);
	}
	int q,r;
	do {
		r = a%b;
		q = a/b;
		a = b;
		if(r!=0) {
				b = r;
		}
	}while(r!=0);	
	return b;
}

int main(){
	int a, b;
	printf("Enter two numbers (a b): ");
	scanf("%d %d", &a, &b);
	printf("The GCD is %d\n", GCD(a, b));
	return 0;
}
