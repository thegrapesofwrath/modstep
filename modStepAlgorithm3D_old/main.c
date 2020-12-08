#include "modStep.h"
#include "stdio.h"
#include "math.h"
//#include "main.h"

void main(){

	Point point1 = {1, 1,1};
	Point point2 = {-32, 2,5};
	Point distance = calculateDistance(point1, point2);
	long timePulse = calculateTimePulses(distance);

	printf("\n\n-------Variables-------\n\n");
	printf("Point:\t(%i,%i,%i)\n",point1.x,point1.y,point1.z);
	printf("Point:\t(%i,%i,%i)\n",point2.x,point2.y,point2.z);
	printf("Distance:\t(%i,%i,%i)\n",distance.x,distance.y,distance.z);
	printf("Timepulse:\t%i\n",timePulse);

	moveTo(distance,timePulse);

}