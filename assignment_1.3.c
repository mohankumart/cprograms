#include<stdio.h>
void swap(int *p, int *q){
	*p = *p + *q;
	*q = *p - *q;
	*p = *p - *q;
}

int main(){
	int c, d;	
	printf("value of C and D:\n");
	scanf("%d %d", &c, &d);
	swap(&c, &d);
	printf("Value of C after swap: %d\n", c);
	printf("Value of D after swap: %d\n", d);
	return 0;
}
