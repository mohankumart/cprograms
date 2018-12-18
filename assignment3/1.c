#include<stdio.h>
 int factorial(n){
	int result = 1;
	while(n != 0){
		result = result * n--;
	}
	return result;
}

int main(){
	int rows,i,spaces, stars,j, n,term;
	printf("Number od rows of Pascal triangle to print: ");
	scanf("%d", &rows);
	for(i=1; i<=rows; i++){
		//logic to print spaces
		for(spaces=rows-i; spaces>0; spaces--){
			printf(" ");
		}
		
		n = i-1;
		for(j=0; j<=n; j++){
			term = (factorial(n))/(factorial(n-j)*factorial(j));	
			printf("%d ", term);
		}
	
		printf("\n");
	}
	return 0;
}
