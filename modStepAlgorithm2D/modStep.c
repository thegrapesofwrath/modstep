#include "modStep.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <stdbool.h>

Point calculateDistance(Point initial, Point final){
	Point out = {(final.x - initial.x), (final.y - initial.y)};
	return out;
}

void stepX(int x){
	if (x > 0){
		printf("StepX\n");
	}
	else{
		printf("-StepX\n");
	}
}

void stepY(int y){
	if (y > 0){
		printf("StepY\n");
	}
	else{
		printf("-StepY\n");
	}
}

void doubleStep(int x, int y){
	char outX[10];
	char outY[10];
	char out[20];

	if (x > 0){
		strcpy(outX,"StepX\t");
	}
	else{
		strcpy(outX,"-StepX\t");
	}

	if (y > 0){
		strcpy(outY,"StepY\n");
	}
	else{
		strcpy(outY,"-StepY\n");
	}

	strcpy(out, outX);
	strcat(out, outY);
	printf("%s",out);
}

int calculateTimePulses(Point distance){
	long out;
	if (distance.x == 0 && distance.y != 0){
		out = distance.y;
	}
	else if (distance.x != 0 && distance.y == 0){
		out = distance.x;
	}
	else{
		out = abs(distance.x * distance.y);
	}
	return out;
}

void definedSlopeMove(int i, Point distance){
		if (i == 0)
		{
			printf("%i:\t",i);
			doubleStep(distance.x,distance.y);
		}
		else if ( i % distance.x == 0 && i % distance.y == 0 ){
			printf("%i:\t",i);
			doubleStep(distance.x,distance.y);
		}
		else if ( i % distance.x == 0) {
			printf("%i:\t",i);
			stepY(distance.y);
		}
		else if ( i % distance.y == 0)
		{
			printf("%i:\t",i);
			stepX(distance.x);
		}
		// else
		// {
		// 	printf("Failed to Move\n");
		// }
}

void undefinedSlopeMove(int i , Point distance){
	if (distance.x != 0){
		stepX(distance.x);
	}
	else if (distance.y != 0){
		stepY(distance.y);
	}
}
bool slopeIsDefined(Point distance){
	if (distance.x == 0 || distance.y ==0){
		return false;
	}
	else{
		return true;
	}
}

void moveTo(Point distance, long timePulse){
	printf("\n\n-------Move List-------\n\n");
	long i;
	for (i = 0; i < timePulse; i++)
	{
		// printf("%i:\t",i);
		if (slopeIsDefined(distance)){
			definedSlopeMove(i, distance);
		}
		else{
			undefinedSlopeMove(i, distance);
		}

	}
	printf("\n-----------------------\n\n");
}