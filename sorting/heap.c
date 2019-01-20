
#include<stdio.h>
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

void max_heapify(int *a, int i, int size){
	int l, r, largest;
	l = 2*i + 1;
	r = 2*i + 2;
	
	if(l<size && a[l] > a[i]){
		largest = l;	
	}else{
		largest = i;
	}

	if(r<size && a[r] > a[largest]){
		largest = r;
	}

	if(largest != i){
		exchange(a, i, largest);		
		max_heapify(a, largest, size);
	}
}

void build_heap(int *a, int size){
	int i;
	for(i=((size/2)-1); i>=0; i--){
		max_heapify(a, i, size);
	}	
}

int heap_extract_max(int *a, int *size){
	int max;
	if(*size < 1){
		printf("No Heap");
		return -1;
	}	
	
	max = a[0];
	a[0] = a[*size-1];
	*size = *size - 1;
	max_heapify(a, 0, *size);
	return max;
}

void heap_increase_key(int *a, int i, int key){
	if(key < a[i]){
		printf("Error");
	}
	a[i] = key;
	while(i>0 && a[i/2] < a[i]){
		exchange(a, i/2, i);
		i = i/2;
	}

}

int main(){
	int arr[] = {9, 6, 5, 0, 8, 2, 1, 3};
	int size = sizeof(arr)/sizeof(arr[0]);
	printf("Before Heaify\n");
	printArray(arr, size);
	build_heap(arr, size);
	printf("After build Heap\n");
	printArray(arr, size);
	printf("Max is %d\n", heap_extract_max(arr, &size));
	printArray(arr, size);
	heap_increase_key(arr, 3, 400);
	printArray(arr, size);
	return 0;
}
