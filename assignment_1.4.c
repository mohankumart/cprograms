#include<stdio.h>
#include<math.h>

float incircleArea(float c1, float c2, float m1, float m2){
	float radius = sqrt(((m2-m1)*(m2 -m1)) +((c2-c1)*(c2-c1)));
	printf("The radius is %f\n", radius);
	return 3.14 * radius * radius;
}


int main(){
	int x1, x2, y1, y2, z1, z2;
	float c1, c2;
	float m1, m2;
	printf("Enter x1 and x2: ");
	scanf("%d %d", &x1, &x2);
	printf("Enter y1 and y2: ");
	scanf("%d %d", &y1, &y2);
	printf("Enter z1 and z2: ");
	scanf("%d %d", &z1 , &z2);
	c1 = (x1+y1+z1)/3;
	c2 = (x2+y2+z2)/3;
	printf("Coordinates of incentre: %f %f\n", c1,c2);
	m1 = (x1+y1)/2;
	m2 = (x2+y2)/2;
	
	printf("Area of incircle: %f\n", incircleArea(c1, c2, m1, m2));
	return 0;
}
