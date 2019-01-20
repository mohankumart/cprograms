#include<stdio.h>
void insertionSort(int *a, int size);
int main(){
	int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}, i, size;
	size = sizeof(a)/sizeof(a[0]);
	printf("Before Sort: ");
	for(i=0; i<size; i++){
		printf("%d ", a[i]);
	}
	printf("\n After Sort: ");
	insertionSort(a, size); 	
	for(i=0; i<size; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

void insertionSort(int *a, int size){
	int i, j, key;
	for(j=1; j<size; j++){
		key = a[j];
		i = j-1;
		while(i>=0 && a[i]>key){
			a[i+1] = a[i];
			i = i-1;
		}
		a[i+1] = key;
	}
}
