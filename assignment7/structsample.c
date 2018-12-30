#include<stdio.h>
int main(){
	
	struct node {
		int i;
		int *c;
	};
		
	struct node a[2], *p;
	int b[2] = {30, 40};

	p = a;
	a[0].i = 10;
	a[1].i = 20;

	a[0].c = b;

	//printf("%d\n", ++p->i);	
	
	//int x = (++p)->i; 
	//printf("%d\n", x);

	//int x = (p++) -> i;
	//printf("%d\n", x);

	//int x = *p->c;
	//printf("%d\n", x);

	//int x = *p->c++;
	//printf("%d\n", x);

	//int x = (*p->c)++;
	//printf("%d\n", x);	

	int x = *p++ -> c;
	printf("%d\n", x);

	return 0;
}
