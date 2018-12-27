#include<stdio.h>
#include<stdlib.h>
int main(){
	int n, i; 
	unsigned long *ptr;
	printf("Enter the number of numbers: ");
	scanf("%d", &n);
	ptr = (unsigned long *)calloc(n, sizeof(unsigned long));
	for(i=0; i<n; i++){
		printf("Enter %d: ", i);
		scanf("%ld", ptr+i);
	}
	
	unsigned long sum = 0;
	for(i=0;i<n;i++){
		sum += *(ptr+i);
	}
	printf("The average is %lu\n", sum/n);
	return 0;
}
