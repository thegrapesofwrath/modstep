typedef struct Point Point;

struct Point {
	long x;
	long y;
	long z;
};

Point calculateDistance(Point initial, Point final);
Point newPoint(long x, long y, long z);
char* stepX(Point distance);
char* stepY(Point distance);
char* stepZ(Point distance);
int calculateTimePulses(Point dist);
void moveTo(Point distance, long timePulse);
void tripleStep(Point distance, long i);
