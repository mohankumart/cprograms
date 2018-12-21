#include<stdio.h>
char *checkIfCircle(int x1, int y1, int x2, int y2, int x3, int y3){
	// x1*x1 + y1*y1 = x2*x2 + y2*y2 = x3*x3 + y3*y3
	// First circle radius
	int r1 = sqrt(x1*x1 + y1*y1);
	int r2 = sqrt(x2*x2 + y2*y2) ; 
	int r3 = sqrt(x3*x3 + y3*y3) ;
	char *p;	
	if((r1 == r2) && ( r1== r3) && (r2 == r3)){
		p = "Yes";
	}else{
		p = "No";
	} 
	return p;
}

int main(){
	int x1, x2, x3, y1, y2, y3;
	printf("Assume center of circle coordinates are: 0 0 \n");
	printf("Enter x1 and y1: ");
	scanf("%d %d", &x1, &y1);
	printf("Enter x2 and y2: ");
	scanf("%d %d", &x2, &y2);
	printf("Enter x3 and y3: ");
	scanf("%d %d", &x3, &y3);

	printf("%s\n",checkIfCircle(x1,y1,x2,y2,x3,y3));
	return 0;
}
