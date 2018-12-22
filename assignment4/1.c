#include<stdio.h>
void is_power_of_two(int n){
	int x,count;
	while(n){
		x = n & -n;
		if(x == 1){
			count++;
		}
		n>>=1;	
	}
	if(count != 1){
		printf("no, the number is not power of two\n");
	}else{
		printf("yes, the number is power of two\n");
	}			
}

int main(){
	int n;
	printf("Enter the Number: ");
	scanf("%d", &n);
	is_power_of_two(n);
	return 0;
}
