#include<stdio.h>
void printArray(int *a, int size);
void merge(int *a, int p, int q, int r){
	int i, j, k, n1, n2;
	n1 = q-p+1;
	n2 = r-q;
	int L[n1+1], R[n2+1];

	for(i=0; i<n1; i++){
		L[i] = a[p+i];
	}

	for(j=0; j<n2; j++){
		R[j] = a[q+j+1];	
	}

	L[n1] = 10000;
	R[n2] = 10000;

	i=0;
	j=0;
	
	for(k=p; k<=r; k++){
		if(L[i] <= R[j]){
			a[k] = L[i];
			i = i+1;
		}else{
			a[k] = R[j];
			j = j+1;		 
		}
	}
}

void printArray(int *a, int size){
	int i;
	for(i=0; i<size; i++){
		printf("%d ", a[i]);
	}
	printf("\n");	
}

void merge_sort(int *a,int p,int r){
	int q;
	if(p<r){
		q = (p+r)/2;
		merge_sort(a, p, q);
		merge_sort(a, q+1, r);
		merge(a, p, q, r);
	}
}

int main(){
	int arr[11] = {1, 89, 2, 0, 5, 7, 8, 2, 4, 6, 9};
	int size = sizeof(arr)/sizeof(arr[0]);
	printArray(arr, size);	
	merge_sort(arr, 0, 10);
	printArray(arr, size);
	return 0;
}
