#include<stdio.h>
#define m 3
#define n 3

void matTransposefloat(int a[][n], int at[][n]){
	int i, j, atRow=0, atCol=0;
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			at[atRow][atCol] = a[i][j];
			atRow++;
		}
		atRow = 0;
		atCol++;
	}
}

void orthoNormal(int a[][n], int at[][n]){
	int i, j, p, r, flag = 1;
 	matTransposefloat(a, at);
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			r = 0;
			for(p=0; p<m; p++){
				r+= (a[i][p]*at[p][j]);	
			}
			
			if(i==j && r!=1){
				flag = 0;
			}else if(i!=j && r!=0){
				flag = 0;
			}
		}
	}
	if(flag){
		printf("The matrix orthonormal\n");
	}else{
		printf("The matrix is not orthonormal\n");
	}
}

int main(){
	int a[][n] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	int at[m][n];
	orthoNormal(a, at);	
	return 0;
}
