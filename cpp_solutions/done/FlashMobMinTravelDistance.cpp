// FLASH MOB - min travel dist bw graph points

/*
 Your job is to find the meeting location given all the members’ locations.
Each intersection will be given by a pair of non-negative integers; the first coordinate is the east-west
street and the second coordinate is the north-south street. The location of each flash mob member will
be an intersection. Members can travel only north-south or east-west between intersections.
For example, suppose there are 5 mob members at locations (3, 4),(0, 5),(1, 1),(5, 5), and (5, 5). Then
if Jack summons them all to location (3, 5), the total number of blocks traveled by the mob members
would be 14. Jack could do no better – but sometimes the ‘best’ location may not be unique.


Input
Input for each test case will be a series of integers on one or more lines. The first integer, n (1 ≤ n ≤
1000), indicates the number of mob members. There follow n pairs of integers indicating the location
(intersection) of each member. The location coordinates are both between 0 and 106
, inclusive. More
than one member may be at the same intersection. A line containing 0 will follow the last test case.


Output
Output one line for each test case in the format given below. The ordered pair is the coordinates of
the location in the city where the total distance traveled (in blocks) is minimal. If there is more than
one such location, output the one with the smallest first coordinate. If there is more than one ‘best’
location with the smallest first coordinate, output the one of those with the smallest second coordinate.
The total number of blocks traveled by all the mob members follows the location.


Sample Input
5 3 4 0 5 1 1 5 5 5 5
4 100 2 100 2 100 2 1 20000
0


Sample Output
Case 1: (3,5) 14
Case 2: (100,2) 20097

*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 1000 + 5;

struct Point {
    int x, y;
    Point(int a=0, int b=0):x(a), y(b) {}
};

vector<Point> pts(maxn);
int size = 0;

int steps(const Point & start, const Point & end)
{
    return abs(start.x-end.x) + abs(start.y-end.y);
}

Point findMed(vector<Point> & pts, int idx)
{
    int medx = 0, medy = 0;
    vector<int> bufx(size);
    vector<int> bufy(size);
    for (int i = 0; i < size; i++) {
	bufx[i] = pts[i].x;
	bufy[i] = pts[i].y;
    }
    sort(bufx.begin(), bufx.end());
    sort(bufy.begin(), bufy.end());
    medx = bufx[idx];
    medy = bufy[idx];
    return Point(medx, medy);
}

int solve(vector<Point> & pts, const Point & end)
{
    int ans = 0;
    for (int i = 0; i < size; i++) {
	ans += steps(pts[i], end);
    }
    return ans;
}

int main()
{
    int T;
    int kase = 0;
    cin >> T;
    while (T!=0) {
	size = T;
	for (int i = 0; i < size; i++) {
	    cin >> pts[i].x >> pts[i].y;
	}
	cout << "Case " << ++kase << ": ";
	Point med1 = findMed(pts, size/2);
	Point med2 = findMed(pts, size/2-1);
	int step1 = solve(pts, med1);
	int step2 = solve(pts, med2);
	if (step1 < step2)
	    cout << '(' << med1.x << ',' << med1.y << ") " << step1 << endl;
	else
	    cout << '(' << med2.x << ',' << med2.y << ") " << step2 << endl;
	cin >> T;
    }
    return 0;
}

