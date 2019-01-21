#include<stdio.h>
int partition(int *a, int p, int r);
void exchange(int *a, int i, int j);
void printArray(int *a, int size);
void quicksort(int *a, int p, int r);

int main(){
	int arr[8] = {6, 9, 5, 0, 8, 2, 4, 7};
	int size = sizeof(arr)/sizeof(arr[0]);
	printArray(arr, size);
	quicksort(arr, 0, 7);	
	printArray(arr, size);
	return 0;
}

void printArray(int *a, int size){
	int i;
	for(i=0; i<size; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

void exchange(int *a, int i, int j){
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void quicksort(int *a, int p, int r){
	int q;
	if(p<r){
		q = partition(a,p,r);
		quicksort(a, p, q-1);
		quicksort(a, q+1, r);
	}
}

int partition(int *a, int p, int r){
	int x, i = p-1, j;
	x = a[r];
	for(j=p;j<=r-1;j++){
		if(a[j] <= x){
			i=i+1;
			exchange(a, i, j);
		}	
	}
	exchange(a, i+1, r);
	return i+1;	
}
