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

char stepX(Point distance)
{
	char outX[10] = "";

	if (distance.x > 0)
	{
		strcpy(outX, "StepX\n");
		distance.x -= 1;
	}
	else if (distance.x < 0)
	{
		strcpy(outX, "-StepX\n");
		distance.x += 1;
	}

	// printf("%s", outX);
	return outX;
	// return distance;
}

char stepY(Point distance)
{
	char outY[10] = "";

	if (distance.y > 0)
	{
		strcpy(outY, "StepY\n");
		distance.y -= 1;
	}
	else if (distance.y < 0)
	{
		strcpy(outY, "-StepY\n");
		distance.y += 1;
	}

	// printf("%s", outY);
	// return distance;
	return outY;
}

char stepZ(Point distance)
{
	char outZ[10] = "";

	if (distance.z > 0)
	{
		strcpy(outZ, "StepZ\n");
		distance.z -= 1;
	}
	else if (distance.z < 0)
	{
		strcpy(outZ, "-StepZ\n");
		distance.z += 1;
	}

	// printf("%s", outZ);
	// return distance;
	return outZ;
}

// void doubleStep(Point distance, long i)
// {
// 	char out[35] = "";
// 	if (distance.x != 0 && distance.y != 0)
// 	{
// 		strcpy(out, stepX(distance));
// 		strcpy(out, stepY(distance));
// 	}
// 	else if (distance.x != 0 && distance.z != 0)
// 	{
// 		strcpy(out, stepX(distance));
// 		strcpy(out, stepZ(distance));
// 	}
// 	else if (distance.y != 0 && distance.z != 0)
// 	{
// 		strcpy(out, stepY(distance));
// 		strcpy(out, stepZ(distance));
// 	}
// 	// printf("Point:\t(%i,%i,%i)\n",distance.x,distance.y,distance.z);
// 	strcat(out, "\n");
// 	printf("%s", out);
// 	// return distance;
// }

void tripleStep(Point distance, long i)
{
	char out[35] = "";
	if ( i % distance.x == 0 && i % distance.y == 0 && i % distance.z == 0)
	{
		strcpy(out, stepX(distance));
		strcpy(out, stepY(distance));
		strcpy(out, stepY(distance));
	}
	else if (i % distance.x == 0 && i % distance.y == 0 && i % distance.z != 0)
	{
		strcpy(out, stepX(distance));
		strcpy(out, stepY(distance));
	}
	else if (i % distance.x == 0 && i % distance.y != 0 && i % distance.z == 0)
	{
		strcpy(out, stepX(distance));
		strcpy(out, stepZ(distance));
	}
	else if (i % distance.x != 0 && i % distance.y == 0 && i % distance.z == 0)
	{
		strcpy(out, stepY(distance));
		strcpy(out, stepZ(distance));
	}
	else if (i % distance.x == 0 && i % distance.y != 0 && i % distance.z != 0)
	{
		strcpy(out, stepX(distance));
	}
	else if (i % distance.x != 0 && i % distance.y == 0 && i % distance.z != 0)
	{
		strcpy(out, stepY(distance));
	}
	else if (i % distance.x != 0 && i % distance.y != 0 && i % distance.z == 0)
	{
		strcpy(out, stepY(distance));
	}
	strcat(out, "\n");
	printf("%s", out);
	// return distance;
}

int calculateTimePulses(Point distance)
{
	long out;
	if (distance.x != 0 && distance.y == 0 && distance.z == 0)
	{
		out = distance.x;
	}
	else if (distance.x != 0 && distance.y != 0 && distance.z == 0)
	{
		out = abs(distance.x * distance.y);
	}
	else if (distance.x == 0 && distance.y != 0 && distance.z == 0)
	{
		out = distance.y;
	}
	else if (distance.x == 0 && distance.y == 0 && distance.z != 0)
	{
		out = distance.z;
	}
	else if (distance.x == 0 && distance.y != 0 && distance.z != 0)
	{
		out = abs(distance.y * distance.z);
	}
	else if (distance.x != 0 && distance.y == 0 && distance.z != 0)
	{
		out = abs(distance.x * distance.z);
	}
	else if (distance.x != 0 && distance.y != 0 && distance.z != 0)
	{
		out = abs(distance.x * distance.y * distance.z);
	}
	else if (distance.x == 0 && distance.y == 0 && distance.z == 0)
	{
		out = 0;
	}
	return out;
}

// void definedSlopeMove(long i, Point distance){
// 		// if ( i % distance.x == 0 && i % distance.y == 0 && i % distance.z == 0 ){
// 		// 	printf("%i:\t",i);
// 		// 	tripleStep(distance.x,distance.y,distance.z);
// 		// }
// 		// else if ( i % distance.x == 0 && i % distance.y == 0 && i % distance.z == 0 ){

// 		// }
// 		printf("%i:\t",i);
// 		tripleStep(distance.x,distance.y,distance.z);

// }

// void undefinedSlopeMove(int i , Point distance){
// 	if (distance.x != 0){
// 		stepX(distance.x);
// 	}
// 	else if (distance.y != 0){
// 		stepY(distance.y);
// 	}
// }
bool moveSingleStep(Point distance)
{
	if ((distance.x != 0 && distance.y == 0 && distance.z == 0) || (distance.x == 0 && distance.y != 0 && distance.z == 0) || (distance.x == 0 && distance.y == 0 && distance.z != 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool moveDoubleStep(Point distance)
{
	if ((distance.x != 0 && distance.y != 0) || (distance.x != 0 && distance.z != 0) || (distance.z != 0 && distance.y != 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool moveTripleStep(Point distance)
{
	if ((distance.x != 0 && distance.y != 0 && distance.z != 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}
void moveTo(Point distance, long timePulse)
{
	printf("\n\n-------Move List-------\n\n");
	long i;
	for (i = 0; i < timePulse; i++)
	{
		// printf("%i:\t",i);
		// if (moveTripleStep(distance))
		// {
		// 	//definedSlopeMove(i, distance);
			tripleStep(distance, i);
		// }
		// else if (moveDoubleStep(distance))
		// {
		// 	doubleStep(distance, i);
		// }
		// else if (moveSingleStep)
		// {
		// 	//moveSingleStep();
		// 	//if x,y,z single step
		// }
		// printf("%i:\t",i);
		// printf("dist:\t(%i,%i,%i)\n",dist.x,dist.y,dist.z);
		// printf("dist:\t(%i,%i,%i)\n",dist.x,dist.y,dist.z);
	}
	printf("\n-----------------------\n\n");
}