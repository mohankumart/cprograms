#include<stdio.h>
int main(){
	int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
	
	printf("the ten integers:");
	scanf("%d%d%d%d%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5,&a6,&a7, &a8, &a9, &a10);
	int count=0;
	if(a1 == 1 && a2 == 0 && a3 == 1 && a4 == 1){
		count++;
	}
	if(a2 == 1 && a3 == 0 && a4 == 1 && a5 == 1){
		count++;
	}
	if(a3 == 1 && a4 == 0 && a5 == 1 && a6 == 1){
		count++;
	}
	if(a4 == 1 && a5 == 0 && a6 == 1 && a7 == 1){
		count++;
	}
	if(a5 == 1 && a6 == 0 && a7 == 1 && a8 == 1){
		count++;
	}
	if(a6 == 1 && a7 == 0 && a8 == 1 && a9 == 1){
		count++;
	}
	if(a7 == 1 && a8 == 0 && a9 == 1 && a10 == 1){
		count++;
	}
	printf("number of times the pattern occurs minimum of the three numvbers: %d\n", count);
	return 0;
}
