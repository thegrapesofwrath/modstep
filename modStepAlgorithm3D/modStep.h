typedef struct Point Point;

struct Point {
	long long x;
	long long y;
	long long z;
};

Point calculateDistance(Point initial, Point final);
Point newPoint(long long x, long long y, long long z);
char* stepX(Point distance);
char* stepY(Point distance);
char* stepZ(Point distance);
long long calculateTimePulses(Point dist);
void moveTo(Point distance, long timePulse);
void tripleStep(Point distance, long i);
