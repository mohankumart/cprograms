#include<stdio.h>
#include<stdlib.h>
void sortArray(int size, double *a){
	int i, j;
	double temp;
	for(i=0; i<size; i++){
		for(j=i+1; j<size; j++){
			if(a[i] > a[j]){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}				
		}
	}
}

double findMedian(int size, double *a){
	int median;
	if(size%2 == 0){
		median = (size+1)/2;
		return (a[median] + a[median-1])/2;
	}else{
		median = (size+1)/2;
		return a[median-1];
	}
}

int main(int argc, char *argv[]){
	double a[argc-1];
	int i, j=0;
	for(i=1; i<argc; i++){
		a[j++] = atof(argv[i]);
	}
	
	sortArray(argc-1, a);
	printf("The median is: %f\n", findMedian(argc-1,a));
	return 0;
}
