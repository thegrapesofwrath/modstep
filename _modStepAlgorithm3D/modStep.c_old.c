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
	else if (distance.z <= -1)
	{
		strcpy(outZ, "-StepZ\t");
	}
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

int crement(int pnt){
	if (pnt > 0){
		return -1;
	}
	else if (pnt < 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
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
Point tripleStep(Point distance, long i)
{
	char out[50] = "";
	printf("i:%i\t(%i,%i,%i)",i,distance.x,distance.y,distance.z);
	// if ( i % distance.x == 0 && i % distance.y == 0 && i % distance.z == 0)
	// if ( distance.x % i == 0 && distance.y % i == 0 && distance.z % i == 0)
	if ( modCheck(distance.x,i) && modCheck(distance.y,i) && modCheck(distance.z,i))
	{
		strcat(out, (char *)stepX(distance));
		strcat(out, (char *)stepY(distance));
		strcat(out, (char *)stepZ(distance));
		// distance.x += crement(distance.x);
		// distance.y += crement(distance.y);
		distance.z += crement(distance.z);
		free;
		printf(" Branch 1:\t");
	}
	// else if (i % distance.x == 0 && i % distance.y == 0 && i % distance.z != 0)
	// else if (distance.x % i == 0 && distance.y % i == 0 && distance.z % i != 0)
	else if (modCheck(distance.x,i) && modCheck(distance.y,i) && !modCheck(distance.z,i))
	{
		strcat(out, (char *)stepX(distance));
		strcat(out, (char *)stepY(distance));
		// distance.x += crement(distance.x);
		// distance.y += crement(distance.y);
		free;
		printf(" Branch 2:\t");
	}
	// else if (i % distance.x == 0 && i % distance.y != 0 && i % distance.z == 0)
	// else if (distance.x % i == 0 && distance.y % i != 0 && distance.z % i == 0)
	else if (modCheck(distance.x,i) && !modCheck(distance.y,i) && modCheck(distance.z,i))
	{
		strcat(out, (char *)stepX(distance));
		strcat(out, (char *)stepZ(distance));
		// distance.x += crement(distance.x);
		distance.z += crement(distance.z);
		free;
		printf(" Branch 3:\t");
	}
	// else if (i % distance.x != 0 && i % distance.y == 0 && i % distance.z == 0)
	// else if (distance.x % i != 0 && distance.y % i == 0 && distance.z % i == 0)
	else if (!modCheck(distance.x,i) && modCheck(distance.y,i) && modCheck(distance.z,i))
	{
		strcat(out, (char *)stepY(distance));
		strcat(out, (char *)stepZ(distance));
		// distance.y += crement(distance.y);
		distance.z += crement(distance.z);
		free;
		printf(" Branch 4:\t");
	}
	// else if (i % distance.x == 0 && i % distance.y != 0 && i % distance.z != 0)
	// else if (distance.x % i == 0 && distance.y % i != 0 && distance.z % i != 0)
	else if (modCheck(distance.x,i) && !modCheck(distance.y,i) && !modCheck(distance.z,i))
	{
		strcat(out, (char *)stepY(distance));
		// distance.x += crement(distance.x);
		free;
		printf(" Branch 5:\t");
	}
	// else if (i % distance.x != 0 && i % distance.y == 0 && i % distance.z != 0)
	// else if (distance.x % i != 0 && distance.y % i == 0 && distance.z % i != 0)
	else if (!modCheck(distance.x,i) && modCheck(distance.y,i) && !modCheck(distance.z,i))
	{
		strcat(out, (char *)stepX(distance));
		// distance.y += crement(distance.y);
		free;
		printf(" Branch 6:\t");
	}
	// else if (i % distance.x != 0 && i % distance.y != 0 && i % distance.z == 0)
	// else if ( distance.x % i != 0 && distance.y % i != 0 && distance.z % i == 0)
	else if ( !modCheck(distance.x,i) && !modCheck(distance.y,i) && modCheck(distance.z,i))
	{
		strcat(out, (char *)stepZ(distance));
		distance.z += crement(distance.z);
		free;
		printf(" Branch 7:\t");
	}
	strcat(out, "\n");
	printf("%s", out);
	return distance;
}

int calculateTimePulses(Point distance)
{
	long out;
	// distance.z = 0;
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
	Point dist = distance;
	for (i = 0; i < timePulse; i++)
	// for (i = timePulse; i > 0; i--)
	{
		// printf("%i:\t",i);
		// if (moveTripleStep(distance))
		// {
		// 	//definedSlopeMove(i, distance);
			dist = tripleStep(dist, i);
			//  tripleStep(dist, i);
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