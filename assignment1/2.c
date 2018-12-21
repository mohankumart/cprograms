#include<stdio.h>

float calculateCircleRadius(float cc){
	return cc/(2 * 3.14);
}

float calculateCircleArea(float r){
	return (3.14 * r * r);
}

int main(){
	float squareSide, circleCurcumference, circleRadius;
	printf("Enter length of one side of square:");
	scanf("%f", &squareSide);
	circleCurcumference = 4*squareSide;
	circleRadius = calculateCircleRadius(circleCurcumference);
	printf("Radius of circle is: %f\n", circleRadius);
	printf("Area of circle is: %f\n", calculateCircleArea(circleRadius));
	return 0;
}
