#include "modStep.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <stdbool.h>

Point calculateDistance(Point initial, Point final)
{
	Point out = {(final.x - initial.x), (final.y - initial.y), (final.z - initial.z)};
	return out;
}

Point newPoint(long x, long y, long z)
{
	Point pnt =  {.x = x, .y = y, .z = z};
	return pnt;
}

char* stepX(Point distance)
{
	char *outX = malloc (sizeof (char) * 10);
	if (distance.x > 0)
	{
		strcpy(outX, "StepX\t");
	}
	else if (distance.x < 0)
	{
		strcpy(outX, "-StepX\t");
	}
	return outX;
}

char* stepY(Point distance)
{
	char *outY = malloc (sizeof (char) * 10);
	if (distance.y > 0)
	{
		strcpy(outY, "StepY\t");
	}
	else if (distance.y < 0)
	{
		strcpy(outY, "-StepY\t");
	}
	return outY;
}

char* stepZ(Point distance)
{
	char *outZ = malloc (sizeof (char) * 10);
	// printf("\nz dist: %i\n",distance.z);
	if (distance.z > 0)
	{
		strcpy(outZ, "StepZ\t");
	}
	else if (distance.z < 0)
	{
		strcpy(outZ, "-StepZ\t");
	}
	return outZ;
}

// int crement(int pnt){
// 	if (pnt > 0){
// 		return -1;
// 	}
// 	else if (pnt < 0)
// 	{
// 		return 1;
// 	}
// 	else
// 	{
// 		return 0;
// 	}
// }
bool modCheck(int pnt,int i){
	if (pnt == 0){
		return false;
	}
	else if (i % pnt != 0){
		return false;
	}
	else{
		return true;
	}
}
void tripleStep(Point distance, long i)
{
	char out[50] = "";
	// printf("\ti:%i\t(%i,%i,%i)\n",i,distance.x,distance.y,distance.z);
	Point _x = newPoint(0,distance.y,distance.z);
	Point _y = newPoint(distance.x,0,distance.z);
	Point _z = newPoint(distance.y,distance.x,0);
	// printf("\ti:%i\t(%i,%i,%i)\n",i,_x.x,_x.y,_x.z);
	// printf("\ti:%i\t(%i,%i,%i)\n",i,_y.x,_y.y,_y.z);
	// printf("\ti:%i\t(%i,%i,%i)\n",i,_z.x,_z.y,_z.z);
	
	// bool bStepX = modCheck(distance.z * distance.y,i);
	// bool bStepY = modCheck(distance.x * distance.z,i);
	// bool bStepZ = modCheck(distance.y * distance.x,i);
	printf("%ld _x: %ld\n",i,calculateTimePulses(_x));
	printf("%ld _y: %ld\n",i,calculateTimePulses(_y));
	printf("%ld _z: %ld\n",i,calculateTimePulses(_z));

	bool bStepX = modCheck(calculateTimePulses(_x),i);
	bool bStepY = modCheck(calculateTimePulses(_y),i);
	bool bStepZ = modCheck(calculateTimePulses(_z),i);


	if ( bStepX && bStepY && bStepZ)
	{
		strcat(out, (char *)stepX(distance));
		strcat(out, (char *)stepY(distance));
		strcat(out, (char *)stepZ(distance));
		free;
		printf(" Branch 1:\t");
	}
	else if (bStepX && bStepY && !bStepZ)
	{
		strcat(out, (char *)stepX(distance));
		strcat(out, (char *)stepY(distance));
		free;
		printf(" Branch 2:\t");
	}
	else if (bStepX && !bStepY && bStepZ)
	{
		strcat(out, (char *)stepX(distance));
		strcat(out, (char *)stepZ(distance));
		free;
		printf(" Branch 3:\t");
	}
	else if (bStepX && !bStepY && !bStepZ)
	{
		strcat(out, (char *)stepX(distance));
		free;
		printf(" Branch 4:\t");
	}
	else if (!bStepX && bStepY && bStepZ)
	{
		strcat(out, (char *)stepY(distance));
		strcat(out, (char *)stepZ(distance));
		free;
		printf(" Branch 5:\t");
	}
	else if (!bStepX && bStepY && !bStepZ)
	{
		strcat(out, (char *)stepY(distance));
		free;
		printf(" Branch 6:\t");
	}
	else if (!bStepX && !bStepY && bStepZ)
	{
		strcat(out, (char *)stepZ(distance));
		free;
		printf(" Branch 7:\t");
	}
	if(strlen(out) > 0)
	{
		strcat(out, "\n");
		printf("%s", out);
	}
}

int calculateTimePulses(Point distance)
{
	long out;
	if (distance.x != 0 && distance.y == 0 && distance.z == 0)
	{
		return out = distance.x;
	}
	else if (distance.x != 0 && distance.y != 0 && distance.z == 0)
	{
		return out = abs(distance.x * distance.y);
	}
	else if (distance.x == 0 && distance.y != 0 && distance.z == 0)
	{
		return out = distance.y;
	}
	else if (distance.x == 0 && distance.y == 0 && distance.z != 0)
	{
		return out = distance.z;
	}
	else if (distance.x == 0 && distance.y != 0 && distance.z != 0)
	{
		return out = abs(distance.y * distance.z);
	}
	else if (distance.x != 0 && distance.y == 0 && distance.z != 0)
	{
		return out = abs(distance.x * distance.z);
	}
	else if (distance.x != 0 && distance.y != 0 && distance.z != 0)
	{
		return out = abs(distance.x * distance.y * distance.z);
	}
	else if (distance.x == 0 && distance.y == 0 && distance.z == 0)
	{
		return out = 0;
	}
}

void moveTo(Point distance, long timePulse)
{
	printf("\n\n-------Move List-------\n\n");
	long i;
	for (i = 0; i < timePulse; i++)
	{
		tripleStep(distance, i);
	}
	printf("\n-----------------------\n\n");
}