#include<stdio.h>
int findMax(int x, int y, int z);
int findMin(int x, int y, int z);
int main(){
	int x, y, z;
	printf("Enter three numbers:");
	scanf("%d %d %d", &x, &y, &z);
	printf("maximum of the three numbers: %d\n", findMax(x, y, z));
	printf("minimum of the three numbers: %d\n", findMin(x, y, z));
	return 0;
}

int findMax(int x, int y, int z){
	return x>y?((x>z)?x:y):((y>z)?y:z);
}

int findMin(int x, int y, int z){
	return x<y?((x<z)?x:y):((y<z)?y:z);
}

