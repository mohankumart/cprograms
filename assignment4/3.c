#include<stdio.h>

void is_palindrome(int number){
	int originalNumber = number;
	int reversedNumber = 0, remainder;
	while(number != 0){
		remainder = number%10;
		reversedNumber = reversedNumber * 10 + remainder;
		number = number/10;
	}
	if(originalNumber == reversedNumber){
		printf("Palindrome\n");
	}else{
		printf("Not Palindrome\n");
	}
}

int main(){
	int n;
	printf("Enter the number: ");
	scanf("%d", &n);
	is_palindrome(n);
	return 0;
}
