// Star Crossed Lovers Blocked by wall (GRAPH)

/*

The two lovers are standing at distinct points in the plane. They can travel freely except that there is a single wall which cannot be
crossed. The wall is a line segment which is parallel to either the x or y axis. Each lover can move 1
unit in 1 second. How long will it take them to be together if they both choose the best path?


Input
Input for each test case will consist of two lines each containing four integers. The first two integers
will specify the x and y coordinates of the first lover; the next two integers will specify the x and y
coordinates of the second lover. The next four integers will specify the start and end points of the wall.
Furthermore, in all cases both lovers will not be on the (infinite) line containing the wall — that is, the
wall extended in both directions. All coordinates will be positive and less than or equal to 10000 and
neither lover will start on the wall. The input will be terminated by a line containing four zeroes.

Output
For each test case, output the minimum time in seconds for the two lovers to meet. Print the answer
to exactly 3 decimal places, using the output format shown in the example.

Sample Input
5 2 7 2
1 1 1 100
1 2 3 2
2 1 2 100
0 0 0 0

Sample Output
Case 1: 1.000
Case 2: 1.414


*/



#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

double dist(double x1, double y1, double x2, double y2)
{
	double dx = x1-x2;
	double dy = y1-y2;
	return sqrt(dx*dx+dy*dy);
}

bool between(double a, double b, double c)
{
	if (b < c)
		return (b<a && a<c);
	else
		return (c<a && a<b);
}

int main()
{
	double x1, y1, x2, y2, wx1, wy1, wx2, wy2;
	double ans;
	for(int icase=1; ; icase++) {
		cin >> x1 >> y1 >> x2 >>y2;
    if(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)
      break;
		cin >> wx1 >> wy1 >> wx2 >>wy2;
		if (wx1 == wx2) {
			if (x1 == x2 || !between(wx1, x1, x2))
				ans = dist(x1, y1, x2, y2);
			else {
				double yint = y1 + (y2-y1)*(wx1-x1)/(x2-x1);
				if (between(yint, wy1, wy2)) {
					double dist1 = dist(x1,y1,wx1,wy1)+dist(wx1,wy1,x2,y2);
					double dist2 = dist(x1,y1,wx2,wy2)+dist(wx2,wy2,x2,y2);
					ans = (dist1<dist2) ? dist1 : dist2;
				}
				else
					ans = dist(x1, y1, x2, y2);
			}
		}
		else {
			if (y1 == y2 || !between(wy1, y1, y2))
				ans = dist(x1, y1, x2, y2);
			else {
				double xint = x1 + (x2-x1)*(wy1-y1)/(y2-y1);
				if (between(xint, wx1, wx2)) {
					double dist1 = dist(x1,y1,wx1,wy1)+dist(wx1,wy1,x2,y2);
					double dist2 = dist(x1,y1,wx2,wy2)+dist(wx2,wy2,x2,y2);
					ans = (dist1<dist2) ? dist1 : dist2;
				}
				else
					ans = dist(x1, y1, x2, y2);
			}
		}
    printf("Case %d: %.03f\n", icase, ans/2.0);
	}
}
