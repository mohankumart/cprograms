#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int rows = 5, cols;
	char *a[rows], *temp; 
	int i, j;
	
	// Logic to read strings from user
	for(i=0; i<rows; i++){
		printf("Enter number of words in string: ");
		scanf("%d", &cols);
		a[i] = (char *)malloc(cols * sizeof(char));
		printf("Enter Name: ");
		scanf("%s", a[i]);
	}
	
	// Sort the strings in the array
	for(i=0; i<rows-1; i++){
		for(j=i+1;j<rows; j++){
			if(strcmp(a[i], a[j])>0){
				temp = (char*)malloc(strlen(a[i])*sizeof(char));
				strcpy(temp, a[i]);
				strcpy(a[i], a[j]);
				strcpy(a[j], temp);
				free(temp);
			}
		}
	}

	printf("The Lexicographical order: \n");
	for(i=0; i<rows; i++){
		printf("%s\n", *(a+i)+0);
	}
	
	
	return 0;
}
