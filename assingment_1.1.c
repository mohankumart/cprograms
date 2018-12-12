#include<stdio.h>

int findNthTerm(int ft, int cd, int n){
	return ft + (n-1)*cd;
}

int findSumUptoNthTerm(int ft, int nt, int n){
	return n/2 * (ft + nt);		
}

int main(){
	int ft, cd, n, nt;
	printf("Enter First Term:");
	scanf("%d", &ft);
	printf("Enter comman difference:");
	scanf("%d", &cd);
	printf("Enter Number of Terms:");
	scanf("%d", &n);
	nt = findNthTerm(ft, cd, n); 
	printf("The nth Term is %d\n", nt);
	printf("The sum upto to nth term is %d\n", findSumUptoNthTerm(ft, nt, n));
	return 0;
}


