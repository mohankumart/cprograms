#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	float x, sum, newsum, term, newterm;
	int n;
	do{
		printf("The value of x less than 10: ");
		scanf("%f", &x);
	}while(x > 10);
	
	sum = x;
	term = x;
	n = 1;
	printf("The term 1 is:  %f\n", sum);
	do {
		term =  ((-1) * term * ((x * x)/((n+1)*(n+2))));
		newsum = term + sum;
		if(fabs(newsum - sum) < 0.001)
			break;
		else{
			sum = newsum;
		}
		n += 2;
	}while(1);
	printf("Approximate value of sin(x) %f\n", sum);
	return 0;
}
