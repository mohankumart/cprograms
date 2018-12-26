#include<stdio.h>
void swap(int *aptr, int *bptr){
	int temp;
	temp = *aptr;
	*aptr = *bptr;
	*bptr = temp;	
}

int main(){
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	int size = sizeof(a)/sizeof(a[0]);
	int *first = a, *last = a + (size - 1);
	while(first < last || last-first == 0){
		swap(first, last);
		first++;
		last--;	
	}
	int i;
	for(i=0; i<size; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
