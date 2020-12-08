
typedef struct Point Point;

struct Point {
	int x;
	int y;
};

Point calculateDistance(Point initial, Point final);
void stepX(int x);
void stepY(int y);
int calculateTimePulses(Point dist);
void moveTo(Point distance, long timePulse);