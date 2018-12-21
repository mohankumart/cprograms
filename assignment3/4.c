#include<stdio.h>
int main(){
	int n, i, fib0, fib1, sum, j, temp;
	printf("Number of terms (n) in Fibonacci sequence to be considered: ");	
	scanf("%d", &n);
	fib0 = 0;
	fib1 = 1;
	for(i=0; i<n-2; i++){
		sum = fib0 + fib1;
		fib0 = fib1;
		fib1 = sum;
		for(j=fib0; j<fib1; j++){
			temp = j+1;
			if(temp != fib1){
					printf("%d ", temp);
			}
		}
	}
	printf("\n");
	return 0;
}

