#include "modStep.h"
#include "stdio.h"
#include "math.h"
//#include "main.h"

int main(){

	Point point1 = {0, 0,0};
	// Point point1 = newPoint(0, 0,0);
	Point point2 = {0, 2,0};
	// Point point2 = newPoint(10, 1,0);
	Point distance = calculateDistance(point1, point2);
	long timePulse = calculateTimePulses(distance);

	printf("\n\n-------Variables-------\n\n");
	printf("Point:\t(%ld,%ld,%ld)\n",point1.x,point1.y,point1.z);
	printf("Point:\t(%ld,%ld,%ld)\n",point2.x,point2.y,point2.z);
	printf("Distance:\t(%ld,%ld,%ld)\n",distance.x,distance.y,distance.z);
	printf("Timepulse:\t%ld\n",timePulse);

	moveTo(distance,timePulse);

return(0);
}