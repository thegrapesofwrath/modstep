#include "modStep.h"
#include "stdio.h"
#include "math.h"
//#include "main.h"

void main(){

	Point point2 = {-1200, 500};
	Point point1 = {-300, 2400};
	Point distance = calculateDistance(point1, point2);
	long timePulse = calculateTimePulses(distance);

	printf("\n\n-------Variables-------\n\n");
	printf("Point:\t(%i,%i)\n",point1.x,point1.y);
	printf("Point:\t(%i,%i)\n",point2.x,point2.y);
	printf("Distance:\t(%i,%i)\n",distance.x,distance.y);
	printf("Timepulse:\t%i\n",timePulse);

	moveTo(distance,timePulse);

}