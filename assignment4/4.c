#include<stdio.h>
int binarysearchpeak(int a[], int i, int j){
	int mid, max1, max2;
	if(j-i == 0){
		return a[i];	
	}else if(j-i == 1){
		return a[i]>a[j]?a[i]:a[j];
	}else{
		mid = (i+j)/2;
		max1 = binarysearchpeak(a, i, mid);
		max2 = binarysearchpeak(a,mid+1, j);
		if(max1 > max2){
			return max1;
		}else{
			return max2;
		}
	}
	return 0;		
}

int main(){
	int a[] = {4, 5, 2, 9, 12, 11, 90, 3, 45, 111, 22, 6};
	int length = sizeof(a)/sizeof(a[0]);
	printf("The peak is %d\n", binarysearchpeak(a, 0, length-1));
	return 0;
}
