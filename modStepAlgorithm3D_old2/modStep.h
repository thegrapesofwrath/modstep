
typedef struct Point Point;

struct Point {
	long x;
	long y;
	long z;
};

Point calculateDistance(Point initial, Point final);
char* stepX(Point distance);
char* stepY(Point distance);
char* stepZ(Point distance);
int calculateTimePulses(Point dist);
void moveTo(Point distance, long timePulse);