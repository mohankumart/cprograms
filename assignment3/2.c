#include<stdio.h>
int main(){
	int n, r=0, result=0;
	printf("Enter the Number: ");
	scanf("%d",&n);
	do {
		r = n%10;
		result += r;
		n = n/10;
	}while(n != 0);
	printf("The result is %d\n", result);
	return 0;
}
