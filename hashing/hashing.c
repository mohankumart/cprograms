#include<stdio.h>

int hash(int input){
	return input%10;
}

int main(){
	printf("The mod 10 of 121 is --->%d\n", hash(121));
	return 0;	
}
