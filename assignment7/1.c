#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct box {
	float s1,s2,s3;
};

float arrayBox(struct box *box){
	return box->s1 > box->s2? (box->s1 > box->s3? box->s1: box->s3): (box->s2 > box->s3? box->s2: box->s3);
}

int main(int argc, char *argv[]){
	// Read the size n
	if(argc > 1){
		char *fileName = (char *)malloc(100*sizeof(char));
		strcpy(fileName, argv[1]);
		FILE *fp = fopen(fileName, "r");
		int n,i;
		if(fp != NULL){
			fscanf(fp,"%d", &n);
			struct box *box_array = (struct box*)malloc(n * sizeof(struct box));
			float s1, s2, s3, sum;
			for(i=0;i<n;i++){
				fscanf(fp, "%f %f %f", &s1, &s2, &s3);
				(box_array+i)->s1 = s1;
				(box_array+i)->s2 = s2;
				(box_array+i)->s3 = s3;
				sum += arrayBox(box_array+i);
			}
			fclose(fp);
			printf("The Maximum height is %f\n", sum);
		}else{
			printf("Error opening the file");
		}
	}

	return 0;
}
