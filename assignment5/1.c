#include<stdio.h>
void MaxMin(int arr[], int size, int *max_ptr, int *min_ptr){
	int i;
	for(i=0; i<size; i++){
		if(arr[i] >= *max_ptr){
			max_ptr = arr+i; 
		}
		if(arr[i] <= *min_ptr){
			min_ptr = arr+i;
		}
	}
	printf("The Max and Min are %d %d\n", *max_ptr, *min_ptr);
}

int main(){
	int arr[10] = {12, 4, 6, 10, 30, 321, 3, 8, 31, 45};
	int size = sizeof(arr)/sizeof(arr[0]);
	MaxMin(arr, size, arr, arr);
	return 0;
}
